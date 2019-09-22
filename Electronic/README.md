#Electronic

## TO DO
* Read Can bus from the motor
* Make the card for the electronic components on top of the mat (The fritzing files are in the Mat_Board directory)
* Test temperature sensor
* Test water presence sensor
* Read position message from GPS receiver

## Components

### Sensors
    -Temperature
    -Water presence
    -Motor
    -MARG: VN-100
    -GPS: Emlid Reach RTK
    
### Controllers
    -Teensy
    -Raspberry Pi
    
### Actuators
    -Savox: Waterproof servomotor
    -Electronic Motor

## CAN Reader

In order to read the feedback information from the motor, we must be able to read CAN messages. The Raspberry Pi cannot do that innately. Therefor, the 	
Microchip MCP2515 is used. THe information will thus be read by the Raspberry Pi by SPI. The teensy can also be used for that but it is prefered to dedicate the teensy to handle PWM.

In the end, the circuit should be embedded in the main board but for the testing phase, an already make breakout board can be bought: https://www.amazon.com/Comidox-MCP2515-Receiver-Controller-Development/dp/B07J9KZ4L4/ref=sr_1_12?keywords=can+SPI+adapter&qid=1569098705&sr=8-12

The followinf website explains clearly how to proceed.
http://youness.net/raspberry-pi/raspberry-pi-can-bus

## GPS receiver
General information: https://docs.emlid.com/reach/

These link give indication on how to get gps data though usb.
https://community.emlid.com/t/gps-data-over-usb/6387/7
https://docs.emlid.com/reach/common/reachview/position-output/#serial

## Water and temperature sensors
The objective is that all sensors are connected to the RPi. However, the RPi does not have analog sensor and most temperature sensors are analog. Thus, a digital temperature sensor is needed. Possible website: http://www.circuitbasics.com/raspberry-pi-ds18b20-temperature-sensor-tutorial/

The same goes for Water sensor: https://www.robotshop.com/eu/fr/capteur-fuite-sos.html
