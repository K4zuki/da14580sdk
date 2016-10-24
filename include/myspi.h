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

#ifndef _MY_SPI_H_  // NOLINT
#define _MY_SPI_H_

#include "mygpio.h"     // NOLINT
#include "pin_names.h"  // NOLINT
#include "spi.h"        // NOLINT

class SPI {
 private:
  GPIO_PORT _port;
  GPIO_PIN _pin;

  int port;
  SPI_Word_Mode_t bits;
  int mode;
  SPI_Polarity_Mode_t polarity;  // idle clock value
  SPI_PHA_Mode_t
      phase;  // 0=sample on leading (first) clock edge, 1=trailing (second)
  SPI_XTAL_Freq_t freq;

 public:
  /** Create SWSPI object
                                                                                *
   *  @param mosi_pin
   *  @param miso_pin
   *  @param sclk_pin
   */
  SPI(PinName mosi_pin, PinName miso_pin, PinName sclk_pin);

  /** Destructor */
  ~SPI();

  /** Specify SPI format
   *
   *  @param bits  8, 9, 16 or 32
   *  @param mode  0, 1, 2, or 3 phase (bit1) and idle clock (bit0)
   */
  void format(int bits, int mode = 0);

  /** Specify SPI clock frequency
   *
   *  @param hz  frequency (optional, defaults to 10000000)
   */
  void frequency(int hz = 10000000);

  /** Write data and read result
   *
   *  @param value  data to write (see format for bit size)
   *  returns value read from device
   */
  int write(int value);
};
#endif
