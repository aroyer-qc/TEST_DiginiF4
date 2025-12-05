//-------------------------------------------------------------------------------------------------
//
//  File : project_def.h
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
//
//  Notes : This file hold all define for the application setting
//          For hardware setting see: 'bsp.h'
//
//-------------------------------------------------------------------------------------------------

#pragma once

//-------------------------------------------------------------------------------------------------
#define SERIAL_NUMBER_SIZE          16

// Static value that is not configurable
extern const char OUR_FIRMWARE_NAME             [12];
extern const char OUR_FIRMWARE_VERSION          [6];
extern const char OUR_FIRMWARE_DIGINI_NAME      [11];
extern const char OUR_FIRMWARE_DIGINI_VERSION   [7];
extern const char OUR_FIRMWARE_BUILD_DATE       [24];

// Configurable value
extern char OEM_VENDOR_NAME     [7];
extern char OEM_MODEL_NAME      [17];
extern char OEM_SERIAL_NUMBER   [SERIAL_NUMBER_SIZE];

#ifdef BSP_GLOBAL
const char OUR_FIRMWARE_NAME            [12] = { "Test DEV F4"       };
const char OUR_FIRMWARE_VERSION         [6]  = { "V1.00"             };
const char OUR_FIRMWARE_DIGINI_NAME     [11] = { "Digini GUI"        };
const char OUR_FIRMWARE_DIGINI_VERSION  [7]  = { DIGINI_VERSION      };
const char OUR_FIRMWARE_BUILD_DATE      [24] = {__DATE__ " " __TIME__};

 #ifdef DEBUG
char OEM_VENDOR_NAME                    []  = { "Digini"            };

#ifdef STM32F401xE
char OEM_MODEL_NAME                     [] = { "STM32F401C-DISC"   };
#endif
#ifdef STM32F407xx
char OEM_MODEL_NAME                     [] = { "STM32F407G-DISC"   };
#endif
#ifdef STM32F429xx
char OEM_MODEL_NAME                     [] = { "NUCLEO_F429ZI"     };
#endif
char OEM_SERIAL_NUMBER                  [] = { "00000000"          };
 #else
char OEM_VENDOR_NAME                    [] = { "" };
char OEM_MODEL_NAME                     [] = { "" };
char OEM_SERIAL_NUMBER                  [] = { "" };
 #endif
#endif

//-------------------------------------------------------------------------------------------------
