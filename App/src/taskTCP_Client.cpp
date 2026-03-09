//-------------------------------------------------------------------------------------------------
//
//  File : taskTCP_Client.cpp
//
//-------------------------------------------------------------------------------------------------

#define TASK_TCP_CLIENT_GLOBAL
#include "./lib_digini.h"
#undef  TASK_TCP_CLIENT_GLOBAL
#include "taskTCP_Client.h"

#if (DIGINI_USE_ETHERNET == DEF_ENABLED) && (IP_USE_TCP_CLIENT == DEF_ENABLED)

//-------------------------------------------------------------------------------------------------
// Static member(s)
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
//
//  Name:           TaskTCP_CLient_Wrapper
//
//  Parameter(s):   void* pvParameters
//  Return:         void
//
//  Description:    main() for the TCP_Client
//
//  Note(s):
//
//-------------------------------------------------------------------------------------------------
extern "C" void TaskTCP_CLient_Wrapper(void* pvParameters)
{
    (static_cast<TCP_Client*>(pvParameters))->Run();
}

//-------------------------------------------------------------------------------------------------
// Initialize()
//-------------------------------------------------------------------------------------------------

SystemState_e TCP_Client::Initialize(NetworkContext* pContext)
{
    m_pContext = pContext;
    m_pSocket  = nullptr;

    nOS_SemCreate(&m_Sem, 0, 1);

    // Create task
    /*Error =*/ nOS_ThreadCreate(&m_Handle,
                             TaskTCP_CLient_Wrapper,
                             this,
                             &m_Stack[0],
                             TASK_TCP_CLIENT_STACK_SIZE,
                             TASK_TCP_CLIENT_PRIO,
                             "TCP CLient Test");

    return SYS_READY;
}

//-------------------------------------------------------------------------------------------------

void TCP_Client::Run(void)
{
    IP_Address_t ServerIP = IP_ADDRESS(192,168,1,50);
    uint16_t     Port     = 1234;

    while(1)
    {
        // 1) Create TCP socket via TCP_Manager (same pattern as MQTT_Client)
        TCP_Manager* pTCP = m_pContext->GetTCP();
        m_pSocket = pTCP->Connect(ServerIP, Port);

        if(m_pSocket == nullptr)
        {
            DEBUG_PrintSerialLog(SYS_DEBUG_LEVEL_APPLICATION, "TCPTest: Connect() returned NULL\n");
            nOS_Sleep(1000);
            continue;
        }

        DEBUG_PrintSerialLog(SYS_DEBUG_LEVEL_APPLICATION, "TCPTest: Connecting...\n");

        // 2) Wait until connected
        while(m_pSocket->GetState() != TCP_STATE_ESTABLISHED)
        {
            nOS_Sleep(10);
        }

        DEBUG_PrintSerialLog(SYS_DEBUG_LEVEL_APPLICATION, "TCPTest: Connected!\n");

        // 3) Send test message
        const char* pMsg = "Hello TCP Server!";
        m_pSocket->Send((const uint8_t*)pMsg, strlen(pMsg));

        // 4) Receive response
        uint8_t Buffer[128];
        int Len = m_pSocket->Receive(Buffer, sizeof(Buffer));

        if(Len > 0)
        {
            DEBUG_PrintSerialLog(SYS_DEBUG_LEVEL_APPLICATION, "TCPTest: RX (%d bytes): %.*s\n", Len, Len, Buffer);
        }
        else
        {
            DEBUG_PrintSerialLog(SYS_DEBUG_LEVEL_APPLICATION, "TCPTest: No data received\n");
        }

        // 5) Close socket
        m_pSocket->Close();
        m_pSocket = nullptr;

        // 6) Wait before next test
        nOS_Sleep(2000);
    }
}

//-------------------------------------------------------------------------------------------------

#endif // (DIGINI_USE_ETHERNET == DEF_ENABLED) && (IP_USE_TCP_CLIENT == DEF_ENABLED)
