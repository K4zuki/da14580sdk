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

/** myserial.h
*/
#ifndef _MY_SERIAL_H_  // NOLINT
#define _MY_SERIAL_H_

#include "myuart.h"     //NOLINT
#include "pin_names.h"  // NOLINT
#include "uart.h"       // NOLINT

class Serial {
 public:
  Serial(PinName tx, PinName rx);
  ~Serial();

  /** Set the baud rate of the serial port
   *
   *  @param baudrate The baudrate of the serial port (default = 9600).
   */
  void baud(int baudrate);

  enum Parity { None = 0, Odd, Even, Forced1, Forced0 };

  enum IrqType { RxIrq = 0, TxIrq };

  /** Set the transmission format used by the serial port
   *
   *  @param bits The number of bits in a word (5-8; default = 8)
   *  @param parity The parity used (SerialBase::None, SerialBase::Odd,
   * SerialBase::Even, SerialBase::Forced1, SerialBase::Forced0; default =
   * SerialBase::None)
   *  @param stop The number of stop bits (1 or 2; default = 1)
   */
  void format(int bits, Parity parity, int stop_bits);

  /** Determine if there is a character available to read
   *
   *  @returns
   *    1 if there is a character available to read,
   *    0 otherwise
   */
  // int readable();

  /** Determine if there is space available to write a character
   *
   *  @returns
   *    1 if there is space to write a character,
   *    0 otherwise
   */
  // int writeable();UART2_USR_REG
  // int write (const uint8_t *buffer,
  //           int length, const event_callback_t &callback, int
  //           event=SERIAL_EVENT_TX_COMPLETE)
  /** Attach a function to call whenever a serial interrupt is generated
   *
   *  @param fptr A pointer to a void function, or 0 to set as none
   *  @param type Which serial interrupt to attach the member function to
   * (Seriall::RxIrq for receive, TxIrq for transmit buffer empty)
   */
  //    void attach(void (*fptr)(void), IrqType type=RxIrq);

  /** Attach a member function to call whenever a serial interrupt is generated
   *
   *  @param tptr pointer to the object to call the member function on
   *  @param mptr pointer to the member function to be called
   *  @param type Which serial interrupt to attach the member function to
   * (Seriall::RxIrq for receive, TxIrq for transmit buffer empty)
   */
  //    template<typename T>
  //    void attach(T* tptr, void (T::*mptr)(void), IrqType type=RxIrq) {
  //        if((mptr != NULL) && (tptr != NULL)) {
  //            _irq[type].attach(tptr, mptr);
  //            serial_irq_set(&_serial, (SerialIrq)type, 1);
  //        }
  //    }

  /** Generate a break condition on the serial line
   */
  //    void send_break();

  //    static void _irq_handler(uint32_t id, SerialIrq irq_type);

 private:
  // void _enablefifo();
  // int _rxfifo();
  // int _txfifo();
  //  uint8_t _baudgen();
  GPIO_PORT _txport;
  GPIO_PIN _txpin;
  GPIO_PORT _rxport;
  GPIO_PIN _rxpin;

  uint8_t _mode;
  uint16_t _baudr;
  int _baudrate;
};

#endif  //_MY_SERIAL_H_ //NOLINT
