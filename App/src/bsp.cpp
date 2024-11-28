//-------------------------------------------------------------------------------------------------
//
//  File : bsp.cpp
//
//-------------------------------------------------------------------------------------------------
//
// Copyright(c) 2024 Alain Royer.
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

//------ Note(s) ----------------------------------------------------------------------------------
//
//  BSP - Board support package for STM32F4-DISCO
//
//  this board has 128K RAM in CPU
//                 64K CCRAM in CPU
//
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
// Include file(s)
//-------------------------------------------------------------------------------------------------

#define BSP_GLOBAL
#include "bsp.h"
#undef  BSP_GLOBAL

#if (DIGINI_USE_ETHERNET == DEF_ENABLED)
#include "Task_network.h"
#endif // (DIGINI_USE_ETHERNET == DEF_ENABLED)

//-------------------------------------------------------------------------------------------------

// because for now we don't have eeprom for this test board
const TempUnit_e T_Unit = TEMP_CELSIUS;
const SystemDebugLevel_e DebugLvl = SystemDebugLevel_e(0);//SystemDebugLevel_e(SYS_DEBUG_LEVEL_ETHERNET | SYS_DEBUG_LEVEL_MEMORY_POOL);
const Language_e Lang = LANG_ENGLISH;

//#if (BSP_TEST_HARDWARE == DEF_ENABLED)
void BSP_HardwareTest (void);
//#endif

//-------------------------------------------------------------------------------------------------
// Local Function(s)
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
//
//  Name:           BSP_Initialize
//  Parameter(s):   void
//  Return:         void
//
//  Description:    This function should be called by your application before anything else
//
//  Note(s):
//
//-------------------------------------------------------------------------------------------------
void BSP_Initialize(void)
{
    SysTick_Config(SYSTEM_CORE_CLOCK / CFG_SYSTICK_RATE);

    ISR_Initialize();

    IO_PinInit(IO_LED_RED);
    IO_PinInit(IO_LED_GREEN);

    IO_SetPinLow(IO_LED_RED);
    IO_SetPinLow(IO_LED_GREEN);

    // IO_PinInit(IO_LED_BLUE);  transfert to ETH for now
    IO_PinInit(IO_MCO_2);        // Output the MCO for clock validation
    DIGINI_Initialize();
}

//-------------------------------------------------------------------------------------------------
//
//  Name:           BSP_PostOS_Initialize
//  Parameter(s):   void
//  Return:         SystemState_e       SystemState
//
//  Description:    This function should be called by your application After OS has being started
//
//  Note(s):        Example: class or driver using Semaphore
//
//-------------------------------------------------------------------------------------------------
SystemState_e BSP_PostOS_Initialize(void)
{
    SystemState_e State = SYS_READY;

    // DAC
   // mySPI_ForDAC.Initialize();
   // DAC43508.Initialize();

    // VFD
    //mySPI_ForVFD.Initialize();              // SPI Driver for the data
   // myTIM_VFD.Initialize();                 // Timer Driver on top of PWM for blank line
   // myPWM_VFD_Blank.Initialize();           // PWM Driver to control blank line (dimming feature)
   // VFD.Initialize();                       // Then initialize the VFD driver
    State = DIGINI_PostInitialize();

    // WS2812 LED stream
    WS281x_LedStream.Initialize();


    WS281x_LedStream.Start();

uint8_t R,G,B;

    while(1)
    {
        WS281x_LedStream.SetLed(0, {R++,G--,B+=3});
        WS281x_LedStream.SetLed(1, {uint8_t(R++ + 10), G--,uint8_t(B-= 10)});
        WS281x_LedStream.SetLed(2, {uint8_t(R++ + 20), G--,uint8_t(B-= 20)});
        WS281x_LedStream.SetLed(3, {uint8_t(R++ + 30), G--,uint8_t(B-= 30)});
        WS281x_LedStream.SetLed(4, {uint8_t(R++ + 40), G--,uint8_t(B-= 40)});
        WS281x_LedStream.SetLed(5, {uint8_t(R++ + 50), G--,uint8_t(B-= 50)});
        WS281x_LedStream.SetLed(6, {uint8_t(R++ + 60), G--,uint8_t(B-= 60)});
        WS281x_LedStream.SetLed(7, {uint8_t(R++ + 70), G--,uint8_t(B-= 70)});
        WS281x_LedStream.SetLed(8, {uint8_t(R++ + 80), G--,uint8_t(B-= 80)});
        WS281x_LedStream.SetLed(9, {uint8_t(R++ + 90), G--,uint8_t(B-= 90)});
        WS281x_LedStream.SetLed(10,{uint8_t(R++ + 100),G--,uint8_t(B-= 100)});
        WS281x_LedStream.SetLed(11,{uint8_t(R++ + 110),G--,uint8_t(B-= 110)});
        WS281x_LedStream.SetLed(12,{uint8_t(R++ + 120),G--,uint8_t(B-= 120)});
        WS281x_LedStream.SetLed(13,{uint8_t(R++ + 130),G--,uint8_t(B-= 130)});
        WS281x_LedStream.SetLed(14,{uint8_t(R++ + 140),G--,uint8_t(B-= 140)});
        WS281x_LedStream.SetLed(15,{uint8_t(R++ + 150),G--,uint8_t(B-= 150)});
        WS281x_LedStream.SetLed(16,{uint8_t(R++ + 160),G--,uint8_t(B-= 160)});
        WS281x_LedStream.SetLed(17,{uint8_t(R++ + 170),G--,uint8_t(B-= 170)});
        WS281x_LedStream.SetLed(18,{uint8_t(R++ + 180),G--,uint8_t(B-= 180)});
        WS281x_LedStream.SetLed(19,{uint8_t(R++ + 190),G--,uint8_t(B-= 190)});
        WS281x_LedStream.SetLed(20,{uint8_t(R++ + 200),G--,uint8_t(B-= 200)});
        WS281x_LedStream.SetLed(21,{uint8_t(R++ + 210),G--,uint8_t(B-= 210)});
        WS281x_LedStream.SetLed(22,{uint8_t(R++ + 220),G--,uint8_t(B-= 220)});
        WS281x_LedStream.SetLed(23,{uint8_t(R++ + 230),G--,uint8_t(B-= 230)});
        nOS_Sleep(16);
}


    return State;
}

//-------------------------------------------------------------------------------------------------

