//-------------------------------------------------------------------------------------------------
//
//  File :  spi_var.h
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
//
//  Notes : SPI variables for STM32F4xx
//
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
// Define(s)
//-------------------------------------------------------------------------------------------------

#define SPI_STANDARD_CONFIGURATION_RX ( DMA_MODE_NORMAL             | \
                                        DMA_PERIPHERAL_TO_MEMORY    | \
                                        DMA_PERIPHERAL_NO_INCREMENT | \
                                        DMA_MEMORY_INCREMENT        | \
                                        DMA_PERIPHERAL_SIZE_8_BITS  | \
                                        DMA_MEMORY_SIZE_8_BITS      | \
                                        DMA_PERIPHERAL_BURST_SINGLE | \
                                        DMA_MEMORY_BURST_SINGLE     | \
                                        DMA_PRIORITY_LEVEL_MEDIUM)

#define SPI_STANDARD_CONFIGURATION_TX ( DMA_MODE_NORMAL             | \
                                        DMA_MEMORY_TO_PERIPHERAL    | \
                                        DMA_PERIPHERAL_NO_INCREMENT | \
                                        DMA_MEMORY_INCREMENT        | \
                                        DMA_PERIPHERAL_SIZE_8_BITS  | \
                                        DMA_MEMORY_SIZE_8_BITS      | \
                                        DMA_PERIPHERAL_BURST_SINGLE | \
                                        DMA_MEMORY_BURST_SINGLE     | \
                                        DMA_PRIORITY_LEVEL_MEDIUM)

//-------------------------------------------------------------------------------------------------
// Constant(s)
//-------------------------------------------------------------------------------------------------

#ifdef SPI_DRIVER_GLOBAL

