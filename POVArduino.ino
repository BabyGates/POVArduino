
#include <APA102/APA102.h>
#include <FastGPIO/FastGPIO.h>
#define APA102_USE_FAST_GPIO

#include <string.h>
const int dataPin = 11;
const int clockPin = 12;
const int ledCount = 144;
APA102<dataPin, clockPin> ledStrip;
String mainString;
String redString;
String greenString;
String blueString;
String fpsString;
byte b = B00000010;

char char0_col0[72];
char char0_col1[72];
char char0_col2[72];
char char0_col3[72];
char char0_col4[72];
char char0_col5[72];
char char0_col6[72];
char char0_col7[72];
char char0_col8[72];
char char0_col9[72];
char char0_col10[72];
char char0_col11[72];
char char0_col12[72];
char char0_col13[72];
char char0_col14[72];
char char0_col15[72]; //reload foreach colomn?? is fast enough
int redInt;
int greenInt;
int blueInt;
int fpsInt;

void setup()
{
	Serial.begin(9600);
	if (b == 2) {

	}
}

void loop()
{
	if (Serial.available()) {
		//new Data!!!!!
		char read1 = Serial.read();
		if (read1 == 's') {
			char read2 = Serial.read();
			if (read2 == 'r') {
				redString = "";
				redString += Serial.read() - 48;
				redString += Serial.read() - 48;
				redString += Serial.read() - 48;
				//redInt = redString.toInt;
				char read3 = Serial.read();
				if (read3 == 'g') {
					greenString = "";
					greenString += Serial.read() - 48;
					greenString += Serial.read() - 48;
					greenString += Serial.read() - 48;
					char read4 = Serial.read();	
					if (read4 == 'b') {
						blueString = "";
						blueString += Serial.read() - 48;
						blueString += Serial.read() - 48;
						blueString += Serial.read() - 48;
						char read5 = Serial.read();
						if (read5 == 'f') {
							fpsString = "";
							fpsString += Serial.read() - 48;
							fpsString += Serial.read() - 48;
							fpsString += Serial.read() - 48;
							char read6 = Serial.read();
							mainString = "";
							while (read6 != '\0') {
								mainString += read6;
								read6 = Serial.read();
							}
							show();
							for (int i = 0; i < mainString.length(); i++) {
								populateBytes(mainString[i], i);
								printBytes(i);
							}
						}
					}
				}
			}
		}
	}


	//main loop
	//start symbol for reading
	ledStrip.startFrame();
	for (int i = 0; i < ledCount / 2; i++) {
		if (char0_col0[i] == '0') {
			ledStrip.sendColor(0, 0, 0, 0);
		}
		else if (char0_col0[i] == '1') {
			ledStrip.sendColor(255, 0, 255, 5);
		}
	}
	ledStrip.endFrame(ledCount);
	//full revolution delay
	delay(100);

}
void printBytes(int index) {
	if (index == 0) {
		for (int i = 0; i < ledCount/2; i++) {
			Serial.print(char0_col0[i]);
			Serial.print(char0_col1[i]);
			Serial.print(char0_col2[i]);
			Serial.print(char0_col3[i]);
			Serial.print(char0_col4[i]);
			Serial.print(char0_col5[i]);
			Serial.print(char0_col6[i]);
			Serial.print(char0_col7[i]);
			Serial.print(char0_col8[i]);
			Serial.print(char0_col9[i]);
			Serial.print(char0_col10[i]);
			Serial.print(char0_col11[i]);
			Serial.print(char0_col12[i]);
			Serial.print(char0_col13[i]);
			Serial.print(char0_col14[i]);
			Serial.println(char0_col15[i]);
		}
	}
}
void show() {

	Serial.println("Red: " + redString);
	Serial.println("green: " + greenString);
	Serial.println("blue: " + blueString);
	Serial.println("fps: " + fpsString);
	Serial.println("main: " + mainString);
}
void populateBytes(char c, int i) {
	if (c == 'a') {
		if (i == 0) {
			for (int i = 0; i < ledCount/2; i++) {
				char0_col0[i] = '0';
				char0_col1[i] = '0';
			}
			for (int i = 0; i < ledCount / 2; i++) {
				if (i < 29 || i > 47) {
					char0_col2[i] = '0';
				}
				else{ char0_col2[i] = '1'; }
			}
			for (int i = 0; i < ledCount / 2; i++) {
				if (i < 27 || i > 47) {
					char0_col3[i] = '0';
				}
				else { 
					char0_col3[i] = '1';
				}
			}
			for (int i = 0; i < ledCount / 2; i++) {
				if (i == 27 || i == 36 || i == 37) {
					char0_col4[i] = '1';
					char0_col5[i] = '1';
					char0_col6[i] = '1';
					char0_col7[i] = '1';
					char0_col8[i] = '1';
					char0_col9[i] = '1';
					char0_col10[i] = '1';
					char0_col11[i] = '1';
				}
				else {
					char0_col4[i] = '0';
					char0_col5[i] = '0';
					char0_col6[i] = '0';
					char0_col7[i] = '0';
					char0_col8[i] = '0';
					char0_col9[i] = '0';
					char0_col10[i] = '0';
					char0_col11[i] = '0';
				}
			}
			for (int i = 0; i < ledCount / 2; i++) {
				if (i < 27 || i > 47) {
					char0_col12[i] = '0';
				}
				else {
					char0_col12[i] = '1';
				}
			}
			for (int i = 0; i < ledCount / 2; i++) {
				if (i < 29 || i > 47) {
					char0_col13[i] = '0';
				}
				else { char0_col13[i] = '1'; }
			}
			for (int i = 0; i < ledCount / 2; i++) {
				char0_col14[i] = '0';
				char0_col15[i] = '0';
			}
		}
	}
	else { Serial.println("not implemetned yet"); }
}
