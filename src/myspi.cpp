/*
MIT License
see LICENSE file
*/

#include "myspi.h"

SPI::SPI(PinName mosi_pin, PinName miso_pin, PinName sclk_pin){
    SetBits16(PMU_CTRL_REG, PERIPH_SLEEP,0);       // exit peripheral power down

    // GPIO_ConfigurePin( SPI_GPIO_PORT, SPI_CS_PIN,  OUTPUT, PID_SPI_EN, true );
    _port = (GPIO_PORT)(mosi_pin >> 8);
    _pin =  (GPIO_PIN) (mosi_pin & 0xFF);
    GPIO_ConfigurePin( _port, _pin,  OUTPUT, PID_SPI_DO, false );

    _port = (GPIO_PORT)(miso_pin >> 8);
    _pin =  (GPIO_PIN) (miso_pin & 0xFF);
    GPIO_ConfigurePin( _port, _pin,  INPUT, PID_SPI_DI, false );

    _port = (GPIO_PORT)(sclk_pin >> 8);
    _pin =  (GPIO_PIN) (sclk_pin & 0xFF);
    GPIO_ConfigurePin( _port, _pin, OUTPUT, PID_SPI_CLK, false );

    /* initialize SPI */
    // enable clock for SPI
    SetBits16(CLK_PER_REG, SPI_ENABLE, 1);
    // close SPI block, if opened
    SetBits16(SPI_CTRL_REG, SPI_ON, 0);
    // select role (master/slave)
    SetBits16(SPI_CTRL_REG, SPI_SMN, SPI_ROLE_MASTER);
    // enable/disable SPI interrupt to the NVIC
    SetBits16(SPI_CTRL_REG, SPI_MINT, SPI_MINT_DISABLE);
     // SPI block clock divider
    SetBits16(SPI_CTRL_REG, SPI_CLK, SPI_XTAL_DIV_2);
    // set SPI bitmode
    SetBits16(SPI_CTRL_REG, SPI_WORD, SPI_MODE_8BIT);
    // select SPI clock idle polarity
    SetBits16(SPI_CTRL_REG, SPI_POL, SPI_CLK_IDLE_POL_LOW);
    // select SPI sampling edge selection  (pha_mode - refer to datasheet p.53-54)
    SetBits16(SPI_CTRL_REG, SPI_PHA, SPI_PHA_MODE_0);
    // enable SPI block
    SetBits16(SPI_CTRL_REG, SPI_ON, 1);
}

/** Destructor */
SPI::~SPI(){

}

/** Specify SPI format
 *
 *  @param bits  8, 9, 16 or 32
 *  @param mode  0, 1, 2, or 3 phase (bit1) and idle clock (bit0)
 */
void SPI::format(int bits, int mode){
    // // close SPI block, if opened
    // SetBits16(SPI_CTRL_REG, SPI_ON, 0);
    switch(bits){
        case 8:
            this->bits = SPI_MODE_8BIT;
            break;
        case 9:
            this->bits = SPI_MODE_9BIT;
            break;
        case 16:
            this->bits = SPI_MODE_16BIT;
            break;
        case 32:
            this->bits = SPI_MODE_32BIT;
            break;
        default:
            this->bits = SPI_MODE_8BIT;
            break;
    }
    // set SPI bitmode
    SetBits16(SPI_CTRL_REG, SPI_WORD, this->bits);

    switch(mode){
        case 0:
            this->phase = SPI_PHA_MODE_0;
            this->polarity = SPI_CLK_IDLE_POL_LOW;
            break;
        case 1:
            this->phase = SPI_PHA_MODE_0;
            this->polarity = SPI_CLK_IDLE_POL_HIGH;
            break;
        case 2:
            this->phase = SPI_PHA_MODE_1;
            this->polarity = SPI_CLK_IDLE_POL_LOW;
            break;
        case 3:
            this->phase = SPI_PHA_MODE_1;
            this->polarity = SPI_CLK_IDLE_POL_HIGH;
            break;
        default:
            this->phase = SPI_PHA_MODE_0;
            this->polarity = SPI_CLK_IDLE_POL_LOW;
            break;
    }
    // select SPI sampling edge selection  (pha_mode - refer to datasheet p.53-54)
    SetBits16(SPI_CTRL_REG, SPI_PHA, this->phase);
    // select SPI clock idle polarity
    SetBits16(SPI_CTRL_REG, SPI_POL, this->polarity);
    // enable SPI block
    SetBits16(SPI_CTRL_REG, SPI_ON, 1);

}

/** Specify SPI clock frequency
 *
 *  @param hz  frequency (optional, defaults to 10000000)
 */
void SPI::frequency(int hz){
    // // close SPI block, if opened
    // SetBits16(SPI_CTRL_REG, SPI_ON, 0);
    if (hz <= 1000000){
        this->freq = SPI_XTAL_DIV_14;
    }else if(hz <= 2000000){
        this->freq = SPI_XTAL_DIV_8;
    }else if(hz <= 4000000){
        this->freq = SPI_XTAL_DIV_4;
    }else{
        this->freq = SPI_XTAL_DIV_2;
    }
     // SPI block clock divider
    SetBits16(SPI_CTRL_REG, SPI_CLK, this->freq);
    // enable SPI block
    SetBits16(SPI_CTRL_REG, SPI_ON, 1);
}

