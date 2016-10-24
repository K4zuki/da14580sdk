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

/** pin_names.h
*/
#ifndef _PIN_NAMES_H_  // NOLINT
#define _PIN_NAMES_H_

#include "gpio.h"  // NOLINT

typedef enum {
  P0_0 = (GPIO_PORT_0 << 8) | (GPIO_PIN_0),
  P0_1 = (GPIO_PORT_0 << 8) | (GPIO_PIN_1),
  P0_2 = (GPIO_PORT_0 << 8) | (GPIO_PIN_2),
  P0_3 = (GPIO_PORT_0 << 8) | (GPIO_PIN_3),
  P0_4 = (GPIO_PORT_0 << 8) | (GPIO_PIN_4),
  P0_5 = (GPIO_PORT_0 << 8) | (GPIO_PIN_5),
  P0_6 = (GPIO_PORT_0 << 8) | (GPIO_PIN_6),
  P0_7 = (GPIO_PORT_0 << 8) | (GPIO_PIN_7),

  P1_0 = (GPIO_PORT_1 << 8) | (GPIO_PIN_0),
  P1_1 = (GPIO_PORT_1 << 8) | (GPIO_PIN_1),
  P1_2 = (GPIO_PORT_1 << 8) | (GPIO_PIN_2),
  P1_3 = (GPIO_PORT_1 << 8) | (GPIO_PIN_3),
  P1_4 = (GPIO_PORT_1 << 8) | (GPIO_PIN_4),
  P1_5 = (GPIO_PORT_1 << 8) | (GPIO_PIN_5),

  P2_0 = (GPIO_PORT_2 << 8) | (GPIO_PIN_0),
  P2_1 = (GPIO_PORT_2 << 8) | (GPIO_PIN_1),
  P2_2 = (GPIO_PORT_2 << 8) | (GPIO_PIN_2),
  P2_3 = (GPIO_PORT_2 << 8) | (GPIO_PIN_3),
  P2_4 = (GPIO_PORT_2 << 8) | (GPIO_PIN_4),
  P2_5 = (GPIO_PORT_2 << 8) | (GPIO_PIN_5),
  P2_6 = (GPIO_PORT_2 << 8) | (GPIO_PIN_6),
  P2_7 = (GPIO_PORT_2 << 8) | (GPIO_PIN_7),
  P2_8 = (GPIO_PORT_2 << 8) | (GPIO_PIN_8),
  P2_9 = (GPIO_PORT_2 << 8) | (GPIO_PIN_9),

  P3_0 = (GPIO_PORT_3 << 8) | (GPIO_PIN_0),
  P3_1 = (GPIO_PORT_3 << 8) | (GPIO_PIN_1),
  P3_2 = (GPIO_PORT_3 << 8) | (GPIO_PIN_2),
  P3_3 = (GPIO_PORT_3 << 8) | (GPIO_PIN_3),
  P3_4 = (GPIO_PORT_3 << 8) | (GPIO_PIN_4),
  P3_5 = (GPIO_PORT_3 << 8) | (GPIO_PIN_5),
  P3_6 = (GPIO_PORT_3 << 8) | (GPIO_PIN_6),
  P3_7 = (GPIO_PORT_3 << 8) | (GPIO_PIN_7),
} PinName;

typedef enum {
  PullNone = INPUT,
  PullUp = INPUT_PULLUP,
  PullDown = INPUT_PULLDOWN,
} PinMode;

typedef enum { PIN_INPUT = INPUT, PIN_OUTPUT = OUTPUT } PinDirection;

