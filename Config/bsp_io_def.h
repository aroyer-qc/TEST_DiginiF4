//-------------------------------------------------------------------------------------------------
//
//  File : bsp_io_def.h
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

//-------------------------------------------------------------------------------------------------
//
//          Parameter 1:  This is the ID of the IO pin
//          Parameter 2:  Port for the PIN
//                          GPIOx
//          Parameter 3:  IO number for the PIN
//          Parameter 4:  MODE for the pin
//                          IO_MODE_INPUT
//                          IO_MODE_OUTPUT
//                          IO_MODE_ALTERNATE
//                          IO_MODE_ANALOG
//          Parameter 5:  TYPE for the pin
//                          IO_TYPE_PIN_DRIVE_MASK
//                          IO_TYPE_PIN_DRIVE_SHIFT
//                          IO_TYPE_PIN_PP
//                          IO_TYPE_PIN_OD
//          Parameter 6:  SPEED for the pin
//                          IO_SPEED_FREQ_LOW
//                          IO_SPEED_FREQ_MEDIUM
//                          IO_SPEED_FREQ_HIGH
//                          IO_SPEED_FREQ_VERY_HIGH
//          Parameter 7:  EXTRA info for the pin
//                          If mode is IO_MODE_INPUT,        This is not used. Put 0 there
//                          If mode is IO_MODE_OUTPUT,       This is the default level on the pin at initialization. Put level HALIO_LEVEL_0 or HALIO_LEVEL_1 or HALIO_LEVEL_HIGH_Z
//                          If mode is IO_MODE_ALTERNATE,    This is the alternate setting
//                                                               Example: GPIO_AF7_USART3  -  See hal_io.h for your CPU
//                          If mode is IO_MODE_ANALOG,       This is used to select the ADC input               // to be validated!!!
//
//-------------------------------------------------------------------------------------------------

#define IO_DEF(X_IO) \
/*        ENUM ID of the IO,     IO Port,    IO Pin, Mode,               Pin type,              IO Speed,                 Pin Option           */\
/* Output IO's --------------------------------------------------------------------------------------------------------------------------------*/\
    X_IO( IO_LED_RED,            GPIOB,      14,     IO_MODE_OUTPUT,     IO_TYPE_PIN_PP,        IO_SPEED_FREQ_LOW,        0)                     \
    X_IO( IO_LED_GREEN,          GPIOB,      0,      IO_MODE_OUTPUT,     IO_TYPE_PIN_PP,        IO_SPEED_FREQ_LOW,        0)                     \
    X_IO( IO_LED_BLUE,           GPIOB,      7,      IO_MODE_OUTPUT,     IO_TYPE_PIN_PP,        IO_SPEED_FREQ_LOW,        0)                     \
/* SPI IO's -----------------------------------------------------------------------------------------------------------------------------------*/\
    X_IO( IO_SPI3_CLK,           GPIOB,      3,      IO_MODE_ALTERNATE,  IO_TYPE_PIN_PP,        IO_SPEED_FREQ_HIGH,       IO_AF5_SPI3)           \
    X_IO( IO_SPI3_MOSI,          GPIOB,      5,      IO_MODE_ALTERNATE,  IO_TYPE_PIN_PP,        IO_SPEED_FREQ_HIGH,       IO_AF5_SPI3)           \
/* UART IO's ----------------------------------------------------------------------------------------------------------------------------------*/\
    X_IO( IO_UART3_RX,           GPIOD,      9,      IO_MODE_ALTERNATE,  IO_TYPE_PIN_PP,        IO_SPEED_FREQ_LOW,        IO_AF7_USART3)         \
    X_IO( IO_UART3_TX,           GPIOD,      8,      IO_MODE_ALTERNATE,  IO_TYPE_PIN_PP,        IO_SPEED_FREQ_LOW,        IO_AF7_USART3)         \
/* PWM Output ---------------------------------------------------------------------------------------------------------------------------------*/\
    X_IO( IO_VFD_BLANK,          GPIOA,      0,      IO_MODE_ALTERNATE,  IO_TYPE_PIN_PP,        IO_SPEED_FREQ_MEDIUM,     IO_AF1_TIM2)           \
    X_IO( IO_VFD_LOAD,           GPIOG,      9,      IO_MODE_OUTPUT,     IO_TYPE_PIN_PP,        IO_SPEED_FREQ_LOW,        0)                     \
