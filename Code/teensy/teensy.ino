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
    //Initialize serial communication with Raspberry Pi
    Serial1.begin(9600);

    //Define the outputs
    motor.attach(MOTOR_OUT_PIN);
    rudder.attach(RUDDER_OUT_PIN);

    //Define the Inputs
    pinMode(MODE_IN_PIN, INPUT);
    pinMode(RUDDER_IN_PIN, INPUT);
    pinMode(MODE_IN_PIN, INPUT);

    //Attach interrupts to pin
    attachInterrupt(MODE_IN_PIN, ModeReader, CHANGE);
    attachInterrupt(RUDDER_IN_PIN, RudderReader, CHANGE);
    attachInterrupt(MOTOR_IN_PIN, MotorReader, CHANGE);
}

void loop() {

    if (Serial1.available() > 0) {
        // read the incoming byte:
        incomingByte = Serial1.read();
        /*
        Choose the message form to communicate commands and code it    
        */
    }

    if (modeCh > 1500)  //Manual Mode
    {
        motor.write(map(motorCh, 0, 2000, 0, 180))
        rudder.write()

    }

    else    //Automatic Mode, commands come from Raspberry Pi
    {
        motor.write()
        rudder.write()

    }
}

void MotorReader()
{
    if(digitalRead(MOTOR_IN_PIN)==HIGH)
    {
        motorCh_start = micros();
    }
    else
    {
        motorCh = (uint16_t) (micros() - motorCh_start);
    }
}

void RudderReader()
{
    if(digitalRead(RUDDER_IN_PIN)==HIGH)
    {
        rudderCh_start = micros();
    }
    else
    {
        rudderCh = (uint16_t) (micros() - rudderCh_start);
    }
}

void ModeReader()
{
    if(digitalRead(MODE_IN_PIN)==HIGH)
    {
        modeCh_start = micros();
    }
    else
    {
        modeCh = (uint16_t) (micros() - modeCh_start);
    }
}