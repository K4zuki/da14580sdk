# Based on DA14580 Datasheet Revision 3.3(DA14580_DS_v3.3.pdf)

## Table 47: UART_RBR_THR_DLL_REG (0x50001000) {-}
## Table 105: UART2_RBR_THR_DLL_REG (0x50001100) {-}
### [15..8] {-}
#### Reserved {-}
### [7..0] RBR_THR_DLL [R/W]{-}
#### Receive Buffer Register: Reading while `LCR[7]` = 0 {-}
This register contains the data byte received on the serial input port (`sin`) in UART mode or the serial infrared input (`sir_in`) in infrared mode. The data in this register is valid only if the Data Ready (`DR`) bit in the Line status Register (`LSR`) is set. If FIFOs are disabled (`FCR[0] set to zero`), the data in the RBR must be read before the next data arrives, otherwise it will be overwritten, resulting in an overrun error. If FIFOs are enabled (`FCR[0] set to one`), this register accesses the head of the receive FIFO. If the receive FIFO is full and this register is not read before the next data character arrives, then the data already in the FIFO will be preserved but any incoming data will be lost. An overrun error will also occur.

#### Transmit Holding Register: Writing while `LCR[7]` = 0 {-}
This register contains data to be transmitted on the serial output port (`sout`) in UART mode or the serial infrared output (`sir_out_n`) in infrared mode. Data should only be written to the THR when the THR Empty (`THRE`) bit (`LSR[5]`) is set. If FIFO's are disabled (`FCR[0] set to zero`) and THRE is set, writing a single character to the `THR` clears the `THRE`. Any additional writes to the THR before the `THRE` is set again causes the THR data to be overwritten. If FIFO's are enabled (`FCR[0]` set to one) and `THRE` is set, `x` number of characters of data may be written to the `THR` before the FIFO is full. The number `x` (default=16) is determined by the value of FIFO Depth that you set during configuration. Any attempt to write data when the FIFO is full results in the write data being lost.

#### Divisor Latch (Low): When `LCR[7]` = 1 {-}
This register makes up the lower 8-bits of a 16-bit, read/write, Divisor Latch register that contains the baud rate divisor for the UART. This register may only be accessed when the `DLAB` bit (`LCR[7]`) is set. The output baud rate is equal to the serial clock (`sclk`) frequency divided by sixteen times the value of the baud rate divisor, as follows:

~~~
baud rate = (serial clock freq) / (16 * divisor)
~~~

Note that with the Divisor Latch Registers (`DLL` and `DLH`) set to zero, the baud clock is disabled and no serial communications will occur. Also, once the `DLL` is set, at least 8 clock cycles of the slowest `DW_apb_uart` clock should be allowed to pass before transmitting or receiving data.

## Table 48: UART_IER_DLH_REG (0x50001004) {-}

### [15..8] {-}
#### Reserved {-}
### [7] PTIME_DLH7 [R/W] {-}
#### Interrupt Enable Register: {-}
`PTIME`, Programmable `THRE` Interrupt Mode Enable.
This is used to enable/disable the generation of `THRE` Interrupt.

- 0 = disabled
- 1 = enabled

#### Divisor Latch (High): {-}
Bit[7] of the 8 bit `DLH` register.

### [6..4] {-}
#### Reserved {-}

### [3] EDSSI_DLH3 [R/W] {-}
#### Interrupt Enable Register: {-}
EDSSI, Enable Modem Status Interrupt. This is used to enable/disable the generation of Modem Status Interrupt. This is the fourth highest priority interrupt.

- 0 = disabled
- 1 = enabled

#### Divisor Latch (High): {-}
Bit[3] of the 8 bit `DLH` register

### [2] ELSI_DHL2 [R/W] {-}
#### Interrupt Enable Register: {-}
`ELSI`, Enable Receiver Line Status Interrupt. This is used to enable/disable the generation of Receiver Line Status Interrupt. This is the highest priority interrupt.

- 0 = disabled
- 1 = enabled

