/*
MIT License
see LICENSE file
*/

#include "mygpio.h"

/** DigitalIn Class */
DigitalIn::DigitalIn(PinName pin){
    _port = (GPIO_PORT)(pin >> 8);
    _pin = (GPIO_PIN)(pin & 0xFF);

    GPIO_ConfigurePin(_port, _pin, INPUT, PID_GPIO, false);
}

DigitalIn::~DigitalIn(){
}

DigitalIn::DigitalIn(PinName pin, PinMode mode){
    _port = (GPIO_PORT)(pin >> 8);
    _pin = (GPIO_PIN)(pin & 0xFF);
    _mode = (GPIO_PUPD)mode;

    GPIO_ConfigurePin(_port, _pin, _mode, PID_GPIO, false);
}

int DigitalIn::read(){
    return GPIO_GetPinStatus(_port, _pin);
}

void DigitalIn::mode(PinMode mode){
    _mode = (GPIO_PUPD)mode;
    GPIO_ConfigurePin(_port, _pin, _mode, PID_GPIO, false);
}

/** DigitalOut Class */
DigitalOut::DigitalOut(PinName pin){
    _port = (GPIO_PORT)(pin >> 8);
    _pin = (GPIO_PIN)(pin & 0xFF);
    GPIO_ConfigurePin(_port, _pin, OUTPUT, PID_GPIO, false);
}

DigitalOut::DigitalOut(PinName pin, int value){
    _port = (GPIO_PORT)(pin >> 8);
    _pin = (GPIO_PIN)(pin & 0xFF);

    GPIO_ConfigurePin(_port, _pin, OUTPUT, PID_GPIO, value? 1 : 0);
}

DigitalOut::~DigitalOut(){
}

void DigitalOut::write(int value){
    GPIO_ConfigurePin(_port, _pin, OUTPUT, PID_GPIO, value? 1 : 0);
}

int DigitalOut::read(){
    return GPIO_GetPinStatus(_port, _pin);
}
// int DigitalOut::is_connected (){}

/** DigitalInOut Class */
/** A digital input/output, used for setting or reading a bi-directional pin
 */
    DigitalInOut::DigitalInOut(PinName pin){
        _port = (GPIO_PORT)(pin >> 8);
        _pin = (GPIO_PIN)(pin & 0xFF);

        GPIO_ConfigurePin(_port, _pin, INPUT, PID_GPIO, false);
    }

    /** Create a DigitalInOut connected to the specified pin
     *
     *  @param pin DigitalInOut pin to connect to
     *  @param direction the initial direction of the pin
     *  @param mode the initial mode of the pin
     *  @param value the initial value of the pin if is an output
     */
    DigitalInOut::DigitalInOut(PinName pin, PinDirection direction, PinMode mode, int value) {
        _port = (GPIO_PORT)(pin >> 8);
        _pin = (GPIO_PIN)(pin & 0xFF);
        _mode = (GPIO_PUPD)mode;
        _direction = (GPIO_PUPD)direction;

        if(_direction == PIN_OUTPUT){
            GPIO_ConfigurePin(_port, _pin, _direction, PID_GPIO, value? 1 : 0);
        }else{
            GPIO_ConfigurePin(_port, _pin, _mode, PID_GPIO, value? 1 : 0);
        }

        // GPIO_ConfigurePin(_port, _pin, _mode, PID_GPIO, false);
        // gpio_init_inout(&gpio, pin, direction, mode, value);
    }

    /** Set the output, specified as 0 or 1 (int)
     *
     *  @param value An integer specifying the pin output value,
     *      0 for logical 0, 1 (or any other non-zero value) for logical 1
     */
    void DigitalInOut::write(int value) {
        _direction = OUTPUT;
        GPIO_ConfigurePin(_port, _pin, _direction, PID_GPIO, value? 1 : 0);
    }

    /** Return the output setting, represented as 0 or 1 (int)
     *
     *  @returns
     *    an integer representing the output setting of the pin if it is an output,
     *    or read the input if set as an input
     */
    int DigitalInOut::read() {
        return GPIO_GetPinStatus(_port, _pin);
    }

    /** Set as an output
     */
    void DigitalInOut::output() {
        int _read = read();
        _direction = OUTPUT;
        GPIO_ConfigurePin(_port, _pin, _direction, PID_GPIO, _read);
        // gpio_dir(&gpio, PIN_OUTPUT);
    }

    /** Set as an input
     */
    void DigitalInOut::input() {
        int _read = read();
        _direction = INPUT;
        GPIO_ConfigurePin(_port, _pin, _direction, PID_GPIO, _read);
    }

    /** Set the input pin mode
     *
     *  @param mode PullUp, PullDown, PullNone, OpenDrain
     */
    void DigitalInOut::mode(PinMode pull) {
        int _read = read();
        _direction = INPUT;
        _mode = (GPIO_PUPD)pull;
        GPIO_ConfigurePin(_port, _pin, _mode, PID_GPIO, _read);
        // gpio_mode(&gpio, pull);
    }

    /** Return the output setting, represented as 0 or 1 (int)
     *
     *  @returns
     *    Non zero value if pin is connected to uc GPIO
     *    0 if gpio object was initialized with NC
     */
    // int is_connected() {
    //     return gpio_is_connected(&gpio);
    // }
