
#include <APA102/APA102.h>
//#include <FastGPIO/FastGPIO.h>
//#define APA102_USE_FAST_GPIO
#include <string.h>
const int dataPin = 11;
const int clockPin = 12;
APA102<dataPin, clockPin> ledStrip;
const int ledCount = 144;
String mainString;
void setup()
{
	pinMode(2, OUTPUT);
	pinMode(3, OUTPUT);
	digitalWrite(2, LOW);
	digitalWrite(3, HIGH);
	Serial.begin(9600);
	
}

void loop()
{
	if (Serial.available()) {
		//new Data!!!!!
		char c;
		while (c = Serial.read()) {
			mainString += c;
		}
	}
	//main loop
	for (int i = 0; i < mainString.length; i++) {
		if (mainString[i] == 's') {
			//start symbol for reading
			ledStrip.startFrame();
			if (mainString[i] == '\n') {
					ledStrip.endFrame(ledCount);
					//delay here
					delay(10);
					ledStrip.startFrame();
					continue;
			}
			else if (mainString[i] == 'e') {
					ledStrip.endFrame(ledCount);
					//delay here
					delay(10);
					ledStrip.startFrame();
					continue;
			}
			if (mainString[i] == '0') {
				ledStrip.sendColor(0, 0, 0, 1);
			}
			if (mainString[i] == '1') {
				ledStrip.sendColor(255, 0, 255, 5);
			}
		}
	}
	/*ledStrip.startFrame();
	bool b = false;
	for (int i = 0; i < ledCount; i++)
	{
		if (b == false) {
			b = true;
			ledStrip.sendColor(255, 0, 255, 1);
		}
		else {
			b = false;
			ledStrip.sendColor(0, 0, 0, 1);
		}
	}
	ledStrip.endFrame(ledCount);*/

}
