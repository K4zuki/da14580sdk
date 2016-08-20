/*
MIT License
see LICENSE file
*/

#include "mywait.h"

/** Initialize the ticker
 *
 */
void us_ticker_init(void);

/** Read the current counter
 *
 * @return The current timer's counter value in microseconds
 */
uint32_t us_ticker_read(void);
int us_ticker_inited = 0;

void wait_us( uint32_t us ){
    uint32_t start = us_ticker_read();
    while (( start - us_ticker_read() ) < (uint32_t)us);
}

void wait_ms( uint32_t ms ){
    wait_us(ms * 1000);
}

void wait( float sec ){
    wait_us(sec * 1000000.0f);
}

void us_ticker_init(void) {
    if (us_ticker_inited) return;
    us_ticker_inited = 1;
    systick_start(0xFFFFFFFF, false);
}

uint32_t us_ticker_read() {
    if (!us_ticker_inited)
        us_ticker_init();

    return systick_value();
}
