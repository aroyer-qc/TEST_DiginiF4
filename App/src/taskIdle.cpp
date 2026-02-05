//-------------------------------------------------------------------------------------------------
//
//  File : TaskIdle.cpp
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

//-------------------------------------------------------------------------------------------------
// Include file(s)
//-------------------------------------------------------------------------------------------------

#define TASK_IDLE_GLOBAL
#include "TaskIdle.h"
#undef  TASK_IDLE_GLOBAL
#include "bsp.h"
#include "./lib_digini.h"
//#include "task_network.h"

//-------------------------------------------------------------------------------------------------
// Define(s)
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
// Variable(s) and constant(s)
//-------------------------------------------------------------------------------------------------

static const uint16_t sine_wave[256] =
{
  2048, 2098, 2148, 2198, 2248, 2298, 2348, 2398,
  2447, 2496, 2545, 2594, 2642, 2690, 2737, 2784,
  2831, 2877, 2923, 2968, 3013, 3057, 3100, 3143,
  3185, 3226, 3267, 3307, 3346, 3385, 3423, 3459,
  3495, 3530, 3565, 3598, 3630, 3662, 3692, 3722,
  3750, 3777, 3804, 3829, 3853, 3876, 3898, 3919,
  3939, 3958, 3975, 3992, 4007, 4021, 4034, 4045,
  4056, 4065, 4073, 4080, 4085, 4089, 4093, 4094,
  4095, 4094, 4093, 4089, 4085, 4080, 4073, 4065,
  4056, 4045, 4034, 4021, 4007, 3992, 3975, 3958,
  3939, 3919, 3898, 3876, 3853, 3829, 3804, 3777,
  3750, 3722, 3692, 3662, 3630, 3598, 3565, 3530,
  3495, 3459, 3423, 3385, 3346, 3307, 3267, 3226,
  3185, 3143, 3100, 3057, 3013, 2968, 2923, 2877,
  2831, 2784, 2737, 2690, 2642, 2594, 2545, 2496,
  2447, 2398, 2348, 2298, 2248, 2198, 2148, 2098,
  2048, 1997, 1947, 1897, 1847, 1797, 1747, 1697,
  1648, 1599, 1550, 1501, 1453, 1405, 1358, 1311,
  1264, 1218, 1172, 1127, 1082, 1038,  995,  952,
   910,  869,  828,  788,  749,  710,  672,  636,
   600,  565,  530,  497,  465,  433,  403,  373,
   345,  318,  291,  266,  242,  219,  197,  176,
   156,  137,  120,  103,   88,   74,   61,   50,
    39,   30,   22,   15,   10,    6,    2,    1,
     0,    1,    2,    6,   10,   15,   22,   30,
    39,   50,   61,   74,   88,  103,  120,  137,
   156,  176,  197,  219,  242,  266,  291,  318,
   345,  373,  403,  433,  465,  497,  530,  565,
   600,  636,  672,  710,  749,  788,  828,  869,
   910,  952,  995, 1038, 1082, 1127, 1172, 1218,
  1264, 1311, 1358, 1405, 1453, 1501, 1550, 1599,
  1648, 1697, 1747, 1797, 1847, 1897, 1947, 1997
};

//-------------------------------------------------------------------------------------------------
// Function(s)
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
//
//  Name:           TaskIdle
//
//  Parameter(s):   none
//  Return:         void
//
//  Description:    main() for the idle task
//
//  Note(s):
//
//-------------------------------------------------------------------------------------------------
uint32_t Counter = 0;
static bool DNS_TestStarted = false;

void TaskIdle(void)
{
  //  uint16_t Value;
 //   uint8_t Test[3];

  //  Test[0] = 0xA5;
   // Test[1] = 0x69;

    CRC_Driver Poutine;
    CRC_Driver Poutine2;

    Poutine.Initialize(CRC32_HW_MPEG_2);
    Poutine2.Initialize(CRC32_HW_MPEG_2);



    // --------------------------------------------------------------------------------------------
    // Low level main control loop
    while(1)
    {
      #if (DIGINI_USE_COMM_MODULE == DEF_ENABLED) && (DIGINI_USE_CONSOLE == DEF_ENABLED) && (DIGINI_USE_COMM_AS_A_TASK == DEF_DISABLED)
        pTaskCOMM->Process();       // to test pTaskComm as a process.. at this time it crash!!
      #endif

        // DAC part test ( output a sine wave onto channel 1 of the DAC)
     //   Value = sine_wave[Count];

        if((Counter & 0x01) == 0x00)
        {
            // IO_SetPinHigh(IO_LED_BLUE);
        }
        else
        {
             // if(Count == 128) IO_SetPinLow(IO_LED_BLUE);
        }

      //  DAC43508.WriteDAC(1, Value);


        Counter++;
        if (Counter >= 5)
        {
            Counter = 0;

            if(DNS_TestStarted == false)
            {
                DNS_TestStarted = true;

                bool ok = pTaskNetwork->GetIP_Manager()->RequestDNS(IP_DEFAULT_NTP_SERVER_1,
                    [](void* ctx, bool Success, IP_Address_t IP)
                    {
                        if(Success)
                        {
                            char Buffer[32];
                            IP_Manager::IP_ToAscii(Buffer, IP);
                            DEBUG_PrintSerialLog(SYS_DEBUG_LEVEL_ETHERNET, "DNS TEST: Success -> %s\n", Buffer);
                        }
                        else
                        {
                            DEBUG_PrintSerialLog(SYS_DEBUG_LEVEL_ETHERNET, "DNS TEST: Failed\n");
                        }
                    });

                if(!ok)
                {
                    DEBUG_PrintSerialLog(SYS_DEBUG_LEVEL_ETHERNET, "DNS TEST: Request rejected (busy)\n");
                }
            }

        }

      #ifdef STM32F429xx
        // VFD part test
        //VFD.Send();
      #endif

        //VFD.Set(13, &Test[0], 10);
        //VFD.Set(14, &Test[0], 10);
        //VFD.Set(15, &Test[0], 10);
        //VFD.Set(16, &Test[0], 10);
        //VFD.Set(17, &Test[0], 10);
        //VFD.Set(18, &Test[0], 10);
        //VFD.Set(13, &Test[0], 10);

        //IV11.Write('1', 0, false);
        //IV11.Write('2', 1, false);
        //IV11.Write('3', 2, true);
        //IV11.Write('4', 3, false);
        //IV11.Write('5', 4, false);
        //IV11.Write('6', 5, true);
        //IV11.Write('7', 6, false);     // should failed..


        //IV11.Send();
      #if (DIGINI_USE_ETHERNET == DEF_ENABLED)
        //pTaskNetwork->Process();
      #endif
        LIB_Delay_mSec(1000);
        //nOS_Sleep(1);
    }
}
