#include <Servo.h> 

Servo openServo, closeServo;  // create servo object to control a servo 
int openPos = 0, closePos = 0;    // variable to store the servo position 

void setup() 
{ 
    openServo.attach(9);  // attaches the servo on pin 9 to the servo object 
    closeServo.attach(5);
    delay(1000);
} 

void loop() {
    open();
    delay(1000);
    close();
    delay(1000);
}

void open() 
{ 
    for(openPos = 0; openPos < 150; openPos += 1)  // goes from 0 degrees to 180 degrees 
    {                                  // in steps of 1 degree 
        openServo.write(openPos);              // tell servo to go to position in variable 'pos' 
        delay(15);                       // waits 15ms for the servo to reach the position 
    } 
    for(openPos = 150; openPos>=1; openPos-=1)     // goes from 180 degrees to 0 degrees 
    {                                
        openServo.write(openPos);              // tell servo to go to openPosition in variable 'openPos' 
        delay(15);                       // waits 15ms for the servo to reach the openPosition 
    } 
} 

void close() 
{ 
    for(closePos = 160; closePos>=1; closePos-=1)     // goes from 180 degrees to 0 degrees 
    {                                
        closeServo.write(closePos);              // tell servo to go to closePosition in variable 'closePos' 
        delay(15);                       // waits 15ms for the servo to reach the closePosition 
    } 
    for(closePos = 0; closePos < 160; closePos += 1)  // goes from 0 degrees to 180 degrees 
    {                                  // in steps of 1 degree 
        closeServo.write(closePos);              // tell servo to go to position in variable 'pos' 
        delay(15);                       // waits 15ms for the servo to reach the position 
    } 
} 
