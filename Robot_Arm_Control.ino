
//Poops-Bot edited by Sam Kodo 



#include <Servo.h>
Servo myservo;  // create servo object to control a servo
int angle =80;    // initial angle  for servo
int angleStep = 1;

int LEFT = 4;  // pin 4 is connected to left button
int RIGHT = 2;  // pin 2 is connected to right button

void setup() {
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 6 to the servo object
  pinMode(LEFT,INPUT_PULLUP); // assign pin 4 ass input for Left button
  pinMode(RIGHT,INPUT_PULLUP);// assing pin 2 as input for right button
  myservo.write(angle);// send servo to the middle at 90 degrees
}

void loop() {
  while(digitalRead(RIGHT) == LOW){
    if (angle > 80 && angle <= 99) {
      angle = angle - angleStep;
       if(angle < 0){
        angle = 0;
       }else{
      myservo.write(angle); // move the servo to desired angle
      Serial.print("Moved to: ");
      Serial.print(angle);   // print the angle
      Serial.println(" degree");
       }
    }
   
  delay(10); // waits for the servo to get there
  }// while

  while(digitalRead(LEFT) == LOW){
    if (angle >= 80 && angle <= 99) {
      angle = angle + angleStep;
      if(angle >99){
        angle =99;
       }else{
      myservo.write(angle); // move the servo to desired angle
      Serial.print("Moved to: ");
      Serial.print(angle);   // print the angle
      Serial.println(" degree");
       }
    }
   
  delay(10); // waits for the servo to get there
  }
}
