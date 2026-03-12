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

#define MQTT_TASK_PERIOD_MS                 100
#define MQTT_TASK_DISCONNECTED_PERIOD_MS    500

//-------------------------------------------------------------------------------------------------
// Local MQTT message callback (for testing)
//-------------------------------------------------------------------------------------------------

static void MQTT_TestMessageCallback(void* pContext, const char* pTopic, const uint8_t* pPayload, size_t Length)
{
    (void)pContext;

    DEBUG_PrintSerialLog(SYS_DEBUG_LEVEL_APPLICATION,
                         "MQTT RX Topic: %s | Payload (%u bytes): %.*s\n",
                         pTopic,
                         (unsigned)Length,
                         (int)Length,
                         (const char*)pPayload);
}

//-------------------------------------------------------------------------------------------------
//
//  Name:           TaskMQTT_Wrapper
//
//  Parameter(s):   void* pvParameters
//  Return:         void
//
//  Description:    main() for the ClassNetwork
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
    m_Client.Initialize(pContext);

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

    while(1)
    {
        if(m_pContext->IsEthernetReady() == false)
        {
            if(Connected == true)
            {
                m_Client.Disconnect();
                Connected = false;
            }

            nOS_SemTake(&m_WakeSem, MQTT_TASK_PERIOD_MS);
            continue;
        }

        MQTT_State_e state = m_Client.GetState();

        // ----------------------------------------------------
        // 1. IDLE → lancer la connexion MQTT (TCP + CONNECT)
        // ----------------------------------------------------
        if(state == MQTT_STATE_IDLE)
        {
            m_Client.Connect(&BrokerIP, MQTT_BROKER_PORT, "NanoIP-Client",  60);   // KeepAlive

            nOS_SemTake(&m_WakeSem, MQTT_TASK_PERIOD_MS);
            continue;
        }

        // ----------------------------------------------------
        // 2. CONNECTING / WAIT_CONNACK → laisser Process() bosser
        // ----------------------------------------------------
        if((state == MQTT_STATE_CONNECTING) ||
           (state == MQTT_STATE_WAIT_CONNACK))
        {
            m_Client.Process();
            nOS_SemTake(&m_WakeSem, MQTT_TASK_PERIOD_MS);
            continue;
        }

        // ----------------------------------------------------
        // 3. CONNECTED pour la première fois → subscribe + publish
        // ----------------------------------------------------
        if((Connected == false) && (state == MQTT_STATE_CONNECTED))
        {
            m_Client.Subscribe("test/topic", MQTT_QOS_0);
            m_Client.Publish("test/topic",
                             reinterpret_cast<const uint8_t*>("Hello from MQTT task!"),
                             strlen("Hello from MQTT task!"),
                             MQTT_QOS_0);

            Connected = true;

            m_Client.Process();
            nOS_SemTake(&m_WakeSem, MQTT_TASK_PERIOD_MS);
            continue;
        }

        // ----------------------------------------------------
        // 4. CONNECTED en régime normal
        // ----------------------------------------------------
        if(state == MQTT_STATE_CONNECTED)
        {
            m_Client.Process();
            nOS_SemTake(&m_WakeSem, MQTT_TASK_PERIOD_MS);
            continue;
        }

        // ----------------------------------------------------
        // 5. RECONNECT / ERROR → repartir propre
        // ----------------------------------------------------
        if((state == MQTT_STATE_RECONNECTING) ||
           (state == MQTT_STATE_ERROR))
        {
            m_Client.Disconnect();
            Connected = false;

            nOS_SemTake(&m_WakeSem, MQTT_TASK_PERIOD_MS);
            continue;
        }

        // ----------------------------------------------------
        // 6. Par défaut : laisser Process() avancer la machine
        // ----------------------------------------------------
        m_Client.Process();
        nOS_SemTake(&m_WakeSem, MQTT_TASK_PERIOD_MS);
    }
}

//-------------------------------------------------------------------------------------------------
// ConnectToBroker()
//-------------------------------------------------------------------------------------------------

bool ClassMQTT::ConnectToBroker(const IP_Address_t& ServerIP, uint16_t Port)
{
    if(m_Client.Connect(&ServerIP, Port, "MQTT_TestClient", 30) == false)
        return false;

    TCP_Socket* pSocket = m_Client.GetSocket();

    if(pSocket != nullptr)
    {
        pSocket->SetEventHandler(this);
    }

    return true;
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

void ClassMQTT::OnSocketEvent(TCP_Socket* pSocket, SocketEvent_e Event)
{
    GiveToRunMQTT();

/*
    switch(Event)
    {
        case SOCKET_EVENT_ERROR:
        {
        }
        break;

        case SOCKET_EVENT_CLOSED:
        {
        }
        break;

        case SOCKET_EVENT_RX_READY:
        {
        }
        break;

        case SOCKET_EVENT_CONNECTED:
        {
        }
        break;

        default: break;
    }
*/
}


//-------------------------------------------------------------------------------------------------

#endif // (DIGINI_USE_ETHERNET == DEF_ENABLED) && (IP_USE_MQTT == DEF_ENABLED)
