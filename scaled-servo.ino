#define GroundPin 10

#define echoPin 11

#define trigPin 12

#define VccPin 13

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
void setup()

{

Serial.begin (9600);         //set data transmission rate to communicate with computer

pinMode(VccPin, OUTPUT) ;    //tell pin 13 it is going to be an output

digitalWrite(VccPin, HIGH) ; //tell pin 13 to output HIGH (+5V)

pinMode(echoPin, INPUT);     //tell pin 11 it is going to be an input

pinMode(trigPin, OUTPUT);    //tell pin 12 it is going to be an output

pinMode(GroundPin, OUTPUT) ; //tell pin 10 it is going to be an output

digitalWrite(GroundPin,LOW) ;//tell pin 10 to output LOW (0V, or ground)

myservo.attach(9);  // attaches the servo on pin 9 to the servo object


}

void loop()

{

int duration, distance;                //defining variables

digitalWrite(trigPin, HIGH);           //set trigger pin to HIGH

delayMicroseconds(6000);               //wait 6000 microseconds

digitalWrite(trigPin, LOW);            //set trigger pin to LOW

duration = pulseIn(echoPin, HIGH);     //read echo pin

distance = (duration/2) / 29.1;        //compute distance from duration of echo Pin

if (distance >= 21 || distance <= 5)  //deciding whether or not distance is reasonable

  {

  Serial.println("Out of range");      //if not, print the words "Out of range"

  }

  else

  {

  Serial.print(distance);              //printing the value of the variable "distance"

  Serial.println(" cm");               //printing " cm" after the value
  for (pos = 0; pos <= distance*9; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos =distance*9 ; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  }

delay(500);

}
