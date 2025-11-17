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
//          IO_CFG_DEF(X_IO_CFG)
//
//          This is common configuration for IO_DEF pin declaration.
//          It help reduce code size by sharing configuration.
//
//          Parameter 1:  ENUM ID of the configuration
//
//          Parameter 2:  MODE for the pin
//                          IO_MODE_INPUT
//                          IO_MODE_OUTPUT
//                          IO_MODE_ALTERNATE
//                          IO_MODE_ANALOG
//          Parameter 3:  TYPE for the pin
//                          IO_TYPE_PIN_DRIVE_MASK
//                          IO_TYPE_PIN_DRIVE_SHIFT
//                          IO_TYPE_PIN_PP
//                          IO_TYPE_PIN_OD
//          Parameter 4:  SPEED for the pin
//                          IO_SPEED_FREQ_LOW
//                          IO_SPEED_FREQ_MEDIUM
//                          IO_SPEED_FREQ_HIGH
//                          IO_SPEED_FREQ_VERY_HIGH
//          Parameter 5:  EXTRA info for the pin
//                          If mode is IO_MODE_INPUT,        This is not used. Put 0 there
//                          If mode is IO_MODE_OUTPUT,       This is the default level on the pin at initialization. Put level 0 or 1
//                          If mode is IO_MODE_ALTERNATE,    This is the alternate setting
//                                                               Example: GPIO_AF7_USART3  -  See lib_STM3F4_io.h
//                          If mode is IO_MODE_ANALOG,       This is used to select the ADC input               // to be validated!!!
//
//-------------------------------------------------------------------------------------------------
#ifdef STM32F401xE
#define IO_CFG_DEF(X_IO_CFG) \
/*            ENUM ID IO CFG,                           Mode,               Pin type,              IO Speed,                 Pin Option           */\
/* input IO's CFG --------------------------------------------------------------------------------------------------------------------------------*/\
    X_IO_CFG( IO_CFG_INPUT_NP_LS,                       IO_MODE_INPUT,      IO_TYPE_PIN_NO_PULL,   IO_SPEED_FREQ_LOW,        0)                     \
/* Output IO's CFG -------------------------------------------------------------------------------------------------------------------------------*/\
    X_IO_CFG( IO_CFG_OUTPUT_PP_LS_DEF0,                 IO_MODE_OUTPUT,     IO_TYPE_PIN_PP,        IO_SPEED_FREQ_LOW,        0)                     \
    X_IO_CFG( IO_CFG_OUTPUT_PP_LS_DEF1,                 IO_MODE_OUTPUT,     IO_TYPE_PIN_PP,        IO_SPEED_FREQ_LOW,        1)                     \
    X_IO_CFG( IO_CFG_OUTPUT_PP_HS_DEF1,                 IO_MODE_OUTPUT,     IO_TYPE_PIN_PP,        IO_SPEED_FREQ_HIGH,       1)                     \
/* MCO IO's CFG ----------------------------------------------------------------------------------------------------------------------------------*/\
    X_IO_CFG( IO_CFG_MCO_OUTPUT,                        IO_MODE_ALTERNATE,  IO_TYPE_PIN_PP,        IO_SPEED_FREQ_HIGH,       IO_AF0_MCO)            \
/* SPI IO's CFG ----------------------------------------------------------------------------------------------------------------------------------*/\
    X_IO_CFG( IO_CFG_SPI_AF5,                           IO_MODE_ALTERNATE,  IO_TYPE_PIN_PP,        IO_SPEED_FREQ_HIGH,       IO_AF5_SPI)            \
/* TIM IO's CFG ----------------------------------------------------------------------------------------------------------------------------------*/\
    X_IO_CFG( IO_CFG_TIM_AF1,                           IO_MODE_ALTERNATE,  IO_TYPE_PIN_PP,        IO_SPEED_FREQ_MEDIUM,     IO_AF1)/* TIM 1 & 2) */\
/* UART IO's CFG ---------------------------------------------------------------------------------------------------------------------------------*/\
    X_IO_CFG( IO_CFG_UART2_AF7,                         IO_MODE_ALTERNATE,  IO_TYPE_PIN_PP,        IO_SPEED_FREQ_MEDIUM,     IO_AF7_USART2)         \
/* -----------------------------------------------------------------------------------------------------------------------------------------------*/
#endif

#ifdef STM32F407xx              // TODO for Discovery F407
#define IO_CFG_DEF(X_IO_CFG) \
/*            ENUM ID IO CFG,                           Mode,               Pin type,              IO Speed,                 Pin Option           */\
/* input IO's CFG --------------------------------------------------------------------------------------------------------------------------------*/\
    X_IO_CFG( IO_CFG_INPUT_NP_LS,                       IO_MODE_INPUT,      IO_TYPE_PIN_NO_PULL,   IO_SPEED_FREQ_LOW,        0)                     \
