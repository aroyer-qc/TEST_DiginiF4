//-------------------------------------------------------------------------------------------------
//
//  File : driver_cfg.h
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
// Include file(s)
//-------------------------------------------------------------------------------------------------

#include "stm32f4xx.h"

//-------------------------------------------------------------------------------------------------
// Low level Peripheral
//-------------------------------------------------------------------------------------------------

#define USE_ADC_DRIVER              DEF_DISABLED
#define USE_CAN_DRIVER              DEF_DISABLED
#define USE_CRC_DRIVER              DEF_ENABLED
#define USE_DAC_DRIVER              DEF_DISABLED
#define USE_IO_BUS_DRIVER           DEF_DISABLED
#define USE_I2C_DRIVER              DEF_DISABLED
#define USE_ETH_DRIVER              DEF_ENABLED
#define USE_I2S_DRIVER              DEF_DISABLED
#define USE_PWM_DRIVER              DEF_ENABLED
#define USE_QSPI_DRIVER             DEF_DISABLED
#define USE_RTC_DRIVER              DEF_DISABLED
#define USE_SAI_DRIVER              DEF_DISABLED                    // Serial audio out
#define USE_SDIO_DRIVER             DEF_DISABLED
#define USE_SPI_DRIVER              DEF_DISABLED
#define USE_TIM_DRIVER              DEF_ENABLED
#define USE_UART_DRIVER             DEF_ENABLED
#define USE_USB_DRIVER              DEF_DISABLED
    #define USE_USB_OTG_FS_CODE     DEF_DISABLED
    #define USE_USB_OTG_HS_CODE     DEF_DISABLED

