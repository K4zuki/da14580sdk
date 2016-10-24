/*
Copyright (c) 2016 Kazuki Yamamoto <k.yamamoto.08136891@gmail.com>
Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files
(the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge,
publish, distribute, sublicense, and/or sell copies of the Software,
and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:
The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

/** myuart.h
*/
#ifndef _MY_UART_H_  // NOLINT
#define _MY_UART_H_
typedef enum {
  RBR_THR_DLL_ = 0x00, /* Receive Buffer Register   */
  IER_DLH_ = 0x04,     /* Interrupt Enable Register   */
  IIR_FCR_ = 0x08, /* Interrupt Identification Register/FIFO Control Register */
  LCR_ = 0x0C,     /* Line Control Register   */
  MCR_ = 0x10,     /* Modem Control Register   */
  LSR_ = 0x14,     /* Line Status Register   */
  MSR_ = 0x18,     /* Modem Status Register   */
  SCR_ = 0x1C,     /* Scratchpad Register    */
  LPDLL_ = 0x20,   /* Low Power Divisor Latch Low */
  LPDLH_ = 0x24,   /* Low Power Divisor Latch High */
  SRBR_STHR0_ = 0x30,  /* Shadow Receive/Transmit Buffer Register  */
  SRBR_STHR1_ = 0x34,  /* Shadow Receive/Transmit Buffer Register  */
  SRBR_STHR2_ = 0x38,  /* Shadow Receive/Transmit Buffer Register  */
  SRBR_STHR3_ = 0x3C,  /* Shadow Receive/Transmit Buffer Register  */
  SRBR_STHR4_ = 0x40,  /* Shadow Receive/Transmit Buffer Register  */
  SRBR_STHR5_ = 0x44,  /* Shadow Receive/Transmit Buffer Register  */
  SRBR_STHR6_ = 0x48,  /* Shadow Receive/Transmit Buffer Register  */
  SRBR_STHR7_ = 0x4C,  /* Shadow Receive/Transmit Buffer Register  */
  SRBR_STHR8_ = 0x50,  /* Shadow Receive/Transmit Buffer Register  */
  SRBR_STHR9_ = 0x54,  /* Shadow Receive/Transmit Buffer Register  */
  SRBR_STHR10_ = 0x58, /* Shadow Receive/Transmit Buffer Register  */
  SRBR_STHR11_ = 0x5C, /* Shadow Receive/Transmit Buffer Register  */
  SRBR_STHR12_ = 0x60, /* Shadow Receive/Transmit Buffer Register  */
  SRBR_STHR13_ = 0x64, /* Shadow Receive/Transmit Buffer Register  */
  SRBR_STHR14_ = 0x68, /* Shadow Receive/Transmit Buffer Register  */
  SRBR_STHR15_ = 0x6C, /* Shadow Receive/Transmit Buffer Register  */
  USR_ = 0x7C,         /* UART Status register.   */
  TFL_ = 0x80,         /* Transmit FIFO Level   */
  RFL_ = 0x84,         /* Receive FIFO Level.   */
  SRR_ = 0x88,         /* Software Reset Register.   */
  SRTS_ = 0x8C,        /* Shadow Request to Send  */
  SBCR_ = 0x90,        /* Shadow Break Control Register  */
  SDMAM_ = 0x94,       /* Shadow DMA Mode   */
  SFE_ = 0x98,         /* Shadow FIFO Enable   */
  SRT_ = 0x9C,         /* Shadow RCVR Trigger   */
  STET_ = 0xA0,        /* Shadow TX Empty Trigger  */
  HTX_ = 0xA4,         /* Halt TX    */
  CPR_ = 0xF4,         /* Component Parameter Register   */
  UCV_ = 0xF8,         /* Component Version    */
  CTR_ = 0xFC          /* Component Type Register   */
} UART_REG;

#define UART1_BASE 0x50001000
#define UART2_BASE 0x50001100

