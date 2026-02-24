//-------------------------------------------------------------------------------------------------
//
//  File : taskTCP_Client.cpp
//
//-------------------------------------------------------------------------------------------------

#define TASK_TCP_CLIENT_GLOBAL
#include "./lib_digini.h"
#undef  TASK_TCP_CLIENT_GLOBAL

//-------------------------------------------------------------------------------------------------
// Static member(s)
//-------------------------------------------------------------------------------------------------

nOS_Thread     TCP_Client::m_Handle;
nOS_Stack      TCP_Client::m_Stack[TASK_TCP_CLIENT_STACK_SIZE];

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

SystemState_e TCP_Client::Initialize(void)
{
    nOS_SemCreate(&m_Sem, 0);

    // Create task
    nOS_ThreadCreate(&m_Handle,
                     m_Stack,
                     TASK_TCP_CLIENT_STACK_SIZE,
                     TASK_TCP_CLIENT_PRIO,
                     TaskTCP_CLient_Wrapper,
                     this);

    return SYS_READY;
}

//-------------------------------------------------------------------------------------------------

void TCP_Client::Run(void)
{
    IP_Address_t ServerIP = IP_ADDRESS(192,168,1,50);   // Echo server or test server
    uint16_t     Port     = 1234;

    while(1)
    {
        // 1) Create socket
        m_Socket.Create(TCP_MODE_CLIENT);

        // 2) Connect
        if(m_Socket.Connect(&ServerIP, Port) == false)
        {
            DEBUG_PrintSerialLog(SYS_DEBUG_LEVEL_APPLICATION, "TCPTest: Connect failed\n");
            m_Socket.Close();
            nOS_Sleep(1000);
            continue;
        }

        // 3) Wait until connected
        while(m_Socket.GetState() != TCP_STATE_CONNECTED)
        {
            nOS_Sleep(10);
        }

        DEBUG_PrintSerialLog(SYS_DEBUG_LEVEL_APPLICATION,
                             "TCPTest: Connected!\n");

        // 4) Send test message
        const char* pMsg = "Hello TCP Server!";
        m_Socket.Send((uint8_t*)pMsg, strlen(pMsg));

        // 5) Wait for response
        uint8_t Buffer[128];
        int Len = m_Socket.Receive(Buffer, sizeof(Buffer));

        if(Len > 0)
        {
            DEBUG_PrintSerialLog(SYS_DEBUG_LEVEL_APPLICATION, "TCPTest: RX (%d bytes): %.*s\n", Len, Len, Buffer);
        }

        // 6) Close
        m_Socket.Close();

        // 7) Sleep before next test
        nOS_Sleep(2000);
    }
}