/* Output IO's CFG -------------------------------------------------------------------------------------------------------------------------------*/\
    X_IO_CFG( IO_CFG_OUTPUT_PP_LS_DEF0,                 IO_MODE_OUTPUT,     IO_TYPE_PIN_PP,        IO_SPEED_FREQ_LOW,        0)                     \
    X_IO_CFG( IO_CFG_OUTPUT_PP_LS_DEF1,                 IO_MODE_OUTPUT,     IO_TYPE_PIN_PP,        IO_SPEED_FREQ_LOW,        1)                     \
    X_IO_CFG( IO_CFG_OUTPUT_PP_HS_DEF1,                 IO_MODE_OUTPUT,     IO_TYPE_PIN_PP,        IO_SPEED_FREQ_HIGH,       1)                     \
/* MCO IO's CFG ----------------------------------------------------------------------------------------------------------------------------------*/\
    X_IO_CFG( IO_CFG_MCO_OUTPUT,                        IO_MODE_ALTERNATE,  IO_TYPE_PIN_PP,        IO_SPEED_FREQ_HIGH,       IO_AF0_MC0)            \
/* SPI IO's CFG ----------------------------------------------------------------------------------------------------------------------------------*/\
    X_IO_CFG( IO_CFG_SPI_AF5,                           IO_MODE_ALTERNATE,  IO_TYPE_PIN_PP,        IO_SPEED_FREQ_HIGH,       IO_AF5_SPI)            \
/* TIM IO's CFG ----------------------------------------------------------------------------------------------------------------------------------*/\
    X_IO_CFG( IO_CFG_TIM_AF1,                           IO_MODE_ALTERNATE,  IO_TYPE_PIN_PP,        IO_SPEED_FREQ_MEDIUM,     IO_AF1)/* TIM 1 & 2) */\
/* UART IO's CFG ---------------------------------------------------------------------------------------------------------------------------------*/\
    X_IO_CFG( IO_CFG_UART2_AF7,                         IO_MODE_ALTERNATE,  IO_TYPE_PIN_PP,        IO_SPEED_FREQ_MEDIUM,     IO_AF7_USART2)         \
/* -----------------------------------------------------------------------------------------------------------------------------------------------*/
#endif


#ifdef STM32F429xx
#define IO_CFG_DEF(X_IO_CFG) \
/*            ENUM ID IO CFG,                           Mode,               Pin type,              IO Speed,                 Pin Option           */\
/* input IO's CFG --------------------------------------------------------------------------------------------------------------------------------*/\
    X_IO_CFG( IO_CFG_INPUT_NP_LS,                       IO_MODE_INPUT,      IO_TYPE_PIN_NO_PULL,   IO_SPEED_FREQ_LOW,        0)                     \
/* Output IO's CFG -------------------------------------------------------------------------------------------------------------------------------*/\
    X_IO_CFG( IO_CFG_OUTPUT_PP_LS_DEF0,                 IO_MODE_OUTPUT,     IO_TYPE_PIN_PP,        IO_SPEED_FREQ_LOW,        0)                     \
    X_IO_CFG( IO_CFG_OUTPUT_PP_LS_DEF1,                 IO_MODE_OUTPUT,     IO_TYPE_PIN_PP,        IO_SPEED_FREQ_LOW,        1)                     \
    X_IO_CFG( IO_CFG_OUTPUT_PP_HS_DEF1,                 IO_MODE_OUTPUT,     IO_TYPE_PIN_PP,        IO_SPEED_FREQ_HIGH,       1)                     \
/* ETH IO's CFG ----------------------------------------------------------------------------------------------------------------------------------*/\
    X_IO_CFG( IO_CFG_ETH_PP_VHS_AF11,                   IO_MODE_ALTERNATE,  IO_TYPE_PIN_PP,        IO_SPEED_FREQ_VERY_HIGH,  IO_AF11_ETH)           \
/* LCD IO's CFG ----------------------------------------------------------------------------------------------------------------------------------*/\
    X_IO_CFG( IO_CFG_LCD_PORT_AF14,                     IO_MODE_ALTERNATE,  IO_TYPE_PIN_PP,        IO_SPEED_FREQ_VERY_HIGH,  IO_AF14_LTDC)          \
/* MCO IO's CFG ----------------------------------------------------------------------------------------------------------------------------------*/\
    X_IO_CFG( IO_CFG_MCO_OUTPUT,                        IO_MODE_ALTERNATE,  IO_TYPE_PIN_PP,        IO_SPEED_FREQ_HIGH,       IO_AF0_MCO)            \
