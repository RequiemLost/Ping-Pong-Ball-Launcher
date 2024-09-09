#include <Servo.h>
// Include the Servo library 
int servoPin = 3; 
// Create a servo object 
Servo Servo1; 

#define stepPin 2
#define dirPin 5 

Servo ESC; 
int mode;
int Speed; 

void setup(){
  ESC.attach(9,1000,2000);
  Serial.begin(9600);
  Servo1.attach(servoPin); 
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  delay(2000);
  for (int i = 0; i < 3; i++){
    Speed = map(1023, 0, 1023, 0, 180);
    ESC.write(Speed); 
    delay(2000);
    Speed = map(0, 0, 1023, 0, 180);
    ESC.write(Speed); 
    delay(2000);
  }
}

void loop(){
  if(Serial.available() > 0){
    mode = Serial.read();
    if(mode==49){
      Serial.print("I got ");
      mode = 1;
      Serial.print(mode, DEC);
    }
    if(mode==50){
      Serial.print("I got ");
      mode = 2;
      Serial.print(mode, DEC);
    }
    if(mode==51){
      Serial.print("I got ");
      mode = 3;
      Serial.print(mode, DEC);
    }
    if(mode==52){
      Serial.print("I got ");
      mode = 4;
      Serial.print(mode, DEC);
      digitalWrite(dirPin,LOW); //Changes the rotations direction
      for(int x = 5; x <  10; x++) {
        digitalWrite(stepPin,HIGH);
        delayMicroseconds(10000);
        digitalWrite(stepPin,LOW);
        delayMicroseconds(700);
      }
    }
    if(mode==53){
      Serial.print("I got ");
      mode = 5;
      Serial.print(mode, DEC);
    }
    if(mode==54){
      Serial.print("I got ");
      mode = 6;
      Serial.print(mode, DEC);
    }
    if(mode==55){
      Serial.print("I got ");
      mode = 7;
      Serial.print(mode, DEC);
    }
  }
  if(mode==1){
    Servo1.write(180);
    Serial.println(Speed);
    Speed = map(200, 0, 1023, 0, 180);
    ESC.write(Speed);
  }
  if(mode==2){
    Servo1.write(90);
    Serial.println(Speed);
    Speed = map(1000, 0, 1023, 0, 180);
    ESC.write(Speed);
  }
  if(mode==3){
    Servo1.write(0);
    Serial.println(Speed);
    Speed = map(400, 0, 1023, 0, 180);
    ESC.write(Speed);
  }
  if(mode==4){
    Servo1.write(180);
    Serial.println(Speed);
    Speed = map(500, 0, 1023, 0, 180);
    ESC.write(Speed);
    digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
    for(int x = 5; x < 10; x++) {
      digitalWrite(stepPin,HIGH); 
      delayMicroseconds(10000);    // by changing this time delay between the steps we can change the rotation speed
      digitalWrite(stepPin,LOW); 
      delayMicroseconds(700); 
    }
  }
  if(mode==5){
    Serial.print("yay");
    Servo1.write(180);
    Speed = map(0, 0, 1023, 0, 180);
    ESC.write(Speed);

  }
  if(mode==6){
    digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
    for(int x = 5; x < 8; x++) {
      digitalWrite(stepPin,HIGH); 
      delayMicroseconds(10000);    // by changing this time delay between the steps we can change the rotation speed
      digitalWrite(stepPin,LOW); 
      delayMicroseconds(700); 
    }
  }
  if(mode==7){
    digitalWrite(dirPin,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
    for(int x = 5; x < 8; x++) {
      digitalWrite(stepPin,HIGH); 
      delayMicroseconds(10000);    // by changing this time delay between the steps we can change the rotation speed
      digitalWrite(stepPin,LOW); 
      delayMicroseconds(700); 
    }
  }
}

//Slow - 350ish, Fast - 400ish, super fast - 600