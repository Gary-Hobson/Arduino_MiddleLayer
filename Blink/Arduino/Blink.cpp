#include "Arduino.h"
#include "main.h"
#include "usart.h"
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(PB14, OUTPUT);
	pinMode(PB7, OUTPUT);
	Serial.begin(115200);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(PB14, HIGH);   // turn the LED on (HIGH is the voltage level)
	digitalWrite(PB7, LOW);
  delay(1000);                       // wait for a second
  digitalWrite(PB14, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(PB7, HIGH); 
	delay(2000);                       // wait for a second
}
