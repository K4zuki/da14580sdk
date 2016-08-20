/*
MIT License
see LICENSE file
*/

/* std lib*/
#include <stdio.h>

/* DA1458x SDK5 */
#include "global_io.h"
#include "common_uart.h"

/* da14580 c++ porting lib */
#include "gpio.h"
#include "mygpio.h"
#include "myserial.h"
#include "mywait.h"

void system_init(void)
{
    SetBits16(GP_CONTROL_REG,EM_MAP,23);

    // SysRAM ret
    SetBits16(SYS_CTRL_REG,RET_SYSRAM,1);

    // set clocks (hclk and pclk ) 16MHz
    SetWord16(CLK_AMBA_REG, 0x00);
    // stop watch dog
    SetWord16(SET_FREEZE_REG,FRZ_WDOG);
    // open pads
    SetBits16(SYS_CTRL_REG,PAD_LATCH_EN,1);
    // open debugger
    SetBits16(SYS_CTRL_REG,DEBUGGER_ENABLE,1);
    // exit peripheral power down
    SetBits16(PMU_CTRL_REG, PERIPH_SLEEP,0);

    // Power up peripherals' power domain
    SetBits16(PMU_CTRL_REG, PERIPH_SLEEP, 0);
    while (!(GetWord16(SYS_STAT_REG) & PER_IS_UP));

    // enable  clock for UART 2
    SetBits16(CLK_PER_REG, UART2_ENABLE, 1);
}
