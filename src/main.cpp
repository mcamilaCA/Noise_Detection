#include <Arduino.h>

int sensor = 7; // pin in which the sound sensor is
int led = 13; // pin where the led (positive side) is connected
boolean sensorState = false; // state of the led is off by default 


void setup() {
  pinMode(sensor, INPUT);
  pinMode(led, OUTPUT); 
}

void loop() {
  int data = digitalRead(sensor); // getting the state of the sound sensor

  // if noise is detected 
  if (data == 1){
    if(sensorState == false){
      sensorState = HIGH; // changing the state of led since there is noirse
      digitalWrite(led, HIGH); // turning on led light
    }
    else{
      sensorState = true; // is the led is high, turn it off
      digitalWrite(led, LOW); // turning off led light
    }
  }
}