#define UART1_RBR_THR_DLL ((uint32_t*)(UART1_BASE | (uint32_t)RBR_THR_DLL_))
#define UART1_IER_DLH ((uint32_t*)(UART1_BASE | (uint32_t)IER_DLH_))
#define UART1_IIR_FCR ((uint32_t*)(UART1_BASE | (uint32_t)IIR_FCR_))
#define UART1_LCR ((uint32_t*)(UART1_BASE | (uint32_t)LCR_))
#define UART1_MCR ((uint32_t*)(UART1_BASE | (uint32_t)MCR_))
#define UART1_LSR ((uint32_t*)(UART1_BASE | (uint32_t)LSR_))
#define UART1_MSR ((uint32_t*)(UART1_BASE | (uint32_t)MSR_))
#define UART1_SCR ((uint32_t*)(UART1_BASE | (uint32_t)SCR_))
#define UART1_LPDLL ((uint32_t*)(UART1_BASE | (uint32_t)LPDLL_))
#define UART1_LPDLH ((uint32_t*)(UART1_BASE | (uint32_t)LPDLH_))
#define UART1_SRBR_STHR0 ((uint32_t*)(UART1_BASE | (uint32_t)SRBR_STHR0_))
#define UART1_SRBR_STHR1 ((uint32_t*)(UART1_BASE | (uint32_t)SRBR_STHR1_))
#define UART1_SRBR_STHR2 ((uint32_t*)(UART1_BASE | (uint32_t)SRBR_STHR2_))
#define UART1_SRBR_STHR3 ((uint32_t*)(UART1_BASE | (uint32_t)SRBR_STHR3_))
#define UART1_SRBR_STHR4 ((uint32_t*)(UART1_BASE | (uint32_t)SRBR_STHR4_))
#define UART1_SRBR_STHR5 ((uint32_t*)(UART1_BASE | (uint32_t)SRBR_STHR5_))
#define UART1_SRBR_STHR6 ((uint32_t*)(UART1_BASE | (uint32_t)SRBR_STHR6_))
#define UART1_SRBR_STHR7 ((uint32_t*)(UART1_BASE | (uint32_t)SRBR_STHR7_))
#define UART1_SRBR_STHR8 ((uint32_t*)(UART1_BASE | (uint32_t)SRBR_STHR8_))
#define UART1_SRBR_STHR9 ((uint32_t*)(UART1_BASE | (uint32_t)SRBR_STHR9_))
#define UART1_SRBR_STHR10 ((uint32_t*)(UART1_BASE | (uint32_t)SRBR_STHR10_))
#define UART1_SRBR_STHR11 ((uint32_t*)(UART1_BASE | (uint32_t)SRBR_STHR11_))
#define UART1_SRBR_STHR12 ((uint32_t*)(UART1_BASE | (uint32_t)SRBR_STHR12_))
#define UART1_SRBR_STHR13 ((uint32_t*)(UART1_BASE | (uint32_t)SRBR_STHR13_))
#define UART1_SRBR_STHR14 ((uint32_t*)(UART1_BASE | (uint32_t)SRBR_STHR14_))
#define UART1_SRBR_STHR15 ((uint32_t*)(UART1_BASE | (uint32_t)SRBR_STHR15_))
#define UART1_USR ((uint32_t*)(UART1_BASE | (uint32_t)USR_))
#define UART1_TFL ((uint32_t*)(UART1_BASE | (uint32_t)TFL_))
#define UART1_RFL ((uint32_t*)(UART1_BASE | (uint32_t)RFL_))
#define UART1_SRR ((uint32_t*)(UART1_BASE | (uint32_t)SRR_))
#define UART1_SRTS ((uint32_t*)(UART1_BASE | (uint32_t)SRTS_))
#define UART1_SBCR ((uint32_t*)(UART1_BASE | (uint32_t)SBCR_))
#define UART1_SDMAM ((uint32_t*)(UART1_BASE | (uint32_t)SDMAM_))
#define UART1_SFE ((uint32_t*)(UART1_BASE | (uint32_t)SFE_))
#define UART1_SRT ((uint32_t*)(UART1_BASE | (uint32_t)SRT_))
#define UART1_STET ((uint32_t*)(UART1_BASE | (uint32_t)STET_))
#define UART1_HTX ((uint32_t*)(UART1_BASE | (uint32_t)HTX_))
#define UART1_CPR ((uint32_t*)(UART1_BASE | (uint32_t)CPR_))
#define UART1_UCV ((uint32_t*)(UART1_BASE | (uint32_t)UCV_))
#define UART1_CTR ((uint32_t*)(UART1_BASE | (uint32_t)CTR_))