typedef enum {
  P0_DATA_ = 0x00,       /*  P0 Data input / output register */
  P0_SET_DATA_ = 0x02,   /*  P0 Set  port  pins  register */
  P0_RESET_DATA_ = 0x04, /*  P0 Reset  port  pins  register */
  P00_MODE_ = 0x06,      /*  P00  Mode  Register  */
  P01_MODE_ = 0x08,      /*  P01  Mode  Register  */
  P02_MODE_ = 0x0A,      /*  P02  Mode  Register  */
  P03_MODE_ = 0x0C,      /*  P03  Mode  Register  */
  P04_MODE_ = 0x0E,      /*  P04  Mode  Register  */
  P05_MODE_ = 0x10,      /*  P05  Mode  Register  */
  P06_MODE_ = 0x12,      /*  P06  Mode  Register  */
  P07_MODE_ = 0x14,      /*  P07  Mode  Register  */

  P1_DATA_ = 0x20,       /*  P1 Data input / output register */
  P1_SET_DATA_ = 0x22,   /*  P1 Set  port  pins  register */
  P1_RESET_DATA_ = 0x24, /*  P1 Reset  port  pins  register */
  P10_MODE_ = 0x26,      /*  P10  Mode  Register  */
  P11_MODE_ = 0x28,      /*  P11  Mode  Register  */
  P12_MODE_ = 0x2A,      /*  P12  Mode  Register  */
  P13_MODE_ = 0x2C,      /*  P13  Mode  Register  */
  P14_MODE_ = 0x2E,      /*  P14  Mode  Register  */
  P15_MODE_ = 0x30,      /*  P15  Mode  Register  */

  P2_DATA_ = 0x40,       /* P2 Data input / output register */
  P2_SET_DATA_ = 0x42,   /* P2 Set  port  pins  register */
  P2_RESET_DATA_ = 0x44, /* P2 Reset  port  pins  register */
  P20_MODE_ = 0x46,      /* P20  Mode  Register  */
  P21_MODE_ = 0x48,      /* P21  Mode  Register  */
  P22_MODE_ = 0x4A,      /* P22  Mode  Register  */
  P23_MODE_ = 0x4C,      /* P23  Mode  Register  */
  P24_MODE_ = 0x4E,      /* P24  Mode  Register  */
  P25_MODE_ = 0x50,      /* P25  Mode  Register  */
  P26_MODE_ = 0x52,      /* P26  Mode  Register  */
  P27_MODE_ = 0x54,      /* P27  Mode  Register  */
  P28_MODE_ = 0x56,      /* P28  Mode  Register  */
  P29_MODE_ = 0x58,      /* P29  Mode  Register  */

  P01_PADPWR_CTRL_ = 0x70, /*  Ports  0  and  1  Output  Power
                                           Control  Register  */
  P2_PADPWR_CTRL_ = 0x72,  /*  Port  2  Output  Power  Control
                                           Register      */
  P3_PADPWR_CTRL_ = 0x74,  /*  Port  3  Output  Power  Control
                                           Register      */

  P3_DATA_ = 0x80,       /* P3 Data input / output register */
  P3_SET_DATA_ = 0x82,   /* P3 Set  port  pins  register */
  P3_RESET_DATA_ = 0x84, /* P3 Reset  port  pins  register */
  P30_MODE_ = 0x86,      /* P30  Mode  Register  */
  P31_MODE_ = 0x88,      /* P31  Mode  Register  */
  P32_MODE_ = 0x8A,      /* P32  Mode  Register  */
  P33_MODE_ = 0x8C,      /* P33  Mode  Register  */
  P34_MODE_ = 0x8E,      /* P34  Mode  Register  */
  P35_MODE_ = 0x90,      /* P35  Mode  Register  */
  P36_MODE_ = 0x92,      /* P36  Mode  Register  */
  P37_MODE_ = 0x94,      /* P37  Mode  Register  */
} GPIO_REG;

#define GPIOX_BASE 0x50003000
#define PORT0_BASE 0x50003000
#define PORT1_BASE 0x50003020
#define PORT2_BASE 0x50003040
#define PORT3_BASE 0x50003080

#define P0_DATA_RW          ((uint32_t*) (PORT0_BASE |
                              (uint32_t)P0_DATA_       ))
#define P0_SET_DATA         ((uint32_t*) (PORT0_BASE |
                              (uint32_t)P0_SET_DATA_   ))
#define P0_RESET_DATA       ((uint32_t*) (PORT0_BASE |
                              (uint32_t)P0_RESET_DATA_ ))
#define P00_MODE            ((uint32_t*) (PORT0_BASE |
                              (uint32_t)P00_MODE_      ))
#define P01_MODE            ((uint32_t*) (PORT0_BASE |
                              (uint32_t)P01_MODE_      ))
#define P02_MODE            ((uint32_t*) (PORT0_BASE |
                              (uint32_t)P02_MODE_      ))
#define P03_MODE            ((uint32_t*) (PORT0_BASE |
                              (uint32_t)P03_MODE_      ))
#define P04_MODE            ((uint32_t*) (PORT0_BASE |
                              (uint32_t)P04_MODE_      ))
#define P05_MODE            ((uint32_t*) (PORT0_BASE |
                              (uint32_t)P05_MODE_      ))
#define P06_MODE            ((uint32_t*) (PORT0_BASE |
                              (uint32_t)P06_MODE_      ))
#define P07_MODE            ((uint32_t*) (PORT0_BASE |
                              (uint32_t)P07_MODE_      ))
#define P1_DATA_RW          ((uint32_t*) (PORT1_BASE |
                              (uint32_t)P1_DATA_       ))