/* SPI IO's CFG ----------------------------------------------------------------------------------------------------------------------------------*/\
    X_IO_CFG( IO_CFG_SPI_AF5,                           IO_MODE_ALTERNATE,  IO_TYPE_PIN_PP,        IO_SPEED_FREQ_HIGH,       IO_AF5_SPI)            \
/* TIM IO's CFG ----------------------------------------------------------------------------------------------------------------------------------*/\
    X_IO_CFG( IO_CFG_TIM_AF1,                           IO_MODE_ALTERNATE,  IO_TYPE_PIN_PP,        IO_SPEED_FREQ_MEDIUM,     IO_AF1_TIM)            \
/* UART IO's CFG ---------------------------------------------------------------------------------------------------------------------------------*/\
    X_IO_CFG( IO_CFG_UART3_AF7,                         IO_MODE_ALTERNATE,  IO_TYPE_PIN_PP,        IO_SPEED_FREQ_MEDIUM,     IO_AF7_USART3)         \
    X_IO_CFG( IO_CFG_UART6_AF8,                         IO_MODE_ALTERNATE,  IO_TYPE_PIN_PP,        IO_SPEED_FREQ_LOW,        IO_AF8_USART6)         \
/* -----------------------------------------------------------------------------------------------------------------------------------------------*/
#endif

//-------------------------------------------------------------------------------------------------
//
//          IO_DEF(X_IO)
//
//          Parameter 1:  This is the ID of the IO pin
//          Parameter 2:  Port for the PIN
//                          GPIOx
//          Parameter 3:  IO number for the PIN
//          Parameter 4:  IO CFG to used for this pin
//
//-------------------------------------------------------------------------------------------------

#ifdef STM32F401xE
#define IO_DEF(X_IO) \
/* ---------------------------------------------------------------------------------------------*/\
/*        ENUM ID of the IO,    IO Port,    IO Pin, IO Config                                   */\
/* Input IO's ----------------------------------------------------------------------------------*/\
    X_IO( IO_USER_SWITCH,       GPIOC,      IO_PIN_13,     IO_CFG_INPUT_NP_LS)                    \
/* Output IO's ---------------------------------------------------------------------------------*/\
    X_IO( IO_LED_GREEN,         GPIOD,      IO_PIN_13,     IO_CFG_OUTPUT_PP_LS_DEF0)              \
/* MCO -----------------------------------------------------------------------------------------*/\
    X_IO( IO_MCO_2,             GPIOC,      IO_PIN_9,      IO_CFG_MCO_OUTPUT)                     \
/* ---------------------------------------------------------------------------------------------*/
#endif

#ifdef STM32F407xx              // TODO for Discovery F407 now B02
#define IO_DEF(X_IO) \
/* ---------------------------------------------------------------------------------------------*/\
/*        ENUM ID of the IO,    IO Port,    IO Pin, IO Config                                   */\
/* Input IO's ----------------------------------------------------------------------------------*/\
    X_IO( IO_USER_SWITCH,       GPIOA,      IO_PIN_0,      IO_CFG_INPUT_NP_LS)                    \
/* Output IO's ---------------------------------------------------------------------------------*/\
    X_IO( IO_LED_GREEN,         GPIOD,      IO_PIN_12,     IO_CFG_OUTPUT_PP_LS_DEF0)              \
    X_IO( IO_LED_ORANGE,        GPIOD,      IO_PIN_13,     IO_CFG_OUTPUT_PP_LS_DEF0)              \
    X_IO( IO_LED_RED,           GPIOD,      IO_PIN_14,     IO_CFG_OUTPUT_PP_LS_DEF0)              \
    X_IO( IO_LED_BLUE,          GPIOD,      IO_PIN_15,     IO_CFG_OUTPUT_PP_LS_DEF0)              \
/* MCO -----------------------------------------------------------------------------------------*/\
    X_IO( IO_MCO_2,             GPIOC,      IO_PIN_9,      IO_CFG_MCO_OUTPUT)                     \
/* ---------------------------------------------------------------------------------------------*/
#endif

#ifdef STM32F429xx
#define IO_DEF(X_IO) \
/* ---------------------------------------------------------------------------------------------*/\
/*        ENUM ID of the IO,    IO Port,    IO Pin,         IO Config                           */\
/* Input IO's ----------------------------------------------------------------------------------*/\
    X_IO( IO_USER_SWITCH,       GPIOC,      IO_PIN_13,      IO_CFG_INPUT_NP_LS)                   \
