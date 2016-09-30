/*
MIT License
see LICENSE file
*/

#include "myserial.h"

Serial::Serial(PinName tx, PinName rx) {
    _txport = (GPIO_PORT)(tx >> 8);
    _txpin  = (GPIO_PIN )(tx & 0xFF);
    _rxport = (GPIO_PORT)(rx >> 8);
    _rxpin  = (GPIO_PIN )(rx & 0xFF);

    GPIO_ConfigurePin(_txport, _txpin, OUTPUT, PID_UART2_TX, false);
    GPIO_ConfigurePin(_rxport, _rxpin, INPUT,  PID_UART2_RX, false);

    _baudrate = 57600;
    SetBits16(PMU_CTRL_REG, PERIPH_SLEEP, 0);   // exit peripheral power down
    SetBits16(CLK_PER_REG, UART2_ENABLE, 1);    // enable  clock for UART 2
    uart2_init(_baudrate, 8);
    baud(_baudrate);
    format(8, None, 1);
}

Serial::~Serial() {
    GPIO_ConfigurePin(_txport, _txpin, INPUT, PID_GPIO, false);
    GPIO_ConfigurePin(_rxport, _rxpin, INPUT, PID_GPIO, false);
}

void Serial::format(int bits = 8, Parity parity = None, int stop_bits = 1) {
    _mode = 0;

    switch ( bits ) {
        case 5: {  _mode  |= 0x00; break; }
        case 6: {  _mode  |= 0x01; break; }
        case 7: {  _mode  |= 0x02; break; }
        case 8: {  _mode  |= 0x03; break; }
        default: { _mode  |= 0x03; break; }
    }
    switch ((int)parity)  {
        case (int)None: { _mode |= 0x00; break; }
        case (int)Odd:  { _mode |= 0x08; break; }
        case (int)Even: { _mode |= 0x18; break; }
        default:        { _mode |= 0x00; break; }
    }
    switch(stop_bits) {
        case 1:   { _mode  |= 0x00; break; }
        case 2:   { _mode  |= 0x04; break; }
        default:  { _mode  |= 0x00; break; }
    }
    // ACCESS DIVISORLATCH REGISTER FOR BAUDRATE 115200,
    // REGISTER UART_DLH/DLL_REG IF UART2_LCR_REG.DLAB=1
    SetBits16(UART2_LCR_REG, UART_DLAB, 1);

    // NO PARITY, 1 STOP BIT, 8 DATA LENGTH AND
    SetWord16(UART2_LCR_REG, _mode);

    // ENABLE TX INTERRUPTS, REGISTER IER IF UART2_LCR_REG.DLAB=0
    SetBits16(UART2_LCR_REG, UART_DLAB, 0);
}

void Serial::baud(int baudrate )  {
    _baudr = 0;
    _baudrate = baudrate;
    switch(_baudrate) {
        case 115200:  { _baudr = UART_BAUDRATE_115K2;  break; }
        case 57600:   { _baudr = UART_BAUDRATE_57K6;   break; }
        case 38400:   { _baudr = UART_BAUDRATE_38K4;   break; }
        case 28800:   { _baudr = UART_BAUDRATE_28K8;   break; }
        case 19200:   { _baudr = UART_BAUDRATE_19K2;   break; }
        case 9600:    { _baudr = UART_BAUDRATE_9K6;    break; }
        case 2400:    { _baudr = UART_BAUDRATE_2K4;    break; }
        // default:{     _baudr = 400;   break; }
        default:      { _baudr = UART_BAUDRATE_57K6;   break; }
    }

    // ACCESS DIVISORLATCH REGISTER FOR BAUDRATE 115200,
    // REGISTER UART_DLH/DLL_REG IF UART2_LCR_REG.DLAB=1
    SetBits16(UART2_LCR_REG, UART_DLAB, 1);
    SetWord16(UART2_IER_DLH_REG, 0);  // for serial clk 16MHz baudrate 115200
    SetWord16(UART2_IER_DLH_REG, ((_baudr & 0xFF00) >> 8));
    // set baudrate ~115200  = serial_clk/(16*9)
    SetWord16(UART2_RBR_THR_DLL_REG, (uint16_t)(_baudr & 0xFF));

    // ENABLE TX INTERRUPTS, REGISTER IER IF UART2_LCR_REG.DLAB=0
    SetBits16(UART2_LCR_REG, UART_DLAB, 0);
}

    /** Determine if there is a character available to read
     *
     *  @returns
     *    1 if there is a character available to read,
     *    0 otherwise
     */
// int Serial::readable(){
//
// }

    /** Determine if there is space available to write a character
     *
     *  @returns
     *    1 if there is space to write a character,
     *    0 otherwise
     */
// int Serial::writeable(){
//     int localVal = GetBits16(UART2_USR_REG, UART_TFNF);
//     return localVal;
// }
    // REG_PL_WR(UART2_THR_ADDR, (uint32_t)txdata << 0);
