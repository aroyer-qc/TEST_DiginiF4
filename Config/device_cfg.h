//-------------------------------------------------------------------------------------------------
//
//  File :  device_cfg.h
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
// Define(s)
//-------------------------------------------------------------------------------------------------

#define   IV11_NUMBER_OF_TUBE       6

// Config for lib_class_STM32F1_WS281x.h
#define WS281x_USE_PRECALCULATED_PWM_BUFFER         DEF_DISABLED
#define WS281x_USE_48_BITS_DMA_TRANSFER             DEF_ENABLED
#define WS281x_USE_WS2812B                          DEF_ENABLED

//-------------------------------------------------------------------------------------------------
// Include file(s)
//-------------------------------------------------------------------------------------------------

// Put here included for all high level driver. Driver for device not in the CPU
#include "./Digini/Peripheral/inc/device/lib_class_pwm_WS281x.h"
//#include "./Peripheral/inc/device/lib_class_spi_DACX3508.h"
#include "./Peripheral/inc/device/lib_class_spi_VFD.h"
//#include "./Peripheral/inc/device/lib_class_spi_IV_11.h"

//-------------------------------------------------------------------------------------------------