#define UART2_RBR_THR_DLL ((uint32_t*)(UART2_BASE | (uint32_t)RBR_THR_DLL_))
#define UART2_IER_DLH ((uint32_t*)(UART2_BASE | (uint32_t)IER_DLH_))
#define UART2_IIR_FCR ((uint32_t*)(UART2_BASE | (uint32_t)IIR_FCR_))
#define UART2_LCR ((uint32_t*)(UART2_BASE | (uint32_t)LCR_))
#define UART2_MCR ((uint32_t*)(UART2_BASE | (uint32_t)MCR_))
#define UART2_LSR ((uint32_t*)(UART2_BASE | (uint32_t)LSR_))
#define UART2_MSR ((uint32_t*)(UART2_BASE | (uint32_t)MSR_))
#define UART2_SCR ((uint32_t*)(UART2_BASE | (uint32_t)SCR_))
#define UART2_LPDLL ((uint32_t*)(UART2_BASE | (uint32_t)LPDLL_))
#define UART2_LPDLH ((uint32_t*)(UART2_BASE | (uint32_t)LPDLH_))
#define UART2_SRBR_STHR0 ((uint32_t*)(UART2_BASE | (uint32_t)SRBR_STHR0_))
#define UART2_SRBR_STHR1 ((uint32_t*)(UART2_BASE | (uint32_t)SRBR_STHR1_))
#define UART2_SRBR_STHR2 ((uint32_t*)(UART2_BASE | (uint32_t)SRBR_STHR2_))
#define UART2_SRBR_STHR3 ((uint32_t*)(UART2_BASE | (uint32_t)SRBR_STHR3_))
#define UART2_SRBR_STHR4 ((uint32_t*)(UART2_BASE | (uint32_t)SRBR_STHR4_))
#define UART2_SRBR_STHR5 ((uint32_t*)(UART2_BASE | (uint32_t)SRBR_STHR5_))
#define UART2_SRBR_STHR6 ((uint32_t*)(UART2_BASE | (uint32_t)SRBR_STHR6_))
#define UART2_SRBR_STHR7 ((uint32_t*)(UART2_BASE | (uint32_t)SRBR_STHR7_))
#define UART2_SRBR_STHR8 ((uint32_t*)(UART2_BASE | (uint32_t)SRBR_STHR8_))
#define UART2_SRBR_STHR9 ((uint32_t*)(UART2_BASE | (uint32_t)SRBR_STHR9_))
#define UART2_SRBR_STHR10 ((uint32_t*)(UART2_BASE | (uint32_t)SRBR_STHR10_))
#define UART2_SRBR_STHR11 ((uint32_t*)(UART2_BASE | (uint32_t)SRBR_STHR11_))
#define UART2_SRBR_STHR12 ((uint32_t*)(UART2_BASE | (uint32_t)SRBR_STHR12_))
#define UART2_SRBR_STHR13 ((uint32_t*)(UART2_BASE | (uint32_t)SRBR_STHR13_))
#define UART2_SRBR_STHR14 ((uint32_t*)(UART2_BASE | (uint32_t)SRBR_STHR14_))
#define UART2_SRBR_STHR15 ((uint32_t*)(UART2_BASE | (uint32_t)SRBR_STHR15_))
#define UART2_USR ((uint32_t*)(UART2_BASE | (uint32_t)USR_))
#define UART2_TFL ((uint32_t*)(UART2_BASE | (uint32_t)TFL_))
#define UART2_RFL ((uint32_t*)(UART2_BASE | (uint32_t)RFL_))
#define UART2_SRR ((uint32_t*)(UART2_BASE | (uint32_t)SRR_))
#define UART2_SRTS ((uint32_t*)(UART2_BASE | (uint32_t)SRTS_))
#define UART2_SBCR ((uint32_t*)(UART2_BASE | (uint32_t)SBCR_))
#define UART2_SDMAM ((uint32_t*)(UART2_BASE | (uint32_t)SDMAM_))
#define UART2_SFE ((uint32_t*)(UART2_BASE | (uint32_t)SFE_))
#define UART2_SRT ((uint32_t*)(UART2_BASE | (uint32_t)SRT_))
#define UART2_STET ((uint32_t*)(UART2_BASE | (uint32_t)STET_))
#define UART2_HTX ((uint32_t*)(UART2_BASE | (uint32_t)HTX_))
#define UART2_CPR ((uint32_t*)(UART2_BASE | (uint32_t)CPR_))
#define UART2_UCV ((uint32_t*)(UART2_BASE | (uint32_t)UCV_))
#define UART2_CTR ((uint32_t*)(UART2_BASE | (uint32_t)CTR_))

#endif  // _MY_UART_H_ //NOLINT
