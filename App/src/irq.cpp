//-------------------------------------------------------------------------------------------------
//
//  File : irq.cpp
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

#include "bsp.h"

//-------------------------------------------------------------------------------------------------

extern "C"
{

//-------------------------------------------------------------------------------------------------
//
//  DDDDD  MM    MM  AAAA
//  DD  DD MMM  MMM AA  AA
//  DD  DD MMMMMMMM AAAAAA
//  DD  DD MM MM MM AA  AA
//  DDDDD  MM    MM AA  AA
//
//-------------------------------------------------------------------------------------------------

NOS_ISR(DMA1_Stream3_IRQHandler)
{
	myUART_Terminal.DMA_TX_IRQ_Handler();
}

#if 0
NOS_ISR(DMA2_Stream0_IRQHandler)
{
	SPI_Driver::DMA_RX_IRQ_Handler(DRIVER_SPI1_ID);
}

NOS_ISR(DMA2_Stream3_IRQHandler)
{
	SPI_Driver::DMA_TX_IRQ_Handler(DRIVER_SPI1_ID);
}

NOS_ISR(DMA1_Stream0_IRQHandler)
{
	SPI_Driver::DMA_RX_IRQ_Handler(DRIVER_SPI3_ID);
}

NOS_ISR(DMA1_Stream5_IRQHandler)
{
	SPI_Driver::DMA_TX_IRQ_Handler(DRIVER_SPI3_ID);
}
#endif

//-------------------------------------------------------------------------------------------------
//
//   SSSSS  PPPPP  IIII
//  SS      PP  PP  II
//   SSSSS  PPPPPP  II
//       SS PP      II
//   SSSSS  PP     IIII
//
//-------------------------------------------------------------------------------------------------
#if (USE_SPI_DRIVER == DEF_ENABLED)
NOS_ISR(SPI1_IRQHandler)
{
    //mySPI_ForDAC.IRQHandler();
    mySPI_ForVFD.IRQHandler();
}

#endif

//-------------------------------------------------------------------------------------------------
//
//  UU  UU  AAAA  RRRRR  TTTTTT
//  UU  UU AA  AA RR  RR   TT
//  UU  UU AAAAAA RRRRR    TT
//  UU  UU AA  AA RR RR    TT
//   UUUU  AA  AA RR  RR   TT
//
//-------------------------------------------------------------------------------------------------

NOS_ISR(USART3_IRQHandler)
{
    myUART_Terminal.IRQ_Handler();
}

//-------------------------------------------------------------------------------------------------
//
// DDDDD  EEEEE BBBBB  UU  UU  GGGGG    TTTTTT RRRRR   AAAA  PPPPP
// DD  DD EE    BB  BB UU  UU GG          TT   RR  RR AA  AA PP  PP
// DD  DD EEEEE BBBBB  UU  UU GG  GGG     TT   RRRRR  AAAAAA PPPPPP
// DD  DD EE    BB  BB UU  UU GG   GG     TT   RR RR  AA  AA PP
// DDDDD  EEEEE BBBBB   UUUU   GGGGG      TT   RR  RR AA  AA PP
//
//-------------------------------------------------------------------------------------------------

/*

inline void DebugTrap(int32_t IRQ_Number)
{
    static int32_t IRQ_Trap = IRQ_Number;

    VAR_UNUSED(IRQ_Trap);

    while(1)
    {
        __asm("nop");
    };
}

//-------------------------------------------------------------------------------------------------

__attribute__((weak)) void NMI_Handler                   (void)  { DebugTrap(NonMaskableInt_IRQn);     }
__attribute__((weak)) void HardFault_Handler             (void)  { DebugTrap(-15);                     }
__attribute__((weak)) void MemManage_Handler             (void)  { DebugTrap(MemoryManagement_IRQn);   }
__attribute__((weak)) void BusFault_Handler              (void)  { DebugTrap(BusFault_IRQn);           }
__attribute__((weak)) void UsageFault_Handler            (void)  { DebugTrap(UsageFault_IRQn);         }
__attribute__((weak)) void SVC_Handler                   (void)  { DebugTrap(SVCall_IRQn);             }
__attribute__((weak)) void DebugMon_Handler              (void)  { DebugTrap(DebugMonitor_IRQn);       }
__attribute__((weak)) void PendSV_Handler                (void)  { DebugTrap(PendSV_IRQn);             }
__attribute__((weak)) void SysTick_Handler               (void)  { DebugTrap(SysTick_IRQn);            }          // If this is the DebugTrap, you forgot to include Lib_nOS_Tick.c
__attribute__((weak)) void WWDG_IRQHandler               (void)  { DebugTrap(WWDG_IRQn);               }
__attribute__((weak)) void PVD_IRQHandler                (void)  { DebugTrap(PVD_IRQn);                }
__attribute__((weak)) void TAMP_STAMP_IRQHandler         (void)  { DebugTrap(TAMP_STAMP_IRQn);         }
__attribute__((weak)) void RTC_WKUP_IRQHandler           (void)  { DebugTrap(RTC_WKUP_IRQn);           }
__attribute__((weak)) void FLASH_IRQHandler              (void)  { DebugTrap(FLASH_IRQn);              }
__attribute__((weak)) void RCC_IRQHandler                (void)  { DebugTrap(RCC_IRQn);                }
__attribute__((weak)) void EXTI0_IRQHandler              (void)  { DebugTrap(EXTI0_IRQn);              }
__attribute__((weak)) void EXTI1_IRQHandler              (void)  { DebugTrap(EXTI1_IRQn);              }
__attribute__((weak)) void EXTI2_IRQHandler              (void)  { DebugTrap(EXTI2_IRQn);              }
__attribute__((weak)) void EXTI3_IRQHandler              (void)  { DebugTrap(EXTI3_IRQn);              }
__attribute__((weak)) void EXTI4_IRQHandler              (void)  { DebugTrap(EXTI4_IRQn);              }
__attribute__((weak)) void DMA1_Stream0_IRQHandler       (void)  { DebugTrap(DMA1_Stream0_IRQn);       }
__attribute__((weak)) void DMA1_Stream1_IRQHandler       (void)  { DebugTrap(DMA1_Stream1_IRQn);       }
__attribute__((weak)) void DMA1_Stream2_IRQHandler       (void)  { DebugTrap(DMA1_Stream2_IRQn);       }
__attribute__((weak)) void DMA1_Stream3_IRQHandler       (void)  { DebugTrap(DMA1_Stream3_IRQn);       }
__attribute__((weak)) void DMA1_Stream4_IRQHandler       (void)  { DebugTrap(DMA1_Stream4_IRQn);       }
__attribute__((weak)) void DMA1_Stream5_IRQHandler       (void)  { DebugTrap(DMA1_Stream5_IRQn);       }
__attribute__((weak)) void DMA1_Stream6_IRQHandler       (void)  { DebugTrap(DMA1_Stream6_IRQn);       }
__attribute__((weak)) void ADC_IRQHandler                (void)  { DebugTrap(ADC_IRQn);                }
__attribute__((weak)) void CAN1_TX_IRQHandler            (void)  { DebugTrap(CAN1_TX_IRQn);            }
__attribute__((weak)) void CAN1_RX0_IRQHandler           (void)  { DebugTrap(CAN1_RX0_IRQn);           }
__attribute__((weak)) void CAN1_RX1_IRQHandler           (void)  { DebugTrap(CAN1_RX1_IRQn);           }
__attribute__((weak)) void CAN1_SCE_IRQHandler           (void)  { DebugTrap(CAN1_SCE_IRQn);           }
__attribute__((weak)) void EXTI9_5_IRQHandler            (void)  { DebugTrap(EXTI9_5_IRQn);            }
__attribute__((weak)) void TIM1_BRK_TIM9_IRQHandler      (void)  { DebugTrap(TIM1_BRK_TIM9_IRQn);      }
__attribute__((weak)) void TIM1_UP_TIM10_IRQHandler      (void)  { DebugTrap(TIM1_UP_TIM10_IRQn);      }
__attribute__((weak)) void TIM1_TRG_COM_TIM11_IRQHandler (void)  { DebugTrap(TIM1_TRG_COM_TIM11_IRQn); }
__attribute__((weak)) void TIM1_CC_IRQHandler            (void)  { DebugTrap(TIM1_CC_IRQn);            }
__attribute__((weak)) void TIM2_IRQHandler               (void)  { DebugTrap(TIM2_IRQn);               }
__attribute__((weak)) void TIM3_IRQHandler               (void)  { DebugTrap(TIM3_IRQn);               }
__attribute__((weak)) void TIM4_IRQHandler               (void)  { DebugTrap(TIM4_IRQn);               }
__attribute__((weak)) void I2C1_EV_IRQHandler            (void)  { DebugTrap(I2C1_EV_IRQn);            }
__attribute__((weak)) void I2C1_ER_IRQHandler            (void)  { DebugTrap(I2C1_ER_IRQn);            }
__attribute__((weak)) void I2C2_EV_IRQHandler            (void)  { DebugTrap(I2C2_EV_IRQn);            }
__attribute__((weak)) void I2C2_ER_IRQHandler            (void)  { DebugTrap(I2C2_ER_IRQn);            }
__attribute__((weak)) void SPI1_IRQHandler               (void)  { DebugTrap(SPI1_IRQn);               }
__attribute__((weak)) void SPI2_IRQHandler               (void)  { DebugTrap(SPI2_IRQn);               }
__attribute__((weak)) void USART1_IRQHandler             (void)  { DebugTrap(USART1_IRQn);             }
__attribute__((weak)) void USART2_IRQHandler             (void)  { DebugTrap(USART2_IRQn);             }
//__attribute__((weak)) void USART3_IRQHandler             (void)  { DebugTrap(USART3_IRQn);             }
__attribute__((weak)) void EXTI15_10_IRQHandler          (void)  { DebugTrap(EXTI15_10_IRQn);          }
__attribute__((weak)) void RTC_Alarm_IRQHandler          (void)  { DebugTrap(RTC_Alarm_IRQn);          }
__attribute__((weak)) void OTG_FS_WKUP_IRQHandler        (void)  { DebugTrap(OTG_FS_WKUP_IRQn);        }
__attribute__((weak)) void TIM8_BRK_TIM12_IRQHandler     (void)  { DebugTrap(TIM8_BRK_TIM12_IRQn);     }
__attribute__((weak)) void TIM8_UP_TIM13_IRQHandler      (void)  { DebugTrap(TIM8_UP_TIM13_IRQn);      }
__attribute__((weak)) void TIM8_TRG_COM_TIM14_IRQHandler (void)  { DebugTrap(TIM8_TRG_COM_TIM14_IRQn); }
__attribute__((weak)) void TIM8_CC_IRQHandler            (void)  { DebugTrap(TIM8_CC_IRQn);            }
__attribute__((weak)) void DMA1_Stream7_IRQHandler       (void)  { DebugTrap(DMA1_Stream7_IRQn);       }
__attribute__((weak)) void FMC_IRQHandler                (void)  { DebugTrap(FMC_IRQn);                }
__attribute__((weak)) void SDIO_IRQHandler               (void)  { DebugTrap(SDIO_IRQn);               }
__attribute__((weak)) void TIM5_IRQHandler               (void)  { DebugTrap(TIM5_IRQn);               }
__attribute__((weak)) void SPI3_IRQHandler               (void)  { DebugTrap(SPI3_IRQn);               }
__attribute__((weak)) void UART4_IRQHandler              (void)  { DebugTrap(UART4_IRQn);              }
__attribute__((weak)) void UART5_IRQHandler              (void)  { DebugTrap(UART5_IRQn);              }
__attribute__((weak)) void TIM6_DAC_IRQHandler           (void)  { DebugTrap(TIM6_DAC_IRQn);           }
__attribute__((weak)) void TIM7_IRQHandler               (void)  { DebugTrap(TIM7_IRQn);               }
__attribute__((weak)) void DMA2_Stream0_IRQHandler       (void)  { DebugTrap(DMA2_Stream0_IRQn);       }
__attribute__((weak)) void DMA2_Stream1_IRQHandler       (void)  { DebugTrap(DMA2_Stream1_IRQn);       }
__attribute__((weak)) void DMA2_Stream2_IRQHandler       (void)  { DebugTrap(DMA2_Stream2_IRQn);       }
__attribute__((weak)) void DMA2_Stream3_IRQHandler       (void)  { DebugTrap(DMA2_Stream3_IRQn);       }
__attribute__((weak)) void DMA2_Stream4_IRQHandler       (void)  { DebugTrap(DMA2_Stream4_IRQn);       }
__attribute__((weak)) void ETH_IRQHandler                (void)  { DebugTrap(ETH_IRQn);                }
__attribute__((weak)) void ETH_WKUP_IRQHandler           (void)  { DebugTrap(ETH_WKUP_IRQn);           }
__attribute__((weak)) void CAN2_TX_IRQHandler            (void)  { DebugTrap(CAN2_TX_IRQn);            }
__attribute__((weak)) void CAN2_RX0_IRQHandler           (void)  { DebugTrap(CAN2_RX0_IRQn);           }
__attribute__((weak)) void CAN2_RX1_IRQHandler           (void)  { DebugTrap(CAN2_RX1_IRQn);           }
__attribute__((weak)) void CAN2_SCE_IRQHandler           (void)  { DebugTrap(CAN2_SCE_IRQn);           }
__attribute__((weak)) void OTG_FS_IRQHandler             (void)  { DebugTrap(OTG_FS_IRQn);             }
__attribute__((weak)) void DMA2_Stream5_IRQHandler       (void)  { DebugTrap(DMA2_Stream5_IRQn);       }
__attribute__((weak)) void DMA2_Stream6_IRQHandler       (void)  { DebugTrap(DMA2_Stream6_IRQn);       }
__attribute__((weak)) void DMA2_Stream7_IRQHandler       (void)  { DebugTrap(DMA2_Stream7_IRQn);       }
__attribute__((weak)) void USART6_IRQHandler             (void)  { DebugTrap(USART6_IRQn);             }
__attribute__((weak)) void I2C3_EV_IRQHandler            (void)  { DebugTrap(I2C3_EV_IRQn);            }
__attribute__((weak)) void I2C3_ER_IRQHandler            (void)  { DebugTrap(I2C3_ER_IRQn);            }
__attribute__((weak)) void OTG_HS_EP1_OUT_IRQHandler     (void)  { DebugTrap(OTG_HS_EP1_OUT_IRQn);     }
__attribute__((weak)) void OTG_HS_EP1_IN_IRQHandler      (void)  { DebugTrap(OTG_HS_EP1_IN_IRQn);      }
__attribute__((weak)) void OTG_HS_WKUP_IRQHandler        (void)  { DebugTrap(OTG_HS_WKUP_IRQn);        }
__attribute__((weak)) void OTG_HS_IRQHandler             (void)  { DebugTrap(OTG_HS_IRQn);             }
__attribute__((weak)) void DCMI_IRQHandler               (void)  { DebugTrap(DCMI_IRQn);               }
__attribute__((weak)) void HASH_RNG_IRQHandler           (void)  { DebugTrap(HASH_RNG_IRQn);           }
__attribute__((weak)) void FPU_IRQHandler                (void)  { DebugTrap(FPU_IRQn);                }
__attribute__((weak)) void UART7_IRQHandler              (void)  { DebugTrap(UART7_IRQn);              }
__attribute__((weak)) void UART8_IRQHandler              (void)  { DebugTrap(UART8_IRQn);              }
__attribute__((weak)) void SPI4_IRQHandler               (void)  { DebugTrap(SPI4_IRQn);               }
__attribute__((weak)) void SPI5_IRQHandler               (void)  { DebugTrap(SPI5_IRQn);               }
__attribute__((weak)) void SPI6_IRQHandler               (void)  { DebugTrap(SPI6_IRQn);               }
__attribute__((weak)) void SAI1_IRQHandler               (void)  { DebugTrap(SAI1_IRQn);               }
__attribute__((weak)) void LTDC_IRQHandler               (void)  { DebugTrap(LTDC_IRQn);               }
__attribute__((weak)) void LTDC_ER_IRQHandler            (void)  { DebugTrap(LTDC_ER_IRQn);            }
__attribute__((weak)) void DMA2D_IRQHandler              (void)  { DebugTrap(DMA2D_IRQn);              }


*/
//-------------------------------------------------------------------------------------------------

} // extern "C"

//-------------------------------------------------------------------------------------------------