/* Ethernet -----------------------------------------------------------------------------------------------------------------------------------*/\
    X_IO( IO_ETH_REF_CLK,        GPIOA,      1,      IO_MODE_ALTERNATE,  IO_TYPE_PIN_PP,        IO_SPEED_FREQ_HIGH,       IO_AF11_ETH)           \
    X_IO( IO_ETH_MDIO,           GPIOA,      2,      IO_MODE_ALTERNATE,  IO_TYPE_PIN_PP,        IO_SPEED_FREQ_HIGH,       IO_AF11_ETH)           \
    X_IO( IO_ETH_MDC,            GPIOC,      1,      IO_MODE_ALTERNATE,  IO_TYPE_PIN_PP,        IO_SPEED_FREQ_HIGH,       IO_AF11_ETH)           \
    X_IO( IO_ETH_CRS_DV,         GPIOA,      7,      IO_MODE_ALTERNATE,  IO_TYPE_PIN_PP,        IO_SPEED_FREQ_HIGH,       IO_AF11_ETH)           \
    X_IO( IO_ETH_RXD0,           GPIOC,      4,      IO_MODE_ALTERNATE,  IO_TYPE_PIN_PP,        IO_SPEED_FREQ_HIGH,       IO_AF11_ETH)           \
    X_IO( IO_ETH_RXD1,           GPIOC,      5,      IO_MODE_ALTERNATE,  IO_TYPE_PIN_PP,        IO_SPEED_FREQ_HIGH,       IO_AF11_ETH)           \
    X_IO( IO_ETH_TX_EN,          GPIOG,      11,     IO_MODE_ALTERNATE,  IO_TYPE_PIN_PP,        IO_SPEED_FREQ_HIGH,       IO_AF11_ETH)           \
    X_IO( IO_ETH_TXD0,           GPIOG,      13,     IO_MODE_ALTERNATE,  IO_TYPE_PIN_PP,        IO_SPEED_FREQ_HIGH,       IO_AF11_ETH)           \
    X_IO( IO_ETH_TXD1,           GPIOB,      13,     IO_MODE_ALTERNATE,  IO_TYPE_PIN_PP,        IO_SPEED_FREQ_HIGH,       IO_AF11_ETH)           \
/* MCO ----------------------------------------------------------------------------------------------------------------------------------------*/\
    X_IO( IO_MCO_2,              GPIOC,      9,      IO_MODE_ALTERNATE,  IO_TYPE_PIN_PP,        IO_SPEED_FREQ_HIGH,       IO_AF0_MCO)            \

//-------------------------------------------------------------------------------------------------

#define IO_ETH_RX_ER        IO_NOT_DEFINED          // no RX error pin support
#define IO_ETH_EXT_LED      IO_LED_BLUE


/* SPI IO's -----------------------------------------------------------------------------------------------------------------------------------*/\
//    X_IO( IO_SPI1_CLK,           GPIOA,      5,      IO_MODE_ALTERNATE,  IO_TYPE_PIN_PP,        IO_SPEED_FREQ_HIGH,       IO_AF5_SPI1)
//    X_IO( IO_SPI1_MOSI,          GPIOA,      7,      IO_MODE_ALTERNATE,  IO_TYPE_PIN_PP,        IO_SPEED_FREQ_HIGH,       IO_AF5_SPI1)
//    X_IO( IO_SPI1_CS,            GPIOB,      9,      IO_MODE_OUTPUT,     IO_TYPE_PIN_PP,        IO_SPEED_FREQ_HIGH,       1)




// Note(s) the pin IO_CALIB_OUT_DEBUG is only use in some debug case and must not be initialized on permanent base

//-------------------------------------------------------------------------------------------------
//
//          Parameter 1:  This is the ID of the IO IRQ pin
//
//          Parameter 2:  This is the ID of the IO pin used for this IRQ IO
//                          GPIOx
//
//          Parameter 3:    EXTI0_IRQn                  EXTI Line0 Interrupt
//                          EXTI1_IRQn                  EXTI Line1 Interrupt
//                          EXTI2_IRQn                  EXTI Line2 Interrupt
//                          EXTI3_IRQn                  EXTI Line3 Interrupt
//                          EXTI4_IRQn                  EXTI Line4 Interrupt
//                          EXTI9_5_IRQn                External Line[9:5] Interrupts
//                          EXTI15_10_IRQn              External Line[15:10] Interrupts
//
//          Parameter 4:    IO_EXTI_TRIGGER_RISING
//                          IO_EXTI_TRIGGER_FALLING
//                          IO_EXTI_TRIGGER_RISING_FALLING
//
//-------------------------------------------------------------------------------------------------

#if 0
#define IO_IRQ_DEF(X_IO_IRQ) \
/*           Enum ID                    Pin ID                 EXTI Pin Source     Trigger                         */\


#endif
//-------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------