#### Divisor Latch (High): {-}
Bit[2] of the 8 bit `DLH` register.

### [1] R/W {-}
#### ETBEI_DLH1 Interrupt Enable Register: {-}
`ETBEI`, Enable Transmit Holding Register Empty Interrupt. This is used to enable/disable the generation of Transmitter Holding Register Empty Interrupt. This is the third highest priority interrupt.

- 0 = disabled
- 1 = enabled

#### Divisor Latch (High): {-}
Bit[1] of the 8 bit `DLH` register.

### [0] ERBFI_DLH0 [R/W] {-}
#### Interrupt Enable Register: {-}
`ERBFI`, Enable Received Data Available Interrupt. This is used to enable/disable the generation of Received Data Available Interrupt and the Character Timeout Interrupt (`if in FIFO mode and FIFO's enabled`). These are the second highest priority interrupts.

- 0 = disabled
- 1 = enabled

#### Divisor Latch (High): {-}
Bit[0] of the 8 bit `DLH` register.

## Table 49: UART_IIR_FCR_REG (0x50001008) {-}
### [15..0] IIR_FCR [R/W] {-}
Interrupt Identification Register, reading this register

FIFO Control Register, writing to this register

#### Interrupt Identification Register: When reading {-}
##### Bits[7..6], FIFO's Enabled (or `FIFOSE`): {-}
This is used to indicate whether the FIFO's are enabled or disabled.

- 00 = disabled
- 11 = enabled

##### Bits[3..0], Interrupt ID (or `IID`): {-}
This indicates the highest priority pending interrupt which can be
one of the following types:

- 0000 = modem status.
- 0001 = no interrupt pending.
- 0010 = THR empty.
- 0100 = received data available.
- 0110 = receiver line status.
- 0111 = busy detect.
- 1100 = character timeout.

#### FIFO Control Register: When Writing {-}
##### Bits[7..6], RCVR Trigger (or `RT`): {-}
This is used to select the trigger level in the receiver FIFO at which the Received Data Available Interrupt will be generated. In auto flow control mode it is used to determine when the `rts_n` signal will be de-asserted. It also determines when the `dma_rx_req_n` signal will be asserted when in certain modes of operation.

The following trigger levels are supported:

- 00 = 1 character in the FIFO
- 01 = FIFO 1/4 full
- 10 = FIFO 1/2 full
- 11 = FIFO 2 less than full

##### Bits[5..4], TX Empty Trigger (or `TET`): {-}
This is used to select the empty threshold level at which the `THRE` Interrupts will be generated when the mode is active. It also determines when the `dma_tx_req_n` signal will be asserted when in certain modes of operation.

The following trigger levels are supported:

- 00 = FIFO empty
- 01 = 2 characters in the FIFO
- 10 = FIFO 1/4 full
- 11 = FIFO 1/2 full

##### Bit[3], DMA Mode (or `DMAM`): {-}
This determines the DMA signalling mode used for the `dma_tx_req_n` and `dma_rx_req_n` output signals.

- 0 = mode 0
- 1 = mode 1

##### Bit[2], XMIT FIFO Reset (or `XFIFOR`): {-}
This resets the control portion of the transmit FIFO and treats the FIFO as empty. Note that this bit is 'self-clearing' and it is not necessary to clear this bit.

##### Bit[1], RCVR FIFO Reset (or `RFIFOR`): {-}
This resets the control portion of the receive FIFO and treats the FIFO as empty. Note that this bit is 'self-clearing' and it is not necessary to clear this bit.

##### Bit[0], FIFO Enable (or `FIFOE`): {-}
This enables/disables the transmit (`XMIT`) and receive (`RCVR`) FIFO's. Whenever the value of this bit is changed both the `XMIT` and
`RCVR` controller portion of FIFO's will be reset.