#define P1_SET_DATA         ((uint32_t*) (PORT1_BASE |
                              (uint32_t)P1_SET_DATA_   ))
#define P1_RESET_DATA       ((uint32_t*) (PORT1_BASE |
                              (uint32_t)P1_RESET_DATA_ ))
#define P10_MODE            ((uint32_t*) (PORT1_BASE |
                              (uint32_t)P10_MODE_      ))
#define P11_MODE            ((uint32_t*) (PORT1_BASE |
                              (uint32_t)P11_MODE_      ))
#define P12_MODE            ((uint32_t*) (PORT1_BASE |
                              (uint32_t)P12_MODE_      ))
#define P13_MODE            ((uint32_t*) (PORT1_BASE |
                              (uint32_t)P13_MODE_      ))
#define P14_MODE            ((uint32_t*) (PORT1_BASE |
                              (uint32_t)P14_MODE_      ))
#define P15_MODE            ((uint32_t*) (PORT1_BASE |
                              (uint32_t)P15_MODE_      ))
#define P2_DATA_RW          ((uint32_t*) (PORT2_BASE |
                              (uint32_t)P2_DATA_       ))
#define P2_SET_DATA         ((uint32_t*) (PORT2_BASE |
                              (uint32_t)P2_SET_DATA_   ))
#define P2_RESET_DATA       ((uint32_t*) (PORT2_BASE |
                              (uint32_t)P2_RESET_DATA_ ))
#define P20_MODE            ((uint32_t*) (PORT2_BASE |
                              (uint32_t)P20_MODE_      ))
#define P21_MODE            ((uint32_t*) (PORT2_BASE |
                              (uint32_t)P21_MODE_      ))
#define P22_MODE            ((uint32_t*) (PORT2_BASE |
                              (uint32_t)P22_MODE_      ))
#define P23_MODE            ((uint32_t*) (PORT2_BASE |
                              (uint32_t)P23_MODE_      ))
#define P24_MODE            ((uint32_t*) (PORT2_BASE |
                              (uint32_t)P24_MODE_      ))
#define P25_MODE            ((uint32_t*) (PORT2_BASE |
                              (uint32_t)P25_MODE_      ))
#define P26_MODE            ((uint32_t*) (PORT2_BASE |
                              (uint32_t)P26_MODE_      ))
#define P27_MODE            ((uint32_t*) (PORT2_BASE |
                              (uint32_t)P27_MODE_      ))
#define P28_MODE            ((uint32_t*) (PORT2_BASE |
                              (uint32_t)P28_MODE_      ))
#define P29_MODE            ((uint32_t*) (PORT2_BASE |
                              (uint32_t)P29_MODE_      ))
#define P01_PADPWR_CTRL     ((uint32_t*) (GPIO_BASE  |
                              (uint32_t)P01_PADPWR_CTRL))
#define P2_PADPWR_CTRL      ((uint32_t*) (GPIO_BASE  |
                              (uint32_t)P2_PADPWR_CTRL_))
#define P3_PADPWR_CTRL      ((uint32_t*) (GPIO_BASE  |
                              (uint32_t)P3_PADPWR_CTRL_))
#define P3_DATA_RW          ((uint32_t*) (PORT3_BASE |
                              (uint32_t)P3_DATA_       ))
#define P3_SET_DATA         ((uint32_t*) (PORT3_BASE |
                              (uint32_t)P3_SET_DATA_   ))
#define P3_RESET_DATA       ((uint32_t*) (PORT3_BASE |
                              (uint32_t)P3_RESET_DATA_ ))
#define P30_MODE            ((uint32_t*) (PORT3_BASE |
                              (uint32_t)P30_MODE_      ))
#define P31_MODE            ((uint32_t*) (PORT3_BASE |
                              (uint32_t)P31_MODE_      ))
#define P32_MODE            ((uint32_t*) (PORT3_BASE |
                              (uint32_t)P32_MODE_      ))
#define P33_MODE            ((uint32_t*) (PORT3_BASE |
                              (uint32_t)P33_MODE_      ))
#define P34_MODE            ((uint32_t*) (PORT3_BASE |
                              (uint32_t)P34_MODE_      ))
#define P35_MODE            ((uint32_t*) (PORT3_BASE |
                              (uint32_t)P35_MODE_      ))
#define P36_MODE            ((uint32_t*) (PORT3_BASE |
                              (uint32_t)P36_MODE_      ))
#define P37_MODE            ((uint32_t*) (PORT3_BASE |
                              (uint32_t)P37_MODE_      ))

#endif  //_PIN_NAMES_H_
