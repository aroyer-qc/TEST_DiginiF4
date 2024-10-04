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

} // extern "C"

//-------------------------------------------------------------------------------------------------
