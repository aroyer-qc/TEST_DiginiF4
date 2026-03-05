//-------------------------------------------------------------------------------------------------
//
//  File : task_network.cpp
//
//-------------------------------------------------------------------------------------------------
//
// Copyright(c) 2026 Alain Royer.
// Email: aroyer.qc@gmail.com
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software
// and associated documentation files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
// INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
// AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
// Include file(s)
//-------------------------------------------------------------------------------------------------

#define TASK_NETWORK_GLOBAL
#include "./lib_digini.h"
#undef  TASK_NETWORK_GLOBAL

#if (DIGINI_USE_ETHERNET == DEF_ENABLED)

//-------------------------------------------------------------------------------------------------
// Private variable(s) and constant(s)
//-------------------------------------------------------------------------------------------------

// Hardware drivers
ETH_Driver           myETH_Driver;
PHY_LAN8742A_Driver  myPHY_Driver;

// Adapter
ETH_STM32_Adapter    mySTM32_LinkDriver(&myETH_Driver, &myPHY_Driver, 0);
ETH_LinkDriver*      pSTM32_LinkDriver = &mySTM32_LinkDriver;

//-------------------------------------------------------------------------------------------------
//
//  Name:           TaskNetwork_Wrapper
//
//  Parameter(s):   void* pvParameters
//  Return:         void
//
//  Description:    main() for the ClassNetwork
//
//  Note(s):
//
//-------------------------------------------------------------------------------------------------
extern "C" void TaskNetwork_Wrapper(void* pvParameters)
{
    (static_cast<ClassNetwork*>(pvParameters))->Network();
}

//extern "C" void TaskWebServer_Wrapper(void* pvParameters)
//{
//    (static_cast<ClassNetwork*>(pvParameters))->WebServer();
//}


#if (IP_USE_SNTP == DEF_ENABLED)
void ClassNetwork::DNS_NTP_Callback(void* pContext, bool Success, IP_Address_t IP)
{
    ClassNetwork* pNetwork = (ClassNetwork*)pContext;

    if(Success == true)
    {
        pNetwork->m_NTP_DNS_Resolved = true;
        pNetwork->m_NTP_ResolveIP    = IP;

        // Clean and correct: start SNTP transaction
        pNetwork->m_SNTP.Start(IP);
    }
    else
    {
        pNetwork->m_NTP_DNS_Resolved = false;
    }
}
#endif

//-------------------------------------------------------------------------------------------------
//
//  Name:           Initialize
//
//  Parameter(s):   void
//  Return:         nOS_Error
//
//  Description:    Initialize
//
//  Note(s):
//
//-------------------------------------------------------------------------------------------------
SystemState_e ClassNetwork::Initialize(void)
{
    nOS_Error Error = NOS_OK;

  #if (IP_USE_SNTP == DEF_ENABLED)
    m_NTP_DNS_Resolved = false;
    m_LastDNS_Request  = 0;
  #endif

    DEBUG_PrintSerialLog(SYS_DEBUG_LEVEL_ETHERNET, "Initializing ClassNetwork\n");

    Error = nOS_ThreadCreate(&m_Handle,
                             TaskNetwork_Wrapper,
                             this,
                             &m_Stack[0],
                             TASK_NETWORK_STACK_SIZE,
                             TASK_NETWORK_PRIO,
                             "Task Network");


    // Webserver task

/*    Error = nOS_ThreadCreate(&m_WebServerHandle,
                             TaskWebServer_Wrapper,
                             this,
                             &m_WebServerStack[0],
                             TASK_WEBSERVER_STACK_SIZE,
                             TASK_WEBSERVER_PRIO,
                             "WEB Server"};
*/

    return (Error != NOS_OK) ? SYS_ERROR : SYS_READY;  // TODO  improve error handling
}


//-------------------------------------------------------------------------------------------------
//
//  Name:           Network
//
//  Parameter(s):   void
//  Return:         void
//
//  Description:    main() loop of Network task for TCPIP, ARP, DHCP
//
//  Note(s):
//
//-------------------------------------------------------------------------------------------------
void ClassNetwork::Network(void)
{
    m_NetworkContext.Initialize(IF_WIRED);

    for(;;)
    {
        if(m_NetworkContext.IsEthernetReady() == true)
        {
          #if (IP_USE_DNS == DEF_ENABLED)
           #if (IP_USE_SNTP == DEF_ENABLED)
            TickCount_t Tick = GetTick();

            if(m_NTP_DNS_Resolved == false)
            {
                if((m_LastDNS_Request == 0) || TickHasTimeOut(m_LastDNS_Request, 5 * 60 * 1000))
                {
                    m_LastDNS_Request = Tick;
                    m_DNS.SendQuery(IP_DEFAULT_NTP_SERVER_1, ClassNetwork::DNS_NTP_Callback, this);
                }
            }
            else
            {
                m_SNTP.Process();

                if(TickHasTimeOut(m_LastDNS_Request, 60 * 60 * 1000))
                {
                    m_LastDNS_Request = Tick;
                    m_NTP_DNS_Resolved = false;
                }
            }
           #endif
          #endif
        }
        nOS_Sleep(10);
        LED_Toggle(IO_LED_GREEN);
    }
}

