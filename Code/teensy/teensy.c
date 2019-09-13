#include <PWMServo.h>

#define MOTOR_OUT_PIN 
#define RUDDER_OUT_PIN
#define MODE_IN_PIN
#define MOTOR_IN_PIN
#define RUDDER_IN_PIN

PWMServo motor;
PWMServo rudder;

volatile uint16_t motorCh;
volatile uint16_t motorCh_start;
volatile uint16_t rudderCh;
volatile uint16_t rudderCh_start;
volatile uint16_t modeCh;
volatile uint16_t modeCh_start;

void setup() {
    Serial1.begin(9600);     // opens serial port, sets data rate to 9600 bps

    motor.attach(MOTOR_OUT_PIN);
    rudder.attach(RUDDER_OUT_PIN);

    pinMode(MODE_IN_PIN, INPUT);
    pinMode(RUDDER_IN_PIN, INPUT);
    pinMode(MODE_IN_PIN, INPUT);

    attachInterrupt(MODE_IN_PIN, PWMReader(MODE_IN_PIN), CHANGE);
    attachInterrupt(RUDDER_IN_PIN, PWMReader(RUDDER_IN_PIN), CHANGE);
    attachInterrupt(MOTOR_IN_PIN, PWMReader, CHANGE);
}

void loop() {


    motor.write()
    rudder.write()

    // send data only when you receive data:
    if (Serial1.available() > 0) {
        // read the incoming byte:
        incomingByte = Serial1.read();

        // say what you got: echo out Serial1
        Serial1.print("I received: ");
        Serial1.println(incomingByte, DEC);
        // say what you got: print out Teensy USB port
        Serial.print("I received: ");
        Serial.println(incomingByte, DEC);
    }
}

void PWMReader(channel)
{
    if(digitalRead(MOTOR_IN_PIN)==HIGH)
    {
        =micros();
    }
    else
    {
        channel = (uint16_t) (micros() - channel_start);
    }

}