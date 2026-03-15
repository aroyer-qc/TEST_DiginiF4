//-------------------------------------------------------------------------------------------------
//
//  File : taskMQTT.cpp
//
//-------------------------------------------------------------------------------------------------

#include "./lib_digini.h"
#define TASK_MQTT_GLOBAL
#include "taskMQTT.h"
#undef  TASK_MQTT_GLOBAL

//-------------------------------------------------------------------------------------------------

#if (DIGINI_USE_ETHERNET == DEF_ENABLED) && (IP_USE_MQTT == DEF_ENABLED)

//-------------------------------------------------------------------------------------------------
// Define(s)
//-------------------------------------------------------------------------------------------------

#define MQTT_TASK_PERIOD_MS                                 200
#define MQTT_ETEHERNET_READY_RETRY_MS                       1000
#define MQTT_CONNECT_TO_BROKER_KEEP_ALIVE_SEC               30
#define MQTT_TASK_KEEP_ALIVE_SEC                            60

//-------------------------------------------------------------------------------------------------
//
//  Name:           TaskMQTT_Wrapper
//
//  Parameter(s):   void* pvParameters
//  Return:         void
//
//  Description:    main() for the ClassMQTT
//
//  Note(s):
//
//-------------------------------------------------------------------------------------------------
extern "C" void TaskMQTT_Wrapper(void* pvParameters)
{
    (static_cast<ClassMQTT*>(pvParameters))->Run();
}

//-------------------------------------------------------------------------------------------------
// Initialize()
//-------------------------------------------------------------------------------------------------

SystemState_e ClassMQTT::Initialize(NetworkContext* pContext)
{
    // Initialize MQTT library with the network context
    m_pContext = pContext;
    m_Client.Initialize(pContext, this);

    nOS_SemCreate(&m_WakeSem, 0, 1);

    // Create task
    /*Error =*/ nOS_ThreadCreate(&m_Handle,
                             TaskMQTT_Wrapper,
                             this,
                             &m_Stack[0],
                             TASK_MQTT_STACK_SIZE,
                             TASK_MQTT_PRIO,
                             "MQTT Test");

    return SYS_READY;
}

//-------------------------------------------------------------------------------------------------
// Run()
//-------------------------------------------------------------------------------------------------
void ClassMQTT::Run(void)
{
    IP_Address_t BrokerIP = MQTT_BROKER_IP;
    bool Connected = false;
    bool FirstTimeConnected = false;
    TickCount_t m_LastPublishTick = 0;


    while(1)
    {
        // Wait for an event or a periodic timeout
        nOS_SemTake(&m_WakeSem, MQTT_TASK_PERIOD_MS);

        // If Ethernet is down, ensure we are disconnected
        if(m_pContext->IsEthernetReady() == false)
        {
            if(Connected == true)
            {
                m_Client.Disconnect();   // Application-level disconnect request
                Connected = false;
                FirstTimeConnected = false;
            }

            nOS_Sleep(MQTT_ETEHERNET_READY_RETRY_MS);
            continue;
        }

        // Ethernet is ready
        Connected = true;

        // Query the current MQTT state (managed by the internal MQTT task)
        MQTT_State_e state = m_Client.GetState();

        // If the client is idle, trigger the initial connection
        if(state == MQTT_STATE_IDLE)
        {
            m_Client.Connect(&BrokerIP,
                             MQTT_BROKER_PORT,
                             "NanoIP-Client",
                             MQTT_TASK_KEEP_ALIVE_SEC);
            continue;
        }

        // First time entering CONNECTED -> perform application logic once
        if(state == MQTT_STATE_CONNECTED)
        {
            if(FirstTimeConnected == false)
            {
                FirstTimeConnected = true;

                // Subscribe to test topic
                m_Client.Subscribe("test/topic", MQTT_QOS_0);
            }

            if((GetTick() - m_LastPublishTick) >= (2 * TICKS_PER_SECOND))
            {
                m_LastPublishTick = GetTick();

                m_Client.Publish("test/topic",
                                 (const uint8_t*)"Hello from MQTT task!",
                                 strlen("Hello from MQTT task!"),
                                 MQTT_QOS_0);
            }

            continue;
        }


        // All other states (WAIT_CONNACK, WAIT_SUBACK, etc.)
        // -> do nothing, let the internal MQTT task handle them
    }
}

//-------------------------------------------------------------------------------------------------
// ConnectToBroker()
//-------------------------------------------------------------------------------------------------

bool ClassMQTT::ConnectToBroker(const IP_Address_t& ServerIP, uint16_t Port)
{
    return m_Client.Connect(&ServerIP, Port, "MQTT_TestClient", MQTT_CONNECT_TO_BROKER_KEEP_ALIVE_SEC);
}

//-------------------------------------------------------------------------------------------------
// SubscribeToTestTopic()
//-------------------------------------------------------------------------------------------------

bool ClassMQTT::SubscribeToTestTopic(const char* pTopic)
{
    return m_Client.Subscribe(pTopic, MQTT_QOS_0);
}

//-------------------------------------------------------------------------------------------------
// PublishTestMessage()
//-------------------------------------------------------------------------------------------------

bool ClassMQTT::PublishTestMessage(const char* pTopic, const char* pMsg)
{
    return m_Client.Publish(pTopic, (const uint8_t*)pMsg, strlen(pMsg), MQTT_QOS_0);
}

//-------------------------------------------------------------------------------------------------

void ClassMQTT::OnEvent(void)
{
    nOS_SemGive(&m_WakeSem);
}

//-------------------------------------------------------------------------------------------------


void ClassMQTT::ReceivedTopic(const char* pTopic, const uint8_t* pPayload, size_t Length)
{
    DEBUG_PrintSerialLog(SYS_DEBUG_LEVEL_ETHERNET,
                         "MQTT RX Topic: %s | Payload (%u bytes): %.*s\n",
                         pTopic,
                         (unsigned)Length,
                         (int)Length,
                         (const char*)pPayload);
}


//-------------------------------------------------------------------------------------------------

#endif // (DIGINI_USE_ETHERNET == DEF_ENABLED) && (IP_USE_MQTT == DEF_ENABLED)
