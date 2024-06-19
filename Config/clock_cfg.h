//-------------------------------------------------------------------------------------------------
//
//  File : clock_cfg.h
//
//-------------------------------------------------------------------------------------------------
//
// Copyright(c) 2023 Alain Royer.
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

#define CFG_HSE_VALUE                               8000000
#define CFG_HSI_VALUE                               16000000
#define CFG_LSE_VALUE                               32768
#define CFG_LSI_VALUE                               32000
#define CFG_SYSTICK_RATE                            1000

// User loop value for LIB_Delay_uSec function.. use IO to check for the right value
#define CFG_DELAY_TIMING_LOOP_VALUE_FOR_1_USEC      38 // TODO need to be set and fine tuned

// User clock selection
#define CFG_SYS_CLOCK_MUX                           CFG_RCC_CFGR_SW_PLL         // CFG_RCC_CFGR_SW_HSI, CFG_RCC_CFGR_SW_HSE or CFG_RCC_CFGR_SW_PLL
#define CFG_RCC_PLLCFGR_PLLSRC                      CFG_RCC_PLLCFGR_PLLSRC_HSE  // CFG_RCC_PLLCFGR_PLLSRC_HSI or CFG_RCC_PLLCFGR_PLLSRC_HSE
#define CFG_SYSTEM_CLOCK_NUMBER_OF_RETRY            1000

// For 168 MHz HCLK on HSI
//#define CFG_PLL_SOURCE                            CFG_HSI_VALUE
//#define CFG_PLL_M_DIVIDER                         8
//#define CFG_PLL_N_MULTIPLIER                      168
//#define CFG_PLL_P_DIVIDER                         2
//#define CFG_PLL_Q_DIVIDER                         7

// For 168 MHz HCLK on HSE
#define CFG_PLL_SOURCE                              CFG_HSE_VALUE
#define CFG_PLL_M_DIVIDER                           4
#define CFG_PLL_N_MULTIPLIER                        168
#define CFG_PLL_P_DIVIDER                           2
#define CFG_PLL_Q_DIVIDER                           7

// User clock and divider
#define CFG_AHB_CLK_DIVIDER                         CFG_RCC_CFGR_HPRE_DIV1      // (AHB Prescaler) CFG_RCC_CFGR_HPRE_DIVx -> 1,2,4,8,16,64,128,256,512
#define CFG_APB1_CLK_DIVIDER                        CFG_RCC_CFGR_PPRE1_DIV4     // CFG_RCC_CFGR_PPRE1_DIVx -> 1,2,4,8,16
#define CFG_APB2_CLK_DIVIDER                        CFG_RCC_CFGR_PPRE2_DIV2     // CFG_RCC_CFGR_PPRE2_DIVx -> 1,2,4,8,16

#define CFG_MCO_1                                   (CFG_RCC_CFGR_MCO1_PLL | CFG_RCC_CFGR_MCO1PRE_DIV5)
#define CFG_MCO_2                                   (CFG_RCC_CFGR_MCO2_PLL | CFG_RCC_CFGR_MCO2PRE_DIV5)

//-------------------------------------------------------------------------------------------------