## Table 55: UART_LPDLL_REG (0x50001020) {-}
### [15..8] {-}
#### Reserved {-}
### [7..0] R/W UART_LPDLL {-}
This register makes up the lower 8-bits of a 16-bit, read/write, Low Power Divisor Latch register that contains the baud rate divisor for the UART, which must give a baud rate of 115.2K. This is required for SIR Low Power (minimum pulse width) detection at the receiver. This register may be accessed only when the `DLAB` bit (`LCR[7]`) is set. The output low-power baud rate is equal to the serial clock (`sclk`) frequency divided by sixteen times the value of the baud rate divisor, as follows:

Low power baud rate = (serial clock frequency)/(16* divisor)

Therefore, a divisor must be selected to give a baud rate of 115.2K.

NOTE: When the Low Power Divisor Latch registers (`LPDLL and LPDLH`) are set to 0, the low-power baud clock is disabled and no low-power pulse detection (or any pulse detection) occurs at the receiver. Also, once the `LPDLL` is set, at least eight clock cycles of the slowest UART Ctrl clock should be allowed to pass before transmitting or receiving data.

## Table 56: UART_LPDLH_REG (0x50001024) {-}
### [15..8] {-}
#### Reserved {-}
#### [7..0] R/W UART_LPDLH {-}
This register makes up the upper 8-bits of a 16-bit, read/write, Low Power Divisor Latch register that contains the baud rate divisor for the UART, which must give a baud rate of 115.2K. This is required for SIR Low Power (minimum pulse width) detection at the receiver. This register may be accessed only when the `DLAB` bit (`LCR[7]`) is set. The output low-power baud rate is equal to the serial clock (`sclk`) frequency divided by sixteen times the value of the baud rate divisor, as follows:

~~~
Low power baud rate = (serial clock frequency) / (16 * divisor)
~~~

Therefore, a divisor must be selected to give a baud rate of 115.2K.

NOTE: When the Low Power Divisor Latch registers (`LPDLL and LPDLH`) are set to 0, the low-power baud clock is disabled and no low-power pulse detection (or any pulse detection) occurs at the receiver. Also, once the LPDLH is set, at least eight clock cycles of the slowest UART Ctrl clock should be allowed to pass before transmitting or receiving data.

## Table 57..72: UART_SRBR_STHR[0..15]\_REG  (0x50001030..0x5000106C) {-}
### [15..8] {-}
#### Reserved {-}
### [7..0] SRBR_STHRX [R/W] {-}
#### Shadow Receive Buffer Register x: {-}
This is a shadow register for the `RBR` and has been allocated sixteen 32-bit locations so as to accommodate burst accesses from the master. This register contains the data byte received on the serial input port (`sin`) in UART mode or the serial infrared input (`sir_in`) in infrared mode. The data in this register is valid only if the Data Ready (`DR`) bit in the Line status Register (`LSR`) is set. If FIFOs are disabled (`FCR[0] set to zero`), the data in the RBR must be read before the next data arrives, otherwise it will be overwritten, resulting in an overrun error. If FIFOs are enabled (`FCR[0] set to one`), this register accesses the head of the receive FIFO. If the receive FIFO is full and this register is not read before the next data character arrives, then the data already in the FIFO will be preserved but any incoming data will be lost. An overrun error will also occur.

#### Shadow Transmit Holding Register x: {-}
This is a shadow register for the THR and has been allocated sixteen 32-bit locations so as to accommodate burst accesses from the master. This register contains data to be transmitted on the serial output port (`sout`) in UART mode or the serial infrared output (`sir_out_n`) in infrared mode. Data should only be written to the THR when the THR Empty (`THRE`) bit (`LSR[5]`) is set. If FIFO's are disabled (`FCR[0] set to zero`) and `THRE` is set, writing a single character to the `THR` clears the `THRE`. Any additional writes to the `THR` before the `THRE` is set again causes the `THR` data to be overwritten. If FIFO's are enabled (`FCR[0] set to one`) and `THRE` is set, `x` number of characters of data may be written to the THR before the FIFO is full. The number `x` (default=16) is determined by the value of FIFO Depth that you set during configuration. Any attempt to write data when the FIFO is full results in the write data being lost.
