//-------------------------------------------------------------------------------------------------
//
//  File :  device_var.h
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
//
//  This is the place for any device driver not related to CPU peripheral.
//
//  There is exception: EEprom, FatFs, LWIP
//
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
// Global variable(s) and constant(s)
//-------------------------------------------------------------------------------------------------

#ifdef __CLASS_WS281x__

    extern class WS281x WS281x_LedStream;

  #ifdef LIB_WS281x_GLOBAL

    const WS281x_Config_t LedStreamConfig =
    {
        MODE_WS2812B,
        &myTIM_NEO_Led,
        &myPWM_NEO_Led,
        24, //34,                                    // There is 34 LED's in the chain

        // DMA
        {
            DMA_MODE_CIRCULAR           |
            DMA_MEMORY_TO_PERIPHERAL    |
            DMA_PERIPHERAL_NO_INCREMENT |
            DMA_MEMORY_INCREMENT        |
            DMA_PERIPHERAL_SIZE_16_BITS |
            DMA_MEMORY_SIZE_16_BITS     |
            DMA_PERIPHERAL_BURST_SINGLE |
            DMA_MEMORY_BURST_SINGLE     |
            DMA_PRIORITY_LEVEL_HIGH     |
            DMA_CHANNEL_6,                                  // Configuration + DMA_Channel
            DMA_HIFCR_CTCIF5 | DMA_HIFCR_CHTIF5,            // Flag
            DMA2_Stream5,                                   // DMA_TypeDef
            DMA2_Stream5_IRQn,                              // IRQn
            4,
        },
    };

    class WS281x WS281x_LedStream(&LedStreamConfig);

  #endif
#endif

#ifdef __CLASS_DAC_X3508__
//extern class DAC_X3508_Driver       DAC43508;
#ifdef LIB_DAC_x3508_GLOBAL
//class DAC_X3508_Driver              DAC43508(&mySPI_ForDAC, IO_SPI1_CS);
#endif
#endif

#ifdef __CLASS_VFD__
extern class VFD_Driver             VFD;
#ifdef LIB_VFD_GLOBAL
const VFD_Config_t                  VFD_Config =
{
    &mySPI_ForVFD,
    &myPWM_VFD_Blank,
    60,                 // Number of bits
    IO_VFD_LOAD,        // IO for LOAD input into Serial shift
};

class VFD_Driver                    VFD(&VFD_Config);

#endif
#endif

#ifdef __CLASS_DIGIT_IV_11__
extern class IV_11_DigitDriver      IV11;
#ifdef LIB_IV_11_GLOBAL
const uint16_t                      IV11_Info[IV11_NUMBER_OF_TUBE] =
{   // Bit offset in serial bit stream;
    0, 9, 20, 29, 40, 49
};

class IV_11_DigitDriver             IV11(&VFD, &IV11_Info[0], IV11_NUMBER_OF_TUBE);

#endif
#endif

//-------------------------------------------------------------------------------------------------
