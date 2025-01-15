#include <Arduino.h>
#include "airframe.h"

Airframe airframe;

void setup() {
	// put your setup code here, to run once:
	pinMode(LED_BUILTIN, OUTPUT);
	Serial.begin(38400);
	Serial.println("Serial Monitor Initialized.");

	// initialize subsystems
	Airframe *airframe = new Airframe();

}

void loop() {
	airframe.periodic();
	delay(20);
}
