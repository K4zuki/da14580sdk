/*
MIT License
see LICENSE file
*/

#ifndef _MY_SPI_H_
#define _MY_SPI_H_

#include "spi.h"
#include "pin_names.h"
#include "mygpio.h"

class SPI
{
private:

    GPIO_PORT _port;
    GPIO_PIN  _pin;

    int port;
    SPI_Word_Mode_t bits;
    int mode;
    SPI_Polarity_Mode_t polarity; // idle clock value
    SPI_PHA_Mode_t phase; // 0=sample on leading (first) clock edge, 1=trailing (second)
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
