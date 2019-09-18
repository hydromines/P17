# Teensy

A teensy 3.2 is used because it can handle 5V power supply. It's purpose is to handle the PWM signals recieved from the the transmitter and sent to the servomotor and motor. We dont connect the reciever directly the servomotor qnd the motor as it is usually done because we want to be able to switch between an automatic mode and a manual mode. The interruptor to switch between these two modes will be on the radiocommande. A Raspberry Pie cannot be used for this part because it cannot read PWM signals (impossible to use interrupts on the raspberry pi). Morevover, in case of problem, the reboot time of the teensy is almost instatenous, not like the RPi.

## Principle

### Read PWM signals
In order to read the PWM signals with the Teensy, interrupts are used. A timer is launched on rising fronts and stopped on sinking ones. The interval measured corresponds to the PWM signal.

### Write PWN signals
The PWMServo library is used to generate the PWM signals. The interval measured previously is mapped between 0° and 180° to have the command.
The pins 3-6, 9, 10, 20-23, 25, 32 can be used to generate PWM signals.
We will use the pins 

### Communicate with Raspberry Pi
The Teensy communicates with the Raspberry Pi with serial Tx/Rx. The Raspberry Pi is the one that generates the commands in automatic mode. Also, the Teensy will indicate to the Raspberry Pi when the boat is in manual or in automatic mode. The Teensy indeed also reads a channel from the RC receiver indicating which mode is in use.

The first serial channel is used (RX/TX1) with the pins 0 (RX1) and 1 (TX1).
