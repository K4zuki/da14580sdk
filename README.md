# da14580sdk
DA14580 C++ porting to use Dialog Semiconductor DA14580/1/2/3 peripheral.
 **Requires DA1458x SDK 5**

## Sample
```{.c++}
#include "da14580.h"
extern void system_init(void);

DigitalOut LED(P1_0);
Serial pc(P0_0, P0_1);
void main(void){
    system_init();
    pc.baud(57600);

    while(1){
        LED = 1;
        wait_ms(500);
        LED = 0;
        wait_ms(500);
    }
}
```

## Available Classes
### wait(), wait_ms(), wait_us()
### DigitalIn
    DigitalIn(PinName pin);
    DigitalIn(PinName pin, PinMode mode);

### DigitalOut
    DigitalOut(PinName pin);
    DigitalOut(PinName pin, int state);

### DigitalInOut
    DigitalInOut(PinName pin);
    DigitalInOut( PinName pin, PinDirection direction,
                  PinMode mode, int value);
### Serial(\*)
    Serial(PinName tx, PinName rx);

### SPI
    SPI(PinName mosi_pin, PinName miso_pin,
        PinName sclk_pin);
