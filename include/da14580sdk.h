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

/* std lib*/
#include <stdio.h>

/* DA1458x SDK5 */
#include "common_uart.h"  // NOLINT
#include "global_io.h"    // NOLINT

/* da14580 c++ porting lib */
#include "gpio.h"      // NOLINT
#include "mygpio.h"    // NOLINT
#include "myserial.h"  // NOLINT
#include "mywait.h"    // NOLINT

void system_init(void) {
  SetBits16(GP_CONTROL_REG, EM_MAP, 23);

  // SysRAM ret
  SetBits16(SYS_CTRL_REG, RET_SYSRAM, 1);

  // set clocks (hclk and pclk ) 16MHz
  SetWord16(CLK_AMBA_REG, 0x00);
  // stop watch dog
  SetWord16(SET_FREEZE_REG, FRZ_WDOG);
  // open pads
  SetBits16(SYS_CTRL_REG, PAD_LATCH_EN, 1);
  // open debugger
  SetBits16(SYS_CTRL_REG, DEBUGGER_ENABLE, 1);
  // exit peripheral power down
  SetBits16(PMU_CTRL_REG, PERIPH_SLEEP, 0);

  // Power up peripherals' power domain
  SetBits16(PMU_CTRL_REG, PERIPH_SLEEP, 0);
  while (!(GetWord16(SYS_STAT_REG) & PER_IS_UP)) {
  }

  // enable  clock for UART 2
  SetBits16(CLK_PER_REG, UART2_ENABLE, 1);
}
