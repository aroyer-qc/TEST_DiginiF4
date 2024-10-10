//-------------------------------------------------------------------------------------------------
//
//  File : main.cpp
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

#include "./lib_digini.h"
#include "taskIdle.h"
#include "bsp.h"

//-------------------------------------------------------------------------------------------------
//
// Name:           main
// Parameter(s):   void
// Return:         int
//
// Description:    main() what more can be said
//
// Note(s):        Here we create the task that will start all the other
//
//-------------------------------------------------------------------------------------------------
int main()
{
    RCC->AHB1ENR = RCC_AHB1ENR_CRCEN;

    for(uint32_t i = 0; i < 0xFFFFFFFF; i++)
    {
        CRC->CR = 1;
        CRC->DR = i;

        if(CRC->DR == 0xFFFFFFFF)
        {
            __asm("nop");
        }
    }


    uint32_t i = 0x55aa55aa ^ 0x00000000;


    CRC->CR = 1;
    CRC->DR = 0xFFFFFFFF;

    if(CRC->DR == 0)
    {
        __asm("nop");
    }









    ISR_Disable();
    nOS_Init();
    BSP_Initialize();                           // All hardware and system initialization
    nOS_Start();
    BSP_PostOS_Initialize();                    // All initialization that must be done after the OS is started

  #ifdef DEBUG
    DateAndTime_t DateTime;

    DateTime.Date.Day    = 25;
    DateTime.Date.Month  = 6;
    DateTime.Date.Year   = 2024;
    DateTime.Time.Hour   = 15;
    DateTime.Time.Minute = 30;
    DateTime.Time.Second = 1;
    LIB_SetDateAndTime(&DateTime);
  #endif

    TaskIdle();
    return 0;
}

//-------------------------------------------------------------------------------------------------