//-------------------------------------------------------------------------------------------------
//
//  WEB SERVER
//
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
//
//  Name:           WebServer
//
//  Parameter(s):   void
//  Return:         void
//
//  Description:    HTTP Web Server
//
//  Note(s):
//
//-------------------------------------------------------------------------------------------------
#if 0
void ClassNetwork::WebServer(void)
{
   // err_t  err;
  //  err_t  accept_err;

  // Initialize webserver demo
  //http_server_socket_init();



for(;;)
{ nOS_Sleep(100);}

//#if 0
    m_WebServerConn = netconn_new(NETCONN_TCP);                                     // Create a new TCP connection handle

    if(m_WebServerConn != nullptr)
    {
        err = netconn_bind(m_WebServerConn, nullptr, 80);                           // Bind to port 80 (HTTP) with default IP address

        if(err == ERR_OK)
        {
            netconn_listen(m_WebServerConn);                                        // Put the connection into LISTEN state

            for(;;)
            {
                accept_err = netconn_accept(m_WebServerConn, &m_WebServerNewConn);  // Accept any incoming connection

                if(accept_err == ERR_OK)
                {
                    WebServer_Serve();                                              // Serve connection
                    netconn_delete(m_WebServerNewConn);                             // Delete connection
                }
            }
        }
    }
//#endif
}
/**
  * @brief serve tcp connection
  * @param conn: pointer on connection structure
  * @retval None
  */
void ClassNetwork::WebServer_Server(void)
{
    #if 0
    struct netbuf*  inbuf;
    err_t           recv_err;
    char*           buf;
    u16_t           buflen;
    //struct fs_file file;

    /* Read the data from the port, blocking if nothing yet there. We assume the request (the part we care about) is in one netbuf */
    recv_err = netconn_recv(m_WebServerNewConn, &inbuf);

    if(recv_err == ERR_OK)
    {
        if(netconn_err(m_WebServerNewConn) == ERR_OK)
        {
            netbuf_data(inbuf, (void**)&buf, &buflen);

            /* Is this an HTTP GET command? (only check the first 5 chars, since there are other formats for GET, and we're keeping it very simple )*/
            if((buflen >=5) && (strncmp(buf, "GET /", 5) == 0))
            {
                /* Check if request to get ST.gif */
                if(strncmp((char const *)buf,"GET /STM32F7xx_files/ST.gif",27)==0)
                {
                    //fs_open(&file, "/STM32F7xx_files/ST.gif");
                    //netconn_write(m_WebServerNewConn, (const unsigned char*)(file.data), (size_t)file.len, NETCONN_NOCOPY);
                    //fs_close(&file);
                }
                /* Check if request to get stm32.jpeg */
                else if(strncmp((char const *)buf,"GET /STM32F7xx_files/stm32.jpg",30)==0)
                {
                    //fs_open(&file, "/STM32F7xx_files/stm32.jpg");
                    //netconn_write(m_WebServerNewConn, (const unsigned char*)(file.data), (size_t)file.len, NETCONN_NOCOPY);
                    //fs_close(&file);
                }
                else if (strncmp((char const *)buf,"GET /STM32F7xx_files/logo.jpg", 29) == 0)
                {
                    /* Check if request to get ST logo.jpg */
                    //fs_open(&file, "/STM32F7xx_files/logo.jpg");
                    //netconn_write(m_WebServerNewConn, (const unsigned char*)(file.data), (size_t)file.len, NETCONN_NOCOPY);
                    //fs_close(&file);
                }
                else if(strncmp(buf, "GET /STM32F7xxTASKS.html", 24) == 0)
                {
                    /* Load dynamic page */
                    WebServer_DynamicPage();
                }
                else if((strncmp(buf, "GET /STM32F7xx.html", 19) == 0)||(strncmp(buf, "GET / ", 6) == 0))
                {
                    /* Load STM32F7xx page */
                    //fs_open(&file, "/STM32F7xx.html");
                    //netconn_write(m_WebServerNewConn, (const unsigned char*)(file.data), (size_t)file.len, NETCONN_NOCOPY);
                    //fs_close(&file);
                }
                else
                {
                    /* Load Error page */
                    //fs_open(&file, "/404.html");
                    //netconn_write(m_WebServerNewConn, (const unsigned char*)(file.data), (size_t)file.len, NETCONN_NOCOPY);
                    //fs_close(&file);
                }
            }
        }
    }

    /* Close the connection (server closes in HTTP) */
    netconn_close(m_WebServerNewConn);

    /* Delete the buffer (netconn_recv gives us ownership, so we have to make sure to deallocate the buffer) */
    netbuf_delete(inbuf);
#endif
}

/**
  * @brief  Create and send a dynamic Web Page. This page contains the list of
  *         running tasks and the number of page hits.
  * @param  conn pointer on connection structure
  * @retval None
  */
#if 0
void ClassNetwork::WebServer_DynamicPage(void)
{
    char* pPageBody;
    char* pPageHits;

// TODO Add protection
    pPageBody = (char*)pMemoryPool->AllocAndClear(512, MEM_DBG_TSKNET1);
    pPageHits = (char*)pMemoryPool->AllocAndClear(10, MEM_DBG_TSKNET2);

    // Update the hit count
    nPageHits++;
    sprintf(pPageHits, "%d", (int)nPageHits);
    strcat(pPageBody, pPageHits);
    strcat((char *)pPageBody, "<pre><br>Name          State  Priority  Stack   Num" );
    strcat((char *)pPageBody, "<br>---------------------------------------------<br>");

    // The list of tasks and their status
    //osThreadList((unsigned char *)(pPageBody + strlen(pPageBody)));
    strcat((char *)pPageBody, "<br><br>---------------------------------------------");
    strcat((char *)pPageBody, "<br>B : Blocked, R : Ready, D : Deleted, S : Suspended<br>");

    // Send the dynamically generated page
    netconn_write(m_WebServerNewConn, PAGE_START, strlen((char*)PAGE_START), NETCONN_COPY);
    netconn_write(m_WebServerNewConn, pPageBody, strlen(pPageBody), NETCONN_COPY);

    pMemoryPool->Free((void**)&pPageBody);
    pMemoryPool->Free((void**)&pPageHits);
}
    #endif
#endif // if 0
//-------------------------------------------------------------------------------------------------

#endif
