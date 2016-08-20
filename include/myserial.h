/*
MIT License
see LICENSE file
*/

/** myserial.h
*/
#ifndef _MY_SERIAL_H_
#define _MY_SERIAL_H_

#include "uart.h"       // uart definition
#include "myuart.h"
#include "pin_names.h"

class Serial{
public:
    Serial(PinName tx, PinName rx);
    ~Serial();

  /** Set the baud rate of the serial port
   *
   *  @param baudrate The baudrate of the serial port (default = 9600).
   */
   void baud(int baudrate);

    enum Parity {
        None = 0,
        Odd,
        Even,
        Forced1,
        Forced0
    };

    enum IrqType {
        RxIrq = 0,
        TxIrq
    };

    /** Set the transmission format used by the serial port
     *
     *  @param bits The number of bits in a word (5-8; default = 8)
     *  @param parity The parity used (SerialBase::None, SerialBase::Odd,
     *                SerialBase::Even, SerialBase::Forced1,
     *                SerialBase::Forced0; default = SerialBase::None)
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


private:

    GPIO_PORT _txport;
    GPIO_PIN _txpin;
    GPIO_PORT _rxport;
    GPIO_PIN _rxpin;

    uint8_t _mode;
    uint16_t _baudr;
    int _baudrate;
};

#endif //_MY_SERIAL_H_