/** Write data and read result
 *
 *  @param value  data to write (see format for bit size)
 *  returns value read from device
 */
int SPI::write(int value){
    uint32_t read = 0;
    switch(this->bits){
        case SPI_MODE_8BIT:
            break;
        case SPI_MODE_9BIT:
            SetWord16(SPI_RX_TX_REG1, (uint16_t)(value >> 16));
            break;
        case SPI_MODE_16BIT:
            break;
        case SPI_MODE_32BIT:
            SetWord16(SPI_RX_TX_REG1, (uint16_t)(value >> 16));
            break;
    }
    // write (low part of) dataToSend
    SetWord16(SPI_RX_TX_REG0, (uint16_t)value);
    // polling to wait for spi transmission
    do{
    } while (GetBits16(SPI_CTRL_REG, SPI_INT_BIT) == 0);
    // clear pending flag
    SetWord16(SPI_CLEAR_INT_REG, 0x01);
    switch(this->bits){
        case SPI_MODE_8BIT:
            break;
        case SPI_MODE_9BIT:
            // read high part of data from spi slave
            read = GetWord16(SPI_RX_TX_REG1) << 16;
            break;
        case SPI_MODE_16BIT:
            break;
        case SPI_MODE_32BIT:
            // read high part of data from spi slave
            read = GetWord16(SPI_RX_TX_REG1) << 16;
            break;
    }
    //read (low part of) data from spi slave
    read |= GetWord16(SPI_RX_TX_REG0);

    return (int)read;
}
/*
uint32_t spi_access(uint32_t dataToSend)
{
uint32_t dataRead = 0;
  uint16_t bitmode = 0;

 bitmode = GetBits16(SPI_CTRL_REG, SPI_WORD);      // get SPI word mode

if (bitmode > SPI_MODE_16BIT)              // check if bitmode is set in 9-bit or 32-bit
{
  SetWord16(SPI_RX_TX_REG1, (uint16_t)(dataToSend >> 16));  // write high part of dataToSend
}

SetWord16(SPI_RX_TX_REG0, (uint16_t)dataToSend);    // write (low part of) dataToSend

 do
{
} while (GetBits16(SPI_CTRL_REG, SPI_INT_BIT) == 0);  // polling to wait for spi transmission

SetWord16(SPI_CLEAR_INT_REG, 0x01);            // clear pending flag

// Read from Registers
if (bitmode > SPI_MODE_16BIT)              // check if bitmode is set in 9-bit or 32-bit
{
  dataRead = GetWord16(SPI_RX_TX_REG1) << 16;      // read high part of data from spi slave
}

dataRead += GetWord16(SPI_RX_TX_REG0);          //read (low part of) data from spi slave

return dataRead;                    // return data read from spi slave
}

typedef enum SPI_WORD_MODES{
SPI_MODE_8BIT,
SPI_MODE_16BIT,
SPI_MODE_32BIT,
SPI_MODE_9BIT,
}SPI_Word_Mode_t;

typedef enum SPI_ROLES{
SPI_ROLE_MASTER,
SPI_ROLE_SLAVE,
}SPI_Role_t;

typedef enum SPI_POL_MODES{
SPI_CLK_IDLE_POL_LOW,
SPI_CLK_IDLE_POL_HIGH,
}SPI_Polarity_Mode_t;

typedef enum SPI_PHA_MODES{
SPI_PHA_MODE_0,
SPI_PHA_MODE_1,
}SPI_PHA_Mode_t;

typedef enum SPI_MINT_MODES{
SPI_MINT_DISABLE,
SPI_MINT_ENABLE,
}SPI_MINT_Mode_t;

typedef enum SPI_FREQ_MODES{
SPI_XTAL_DIV_8,
SPI_XTAL_DIV_4,
SPI_XTAL_DIV_2,
SPI_XTAL_DIV_14,
}SPI_XTAL_Freq_t;

typedef struct
{
GPIO_PORT port;
GPIO_PIN pin;
}SPI_Pad_t;

SWSPI::SWSPI(PinName mosi_pin, PinName miso_pin, PinName sclk_pin):_fast(false)
{
  mosi = new DigitalOut(mosi_pin);
  miso = new DigitalIn(miso_pin);
  sclk = new DigitalOut(sclk_pin);
  format(8);
  frequency();
}

SWSPI::~SWSPI()
{
  delete mosi;
  delete miso;
  delete sclk;
}

void SWSPI::format(int bits, int mode)
{
  this->bits = bits;
  this->mode = mode;
  polarity = (mode >> 1) & 1;
  phase = mode & 1;
  sclk->write(polarity);
}

void SWSPI::frequency(int hz)
{
  this->freq = hz;
  _fast = (hz >= 1000000) ? true : false;
}

#pragma Otime

int SWSPI::write(int value)
{

  int read = 0;
  if (_fast) {
      read = fast_write(value);
  } else {
      int cnt = 16000000/freq/2;
      for (int bit = bits-1; bit >= 0; --bit) {
          mosi->write(((value >> bit) & 0x01) != 0);

          if (phase == 0) {
              if (miso->read())
                  read |= (1 << bit);
          }

          sclk->write(!polarity);

          for(int i=0;i<cnt;i++){;}

          if (phase == 1) {
              if (miso->read())
                  read |= (1 << bit);
          }

          sclk->write(polarity);

          for(int i=0;i<cnt;i++){;}
      }
  }

  return read;
}
*/