/* Output IO's ---------------------------------------------------------------------------------*/\
    X_IO( IO_LED_RED,           GPIOB,      IO_PIN_14,      IO_CFG_OUTPUT_PP_LS_DEF1)             \
    X_IO( IO_LED_GREEN,         GPIOB,      IO_PIN_0,       IO_CFG_OUTPUT_PP_LS_DEF1)             \
    X_IO( IO_LED_BLUE,          GPIOB,      IO_PIN_7,       IO_CFG_OUTPUT_PP_LS_DEF1)             \
/* SPI IO's ------------------------------------------------------------------------------------*/\
    X_IO( IO_SPI1_CS,           GPIOB,      IO_PIN_9,       IO_CFG_OUTPUT_PP_HS_DEF1)             \
/* PWM Output ----------------------------------------------------------------------------------*/\
    X_IO( IO_VFD_BLANK,         GPIOA,      IO_PIN_0,       IO_CFG_TIM_AF1)                       \
    X_IO( IO_VFD_LOAD,          GPIOG,      IO_PIN_9,       IO_CFG_OUTPUT_PP_LS_DEF0)             \
    X_IO( IO_NEO_DATA,          GPIOE,      IO_PIN_14,      IO_CFG_TIM_AF1)                       \
/* MCO -----------------------------------------------------------------------------------------*/\
    X_IO( IO_MCO_2,             GPIOC,      IO_PIN_9,       IO_CFG_MCO_OUTPUT)                    \
/* ---------------------------------------------------------------------------------------------*/
#endif


//-------------------------------------------------------------------------------------------------
//
//  IO_GROUP is useful for pin sharing configuration and they are not used individually at run time
//  because they are control by module.
//
//    Examples: LCD, SDRAM, ETH, etc...
//
//  Notes : Some group might share same config
//
//-------------------------------------------------------------------------------------------------

//---------------------------------------
// ETH grouping configuration STM32F429xx
#define ETH_PIN_ON_PORT_A               (IO_PIN_1  | IO_PIN_2  | IO_PIN_7)
#define ETH_PIN_ON_PORT_B               (IO_PIN_13)
#define ETH_PIN_ON_PORT_C               (IO_PIN_1  | IO_PIN_5)
#define ETH_PIN_ON_PORT_G               (IO_PIN_11 | IO_PIN_13)

//---------------------------------------------------------
// SPI3 grouping configuration on STM32F401xx & STM32F429xx
#define SPI1_PIN_ON_PORT_A              (IO_PIN_5  | IO_PIN_7)
#define SPI3_PIN_ON_PORT_B              (IO_PIN_5  | IO_PIN_5)

//--------------------------------------------
// UART2 grouping configuration on STM32F401xx
#define UART2_PIN_ON_PORT_xx            (IO_PIN_2  | IO_PIN_3)

//--------------------------------------------
// UART3 grouping configuration on STM32F429xx
#define UART3_PIN_ON_PORT_D             (IO_PIN_8 | IO_PIN_9)
#define UART6_PIN_ON_PORT_C             (IO_PIN_6 /*| IO_PIN_7*/)

//-------------------------------------------------------------

#ifdef STM32F401xE
#define IO_GROUP_DEF(X_IO_GROUP) \
/* ------------------------------------------------------------------------------------------------------*/\
/*              ENUM ID of the Group,   IO Port,    IO Group Pin,               IO ConfigMode            */\
/* SPI --------------------------------------------------------------------------------------------------*/\
    X_IO_GROUP( IO_SPI1_ON_PORT_A,      GPIOA,      SPI1_PIN_ON_PORT_A,         IO_CFG_SPI_AF5)            \
    X_IO_GROUP( IO_SPI3_ON_PORT_B,      GPIOB,      SPI3_PIN_ON_PORT_B,         IO_CFG_SPI_AF5)            \
/* UART -------------------------------------------------------------------------------------------------*/\
    X_IO_GROUP( IO_UART2_ON_PORT_xx,    GPIOxx,     UART2_PIN_ON_PORT_xx,       IO_CFG_UART2_AF7)          \
/* ------------------------------------------------------------------------------------------------------*/
#endif

#ifdef STM32F407xx              // TODO for Discovery F407
#define IO_GROUP_DEF(X_IO_GROUP) \
/* ------------------------------------------------------------------------------------------------------*/\
/*              ENUM ID of the Group,   IO Port,    IO Group Pin,               IO ConfigMode            */\
/* SPI --------------------------------------------------------------------------------------------------*/\
    X_IO_GROUP( IO_SPI1_ON_PORT_A,      GPIOxx,      SPI1_PIN_ON_PORT_A,        IO_CFG_SPI_AF5)            \
    X_IO_GROUP( IO_SPI3_ON_PORT_B,      GPIOxx,      SPI3_PIN_ON_PORT_B,        IO_CFG_SPI_AF5)            \
