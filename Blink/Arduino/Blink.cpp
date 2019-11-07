#include "Arduino.h"

void setup() {
	
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(PB14, OUTPUT);
	pinMode(PB7, OUTPUT);
	Serial.begin(115200);
	
}

// the loop function runs over and over again forever
void loop() {
	
  digitalWrite(PB14, HIGH);   			// turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a second
  digitalWrite(PB14, LOW);    			// turn the LED off by making the voltage LOW
	delay(500);                       // wait for a second
	Serial3.println("hello...");
	
}
