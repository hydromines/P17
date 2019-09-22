Under work.

## TO DO:
* Serial Connexion between Teensy and raspberry
* Serial Connexion between GPS receiver and Raspberry
* Serial Connexio between Xbee and Raspberry
* Connextion between temperature sensor and raspberry
* Connexion between water sensor and raspberry

## Connexions

### Raspberry Pi
* GPIO -> Temperature sensor
* GPIO -> Water sensor
* SPI pins > MCP2151
* Serial pins -> Teensy: Serial (RX, Tx)
* USB -> USB D+/D-: Xbee (To do so, a USB cable has to be cut and soldered to the PCB)
* USB -> USB D+/D-: GPS receiver (To do so, a USB cable has to be cut and soldered to the PCB)

### Teensy
* Ouput servo signal -> Servo: Signal
* Output motor signal -> Motor: Signal
* Input channel k -> RC receiver channel k
* 5V -> BEC 5V
* GND
* RX -> Raspberry Pi: TX
* Tx -> Raspberry Pi: Rx

### Rc Receiver
* Channel k -> Teensy: digital pin (interrupt attached)
* 5V -> Teensy: 5V
* GND

### GPS receiver
* Micro USB D+ -> Raspberry Pi: USB D+
* Micro USB D- -> Raspberry Pi: USB D-
* 5V -> Raspberry Pi: 5V
* GND

### Xbee
* Micro USB D+ -> Raspberry Pi: USB D+
* Micro USB D- -> Raspberry Pi: USB D-
* 5V -> Raspberry Pi: 5V
* GND

### Motor
* Control circuit power -> Teensy : 5V
* Control circuit signal (PWM) -> Teensy: PWM output pin
* GND
* CAN High -> MCP2551: CAN high
* CAN LOW -> MCP 2551: CAN LOW
* Emergency stop short circuit -> Interruptor
* Emergency stop short circuit -> Interruptor

### Servo
* Signal -> Teensy : PWM output pin
* Power (7.4V) -> 7.4V BEC : 7.4V
* GND