SPI_Info_t SPI_Info[NB_OF_SPI_DRIVER] =
{
  #if (SPI_DRIVER_SUPPORT_SPI1_CFG == DEF_ENABLED)
	{
        SPI1,                       // SPIx
        SPI_MODE_MASTER       |     // Configuration
        SPI_DATA_WIDTH_8_BIT  |
        SPI_POLARITY_LOW      |
        SPI_PHASE_1_EDGE      |
        SPI_NSS_SOFT          |     // The CS pin will be handle in software
        SPI_MSB_FIRST         |
        SPI_FULL_DUPLEX,            // SPI_FULL_DUPLEX or SPI_HALF_DUPLEX
		24000000,                   // The DAC chip is 12 inche away from CPU on 790A, so reduced comm speed
        SPI1_IRQn,                  // IRQn_Channel

        // DMA_RX
        {
            SPI_STANDARD_CONFIGURATION_RX | DMA_CHANNEL_3, // Configuration + DMA_Channel RX
            DMA_LIFCR_CTCIF0,                              // RX_IT_Flag
            DMA2_Stream0,                                  // RX_DMA_TypeDef  it won't be used in this case
            DMA2_Stream0_IRQn,                             // RX_IRQn

            // Other choice
         // SPI_STANDARD_CONFIGURATION_RX | DMA_CHANNEL_3, // Configuration + DMA_Channel RX
         // DMA_LIFCR_CTCIF2,                              // RX_IT_Flag
         // DMA1_Stream2,                                  // RX_DMA_TypeDef  it won't be used in this case
         // DMA1_Stream2_IRQn,                             // RX_IRQn
        },

        // DMA TX
        {
            SPI_STANDARD_CONFIGURATION_TX | DMA_CHANNEL_3, // Configuration + DMA_Channel TX
            DMA_LIFCR_CTCIF3,                              // TX_IT_Flag
            DMA2_Stream3,                                  // TX_DMA_TypeDef
            DMA2_Stream3_IRQn,                             // TX_IRQn

            // Other choice
         // SPI_STANDARD_CONFIGURATION_TX | DMA_CHANNEL_3, // Configuration + DMA_Channel TX
         // DMA_HIFCR_CTCIF5,                              // TX_IT_Flag
         // DMA2_Stream5,                                  // TX_DMA_TypeDef
         // DMA2_Stream5_IRQn,                             // TX_IRQn
        },
	},
  #endif

  #if (SPI_DRIVER_SUPPORT_SPI2_CFG == DEF_ENABLED)
	{
		SPI2,                       // SPIx
        SPI_MODE_MASTER       |     // Configuration
        SPI_DATA_WIDTH_8_BIT  |
        SPI_POLARITY_LOW      |
        SPI_PHASE_1_EDGE      |
        SPI_NSS_SOFT          |     // The CS pin will be handle in software
        SPI_MSB_FIRST         |
        SPI_FULL_DUPLEX,            // SPI_FULL_DUPLEX or SPI_HALF_DUPLEX
		24000000,                   // The DAC chip is 12 inche away from CPU on 790A, so reduced comm speed
		SPI2_IRQn,                  // IRQn_Channel

        // DMA_RX
        {
            SPI_STANDARD_CONFIGURATION_RX | DMA_CHANNEL_0, // Configuration + DMA_Channel RX
            DMA_LIFCR_CTCIF3,                              // RX_IT_Flag
            DMA1_Stream3,                                  // RX_DMA_TypeDef
            DMA1_Stream3_IRQn,                             // RX_IRQn
        },

        // DMA_TX
        {
            SPI_STANDARD_CONFIGURATION_TX | DMA_CHANNEL_0, // Configuration + DMA_Channel TX
            DMA_HIFCR_CTCIF4,                              // TX_IT_Flag
            DMA1_Stream4,                                  // TX_DMA_TypeDef
            DMA1_Stream4_IRQn,                             // TX_IRQn
        },
 	},
  #endif

  #if (SPI_DRIVER_SUPPORT_SPI3_CFG == DEF_ENABLED)
	{
		SPI3,                       // SPIx
        SPI_MODE_MASTER       |     // Configuration
        SPI_DATA_WIDTH_8_BIT  |
        SPI_POLARITY_LOW      |
        SPI_PHASE_1_EDGE      |
        SPI_NSS_SOFT          |     // The CS pin will be handle in software
        SPI_MSB_FIRST         |
        SPI_FULL_DUPLEX,            // SPI_FULL_DUPLEX or SPI_HALF_DUPLEX
		24000000,                   // The DAC chip is 12 inche away from CPU on 790A, so reduced comm speed
		SPI3_IRQn,                  // IRQn_Channel

        // DMA_RX
        {
            SPI_STANDARD_CONFIGURATION_RX | DMA_CHANNEL_0, // Configuration + DMA_Channel RX
            DMA_LIFCR_CTCIF0,                              // RX_IT_Flag
            DMA1_Stream0,                                  // RX_DMA_TypeDef
            DMA1_Stream0_IRQn,                             // RX_IRQn

            // Other choice
         // SPI_STANDARD_CONFIGURATION_RX | DMA_CHANNEL_0, // Configuration + DMA_Channel RX
         // DMA_LIFCR_CTCIF2,                              // RX_IT_Flag
         // DMA1_Stream2,                                  // RX_DMA_TypeDef
         // DMA1_Stream2_IRQn,                             // RX_IRQn
        },

        // DMA_TX
        {
            SPI_STANDARD_CONFIGURATION_TX | DMA_CHANNEL_0, // Configuration + DMA_Channel TX
            DMA_HIFCR_CTCIF5,                              // TX_IT_Flag
            DMA1_Stream5,                                  // TX_DMA_TypeDef
            DMA1_Stream5_IRQn,                             // TX_IRQn

            // Other choice
         // SPI_STANDARD_CONFIGURATION_TX | DMA_CHANNEL_0, // Configuration + DMA_Channel TX
         // DMA_HIFCR_CTCIF7,                              // TX_IT_Flag
         // DMA1_Stream7,                                  // TX_DMA_TypeDef
         // DMA1_Stream7_IRQn,                             // TX_IRQn
        },
	},
  #endif

    #if (SPI_DRIVER_SUPPORT_SPI4_CFG == DEF_ENABLED)
	{
		SPI4,                       // SPIx
        SPI_MODE_MASTER       |     // Configuration
        SPI_DATA_WIDTH_8_BIT  |
        SPI_POLARITY_LOW      |
        SPI_PHASE_1_EDGE      |
        SPI_NSS_SOFT          |     // The CS pin will be handle in software
        SPI_MSB_FIRST         |
        SPI_FULL_DUPLEX,            // SPI_FULL_DUPLEX or SPI_HALF_DUPLEX
		24000000,                   // The DAC chip is 12 inche away from CPU on 790A, so reduced comm speed
		SPI4_IRQn,                  // IRQn_Channel

        // DMA_RX
        {
            SPI_STANDARD_CONFIGURATION_RX | DMA_CHANNEL_5, // Configuration + DMA_Channel RX or SPI_DMA_DISABLED
            DMA_LIFCR_CTCIF3,                              // RX_IT_Flag
            DMA2_Stream3,                                  // RX_DMA_TypeDef
            DMA2_Stream3_IRQn,                             // RX_IRQn
            6,                                             // PreempPrio
        },

        // DMA_TX
        {
            SPI_STANDARD_CONFIGURATION_TX | DMA_CHANNEL_5, // Configuration + DMA_Channel TX or SPI_DMA_DISABLED
            DMA_HIFCR_CTCIF4,                              // TX_IT_Flag
            DMA2_Stream4,                                  // TX_DMA_TypeDef
            DMA2_Stream4_IRQn,                             // TX_IRQn
            6,                                             // PreempPrio
        },
	},
  #endif

  #if (SPI_DRIVER_SUPPORT_SPI5_CFG == DEF_ENABLED)
	{
		SPI5,                       // SPIx
        SPI_MODE_MASTER       |     // Configuration
        SPI_DATA_WIDTH_8_BIT  |
        SPI_POLARITY_LOW      |
        SPI_PHASE_1_EDGE      |
        SPI_NSS_SOFT          |     // The CS pin will be handle in software
        SPI_MSB_FIRST         |
        SPI_FULL_DUPLEX,            // SPI_FULL_DUPLEX or SPI_HALF_DUPLEX
		8000000,                    // The DAC chip is 12 inche away from CPU on 790A, so reduced comm speed
		SPI5_IRQn,                  // IRQn_Channel

        // DMA_RX
        {
            SPI_DMA_DISABLED,                             // Configuration + DMA_Channel RX or SPI_DMA_DISABLED
            DMA_HIFCR_CTCIF6,                              // RX_IT_Flag
            DMA2_Stream6,                                  // RX_DMA_TypeDef
            DMA2_Stream6_IRQn,                             // RX_IRQn
            6,                                             // PreempPrio
        },

        // DMA_TX
        {
            SPI_STANDARD_CONFIGURATION_TX | DMA_CHANNEL_1, // Configuration + DMA_Channel TX or SPI_DMA_DISABLED
            DMA_HIFCR_CTCIF5,                              // TX_IT_Flag
            DMA2_Stream5,                                  // TX_DMA_TypeDef
            DMA2_Stream5_IRQn,                             // TX_IRQn
            6,                                             // PreempPrio
        },
	},
  #endif

  #if (SPI_DRIVER_SUPPORT_SPI6_CFG == DEF_ENABLED)
	{
		SPI6,                       // SPIx
        SPI_MODE_MASTER       |     // Configuration
        SPI_DATA_WIDTH_8_BIT  |
        SPI_POLARITY_LOW      |
        SPI_PHASE_1_EDGE      |
        SPI_NSS_SOFT          |     // The CS pin will be handle in software
        SPI_MSB_FIRST         |
        SPI_FULL_DUPLEX,            // SPI_FULL_DUPLEX or SPI_HALF_DUPLEX
		8000000,                    // The DAC chip is 12 inche away from CPU on 790A, so reduced comm speed
		SPI6_IRQn,                  // IRQn_Channel

        // DMA_RX
        {
            SPI_DMA_DISABLED,                             // Configuration + DMA_Channel RX or SPI_DMA_DISABLED
            DMA_HIFCR_CTCIF6,                              // RX_IT_Flag
            DMA2_Stream6,                                  // RX_DMA_TypeDef
            DMA2_Stream6_IRQn,                             // RX_IRQn
            6,                                             // PreempPrio
        },

        // DMA_TX
        {
            SPI_STANDARD_CONFIGURATION_TX | DMA_CHANNEL_1, // Configuration + DMA_Channel TX or SPI_DMA_DISABLED
            DMA_HIFCR_CTCIF5,                              // TX_IT_Flag
            DMA2_Stream5,                                  // TX_DMA_TypeDef
            DMA2_Stream5_IRQn,                             // TX_IRQn
            6,                                             // PreempPrio
        },
	},
  #endif
};

//class SPI_Driver mySPI_ForDAC(DRIVER_SPI1_ID);
class SPI_Driver mySPI_ForVFD(DRIVER_SPI1_ID);

#else // SPI_DRIVER_GLOBAL

//extern class SPI_Driver     mySPI_ForDAC;
extern class SPI_Driver     mySPI_ForVFD;

#endif // SPI_DRIVER_GLOBAL

//-------------------------------------------------------------------------------------------------
