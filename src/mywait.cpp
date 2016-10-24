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

#include "mywait.h"  //NOLINT
// #include "systick.h"

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

void wait_us(uint32_t us) {
  uint32_t start = us_ticker_read();
  while ((start - us_ticker_read()) < (uint32_t)us) {
  }
}

void wait_ms(uint32_t ms) { wait_us(ms * 1000); }

void wait(float sec) { wait_us(sec * 1000000.0f); }

void us_ticker_init(void) {
  if (us_ticker_inited) return;
  us_ticker_inited = 1;
  systick_start(0xFFFFFFFF, false);
}

uint32_t us_ticker_read() {
  if (!us_ticker_inited) us_ticker_init();

  return systick_value();
}
