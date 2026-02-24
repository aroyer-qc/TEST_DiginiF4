//-------------------------------------------------------------------------------------------------
//
//  File : taskMQTT.cpp
//
//-------------------------------------------------------------------------------------------------

#define TASK_MQTT_GLOBAL
#include "taskMQTT.h"

//-------------------------------------------------------------------------------------------------
// Static member(s)
//-------------------------------------------------------------------------------------------------

nOS_Thread     ClassMQTT_Task::m_MQTTHandle;
nOS_Stack      ClassMQTT_Task::m_MQTTStack[TASK_MQTT_STACK_SIZE];

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
// Initialize()
//-------------------------------------------------------------------------------------------------

SystemState_e ClassMQTT_Task::Initialize(void)
{
    nOS_SemCreate(&m_MQTTSem, 0);

    // Create task
    nOS_ThreadCreate(&m_MQTTHandle,
                     m_MQTTStack,
                     TASK_MQTT_STACK_SIZE,
                     TASK_MQTT_PRIO,
                     TaskMQTT_Wrapper,
                     this);

    return SYS_READY;
}

//-------------------------------------------------------------------------------------------------
// ConnectToBroker()
//-------------------------------------------------------------------------------------------------

bool ClassMQTT_Task::ConnectToBroker(const IP_Address_t& ServerIP, uint16_t Port)
{
    if(m_Client.Initialize(*m_pContext) == false)
        return false;

    m_Client.SetMessageCallback(MQTT_TestMessageCallback, nullptr);

    return m_Client.Connect(&ServerIP, Port, "MyTestClient", 30);
}

//-------------------------------------------------------------------------------------------------
// SubscribeToTestTopic()
//-------------------------------------------------------------------------------------------------

bool ClassMQTT_Task::SubscribeToTestTopic(const char* pTopic)
{
    return m_Client.Subscribe(pTopic, MQTT_QOS_0);
}

//-------------------------------------------------------------------------------------------------
// PublishTestMessage()
//-------------------------------------------------------------------------------------------------

bool ClassMQTT_Task::PublishTestMessage(const char* pTopic, const char* pMsg)
{
    return m_Client.Publish(pTopic,
                            (const uint8_t*)pMsg,
                            strlen(pMsg),
                            MQTT_QOS_0);
}

//-------------------------------------------------------------------------------------------------
// Run()
//-------------------------------------------------------------------------------------------------

void ClassMQTT_Task::Run(void)
{
    // Example broker IP (change as needed)
    IP_Address_t BrokerIP = IP_ADDRESS(192,168,1,199);

    // Initial connection
    ConnectToBroker(BrokerIP, 1883);

    // Subscribe to a test topic
    SubscribeToTestTopic("test/topic");

    // Publish a test message
    PublishTestMessage("test/topic", "Hello from MQTT task!");

    // Main loop
    while(1)
    {
        // Process MQTT state machine
        m_Client.Process();

        // Wait or wake
        nOS_SemTake(&m_MQTTSem, 100);
    }
}

//-------------------------------------------------------------------------------------------------
// Wrapper
//-------------------------------------------------------------------------------------------------

extern "C" void TaskMQTT_Wrapper(void* pvParameters)
{
    ClassMQTT_Task* pThis = (ClassMQTT_Task*)pvParameters;
    pThis->Run();
}

//-------------------------------------------------------------------------------------------------