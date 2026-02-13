//-------------------------------------------------------------------------------------------------
//
//  File : task_network.h
//
//-------------------------------------------------------------------------------------------------
//
// Copyright(c) 2020 Alain Royer.
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

#pragma once

//-------------------------------------------------------------------------------------------------

#if (DIGINI_USE_ETHERNET == DEF_ENABLED)

//-------------------------------------------------------------------------------------------------
// Global Macro
//-------------------------------------------------------------------------------------------------

#ifdef TASK_NETWORK_GLOBAL
    #define TASK_NETWORK_EXTERN
#else
    #define TASK_NETWORK_EXTERN extern
#endif

//-------------------------------------------------------------------------------------------------
// Define(s)
//-------------------------------------------------------------------------------------------------

//#define TASK_WEBSERVER_STACK_SIZE            500
//#define TASK_WEBSERVER_PRIO                  6

#define TASK_NETWORK_STACK_SIZE              512
#define TASK_NETWORK_PRIO                    4

//-------------------------------------------------------------------------------------------------
// Class definition(s)
//-------------------------------------------------------------------------------------------------

class ClassNetwork
{
    public:

                        ClassNetwork                ()                      {};
                       ~ClassNetwork                ()                      {};

        // Task
        void            Network                     (void);
      //void            WebServer                   (void);

        SystemState_e   Initialize                  (void);

        IP_Manager*     GetIP_Manager               (void)                      { return &m_IP_Manager; }   // temporary until multi interface can work (maybe add ID)

      #if (IP_USE_SNTP == DEF_ENABLED)
        void            SetNTP_ResolveIP            (IP_Address_t ResolveIP)     { m_NTP_ResolveIP = ResolveIP; }
      #endif    

    private:

      #if (IP_USE_SNTP == DEF_ENABLED)
        static void     DNS_NTP_Callback            (void* pContext, bool Success, IP_Address_t IP);
      #endif

      //void            WebServer_Serve             (void);
      //void            WebServer_DynamicPage       (void);

      //void            TCP_EchoServer_Initialize   (void);
      //rr_t            TCP_EchoServer_Accept       (void* arg, struct tcp_pcb* newpcb, err_t err);

      #if (IP_USE_SNTP == DEF_ENABLED)
        SNTP_Client                     m_SNTP;                                                 // Simple Network Transport Protocol
        IP_Address_t                    m_NTP_ResolveIP;
        bool                            m_NTP_DNS_Resolved;
        TickCount_t                     m_LastDNS_Request;
      #endif

      #if (IP_USE_SOAP == DEF_ENABLED)
        SOAP_Client                     m_SOAP                                                  // Simple Object Access Protocol
        uint8_t                         m_SOAP_Server_1[IP_MAX_URL_SIZE];                       // Messaging protocol specification for exchanging structured information.
        uint8_t                         m_SOAP_Server_2[IP_MAX_URL_SIZE];
      #endif


      
      //static nOS_Thread               m_WebServerHandle;
      //static nOS_Stack                m_WebServerStack            [TASK_WEBSERVER_STACK_SIZE]     NOS_STACK_LOCATION;
        static nOS_Thread               m_Handle;
        static nOS_Stack                m_Stack                     [TASK_NETWORK_STACK_SIZE];

        class IP_Manager                m_IP_Manager;
};

//-------------------------------------------------------------------------------------------------
// Global variable(s) and constant(s)
//-------------------------------------------------------------------------------------------------

#ifdef TASK_NETWORK_GLOBAL
    class ClassNetwork  TaskNetwork;
    class ClassNetwork* pTaskNetwork = &TaskNetwork;
#else
    extern       class ClassNetwork* pTaskNetwork;
#endif

//-------------------------------------------------------------------------------------------------
// Function prototype(s)
//-------------------------------------------------------------------------------------------------

//extern "C" void TaskWebServer_Wrapper       (void* pvParameters);
//extern "C" void TaskNetwork_Wrapper         (void* pvParameters);

//-------------------------------------------------------------------------------------------------

#endif // (DIGINI_USE_ETHERNET == DEF_ENABLED)