/* UART -------------------------------------------------------------------------------------------------*/\
    X_IO_GROUP( IO_UART2_ON_PORT_xx,    GPIOxx,      UART2_PIN_ON_PORT_xx,      IO_CFG_UART2_AF7)          \
/* ------------------------------------------------------------------------------------------------------*/
#endif

#ifdef STM32F429xx
#define IO_GROUP_DEF(X_IO_GROUP) \
/* ------------------------------------------------------------------------------------------------------*/\
/*              ENUM ID of the Group,   IO Port,    IO Group Pin,               IO ConfigMode            */\
/* ETH --------------------------------------------------------------------------------------------------*/\
    X_IO_GROUP( IO_ETH_ON_PORT_A,       GPIOA,      ETH_PIN_ON_PORT_A,          IO_CFG_ETH_PP_VHS_AF11)    \
    X_IO_GROUP( IO_ETH_ON_PORT_B,       GPIOB,      ETH_PIN_ON_PORT_B,          IO_CFG_ETH_PP_VHS_AF11)    \
    X_IO_GROUP( IO_ETH_ON_PORT_C,       GPIOC,      ETH_PIN_ON_PORT_C,          IO_CFG_ETH_PP_VHS_AF11)    \
    X_IO_GROUP( IO_ETH_ON_PORT_G,       GPIOG,      ETH_PIN_ON_PORT_G,          IO_CFG_ETH_PP_VHS_AF11)    \
/* SPI --------------------------------------------------------------------------------------------------*/\
    X_IO_GROUP( IO_SPI1_ON_PORT_A,      GPIOA,      SPI1_PIN_ON_PORT_A,         IO_CFG_SPI_AF5)            \
    X_IO_GROUP( IO_SPI3_ON_PORT_B,      GPIOB,      SPI3_PIN_ON_PORT_B,         IO_CFG_SPI_AF5)            \
/* UART -------------------------------------------------------------------------------------------------*/\
    X_IO_GROUP( IO_UART3_ON_PORT_D,     GPIOD,      UART3_PIN_ON_PORT_D,        IO_CFG_UART3_AF7)          \
    X_IO_GROUP( IO_UART6_ON_PORT_C,     GPIOC,      UART6_PIN_ON_PORT_C,        IO_CFG_UART6_AF8)          \
/* ------------------------------------------------------------------------------------------------------*/
#endif


#define IO_ETH_RX_ER        IO_NOT_DEFINED          // no RX error pin support
#define IO_ETH_EXT_LED      IO_LED_BLUE



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
//          Parameter 4:    Priority
//
//          Parameter 5:    IO_EXTI_TRIGGER_RISING
//                          IO_EXTI_TRIGGER_FALLING
//                          IO_EXTI_TRIGGER_RISING_FALLING
//
//          Parameter 6:    Callback function pointer
//
//          Parameter 7:    Argument pointer for callback
//
//-------------------------------------------------------------------------------------------------

#ifdef STM32F407xx
#define IO_IRQ_DEF(X_IO_IRQ) \
/* ----------------------------------------------------------------------------------------------------------------------------------------------------------*/\
/*           Enum ID                Pin ID              EXTI Pin Source  Priority    Trigger                             CallBack                Argument    */\
/* ----------------------------------------------------------------------------------------------------------------------------------------------------------*/\
    X_IO_IRQ(IO_IRQ_USER_SWITCH,    IO_USER_SWITCH,     EXTI0_IRQn,      4,          IO_EXTI_TRIGGER_RISING,             nullptr,                nullptr)      \
/* ---------------------------------------------------------------------------------------------------------------------------------------------------------*/
#endif

#if defined(STM32F401xE) | defined(STM32F429xx)
#define IO_IRQ_DEF(X_IO_IRQ) \
/* ----------------------------------------------------------------------------------------------------------------------------------------------------------*/\
/*           Enum ID                Pin ID              EXTI Pin Source  Priority    Trigger                             CallBack                Argument    */\
/* ----------------------------------------------------------------------------------------------------------------------------------------------------------*/\
    X_IO_IRQ(IO_IRQ_USER_SWITCH,    IO_USER_SWITCH,     EXTI15_10_IRQn,  4,          IO_EXTI_TRIGGER_RISING,             nullptr,                nullptr)      \
/* ---------------------------------------------------------------------------------------------------------------------------------------------------------*/
#endif

//-------------------------------------------------------------------------------------------------

