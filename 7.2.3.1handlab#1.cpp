#include <Arduino.h>

const int trigPin = 11;
const int echoPin = 12;
const int powerPin = 9;


long duration;
int distance;

void setup() {
 
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  pinMode(powerPin, OUTPUT); 
 
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(powerPin, HIGH); 

  Serial.begin(9600);
}

void loop() {
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  
  duration = pulseIn(echoPin, HIGH);

  
  distance = duration * 0.034 / 2;
  
  
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(50);
  
}
