# da14580sdk
DA14580 C++ porting to use Dialog Semiconductor DA14580/1/2/3 peripheral.

**Requires DA1458x SDK 5**

mbed<sup>TM</sup> style porting

## Sample
```{.c++}
#include "da14580sdk.h"
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
```{.c++}
void wait_us( uint32_t us );
void wait_ms( uint32_t ms );
void wait( float sec );
```
### DigitalIn
```{.c++}
DigitalIn(PinName pin);
DigitalIn(PinName pin, PinMode mode);
```
### DigitalOut
```{.c++}
DigitalOut(PinName pin);
DigitalOut(PinName pin, int state);
```
### DigitalInOut
```{.c++}
DigitalInOut(PinName pin);
DigitalInOut( PinName pin, PinDirection direction,
              PinMode mode, int value);
```
### Serial(\*)
```{.c++}
Serial(PinName tx, PinName rx);
```
<sub>(\*): limited implementation</sub>

### SPI
```{.c++}
SPI(PinName mosi_pin, PinName miso_pin,
    PinName sclk_pin);
```
