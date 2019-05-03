
#include <APA102/APA102.h>
//#include <FastGPIO/FastGPIO.h>
//#define APA102_USE_FAST_GPIO

#include <string.h>
const int ledCountVert = 120;
const int ledCountHori = 16;
APA102<11, 12> ledStrip; //<data, clock>
String mainString;
String redString;
String greenString;
String blueString;
String fpsString;
char currentChar[ledCountHori][ledCountVert];
int redInt;
int greenInt;
int blueInt;
int fpsInt;

void setup()
{
	Serial.begin(9600);
	mainString = "a";
	redInt = 255;
	greenInt = 0;
	blueInt = 255;
	fpsInt = 15;
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
				redInt = redString.toInt();
				char read3 = Serial.read();
				if (read3 == 'g') {
					greenString = "";
					greenString += Serial.read() - 48;
					greenString += Serial.read() - 48;
					greenString += Serial.read() - 48;
					greenInt = greenString.toInt();
					char read4 = Serial.read();
					if (read4 == 'b') {
						blueString = "";
						blueString += Serial.read() - 48;
						blueString += Serial.read() - 48;
						blueString += Serial.read() - 48;
						blueInt = blueString.toInt();
						char read5 = Serial.read();
						if (read5 == 'f') {
							fpsString = "";
							fpsString += Serial.read() - 48;
							fpsString += Serial.read() - 48;
							fpsString += Serial.read() - 48;
							fpsInt = fpsString.toInt();
							char read6 = Serial.read();
							mainString = "";
							while (read6 != '0') {
								mainString += read6;
								read6 = Serial.read();
							}
						}
					}
				}
			}
		}
	}

	//show();
	//main loop
	//start symbol for reading
	for (int character = 0; character < mainString.length(); character++) {
		populateBytes(mainString[character]); //hope this is fast enough. I need to keep working here
		ledStrip.startFrame();
		for (int j = 0; j < ledCountHori; j++) {
			for (int i = 0; i < ledCountVert; i++) {
				if (currentChar[i][j] == '0') {
					ledStrip.sendColor(0, 0, 0, 0);
				}
				else if (currentChar[i][j] == '1') {
					ledStrip.sendColor(redInt, greenInt, blueInt, fpsInt);
				}
				ledStrip.endFrame(ledCountVert);
				//delay between each column here
				delay(5);
			}
		}
	}
	//full revolution delay here
	delay(30);

	/*uncomment for static color on all LED's
	ledStrip.startFrame();
	for (int i = 0; i < ledCountVert; i++) {
		ledStrip.sendColor(255, 0, 255);
	}
	ledStrip.endFrame(ledCountVert);*/
}
void printBytes() {
	for (int j = 0; j < ledCountVert / 2; j++) {
		for (int i = 0; i < ledCountHori; i++) {
			Serial.print(currentChar[i][j]);
		}
		Serial.println("");
	}
}
void show() {
	Serial.println("Red: " + redString);
	Serial.println("green: " + greenString);
	Serial.println("blue: " + blueString);
	Serial.println("fps: " + fpsString);
	Serial.println("main: " + mainString);
}
void populateBytes(char c) {
	if (c == 'a') {
		for (int i = 0; i < ledCountVert / 2; i++) {
			currentChar[0][i] = '0';
			currentChar[1][i] = '0';
		}
		for (int i = 0; i < ledCountVert / 2; i++) {
			if (i < 29 || i > 47) {
				currentChar[2][i] = '0';
			}
			else { currentChar[2][i] = '1'; }
		}
		for (int i = 0; i < ledCountVert / 2; i++) {
			if (i < 27 || i > 47) {
				currentChar[3][i] = '0';
			}
			else {
				currentChar[3][i] = '1';
			}
		}
		for (int i = 0; i < ledCountVert / 2; i++) {
			if (i == 27 || i == 36 || i == 37) {
				currentChar[4][i] = '1';
				currentChar[5][i] = '1';
				currentChar[6][i] = '1';
				currentChar[7][i] = '1';
				currentChar[8][i] = '1';
				currentChar[9][i] = '1';
				currentChar[10][i] = '1';
				currentChar[11][i] = '1';
			}
			else {
				currentChar[4][i] = '0';
				currentChar[5][i] = '0';
				currentChar[6][i] = '0';
				currentChar[7][i] = '0';
				currentChar[8][i] = '0';
				currentChar[9][i] = '0';
				currentChar[10][i] = '0';
				currentChar[11][i] = '0';
			}
		}
		for (int i = 0; i < ledCountVert / 2; i++) {
			if (i < 27 || i > 47) {
				currentChar[12][i] = '0';
			}
			else {
				currentChar[12][i] = '1';
			}
		}
		for (int i = 0; i < ledCountVert / 2; i++) {
			if (i < 29 || i > 47) {
				currentChar[13][i] = '0';
			}
			else { currentChar[13][i] = '1'; }
		}
		for (int i = 0; i < ledCountVert / 2; i++) {
			currentChar[14][i] = '0';
			currentChar[15][i] = '0';
		}
	}
	else { Serial.println("not implemetned yet"); }
}
