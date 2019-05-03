
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
char currChar[ledCountHori][ledCountVert];
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
	//hard coded for now to test
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
		/*uncomment to print array
		printBytes(); */
		ledStrip.startFrame();
		for (int j = 0; j < ledCountHori; j++) {
			for (int i = 0; i < ledCountVert; i++) {
				if (currChar[i][j] == '1') {
					ledStrip.sendColor(redInt, greenInt, blueInt, fpsInt);
				}
				else {
					ledStrip.sendColor(0, 0, 0, 0);
				}
				ledStrip.endFrame(ledCountVert);
				//delay between each column here
				delay(5);
			}
		}
	}
	//full revolution delay here
	delay(30);

}
void printBytes() {
	for (int j = 0; j < ledCountVert/2; j++) {
		for (int i = 0; i < ledCountHori; i++) {
			if (currChar[i][j] == '0' || currChar[i][j] == '1') {
				Serial.print(currChar[i][j]);
			}
			else {
				Serial.print('0');
			}
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
		currChar[15][45] = '0';
		currChar[14][45] = '0';
		currChar[13][45] = '1';
		currChar[12][45] = '1';
		currChar[11][45] = '0';
		currChar[10][45] = '0';
		currChar[9][45] = '0';
		currChar[8][45] = '0';
		currChar[7][45] = '0';
		currChar[6][45] = '0';
		currChar[4][45] = '0';
		currChar[5][45] = '0';
		currChar[3][45] = '1';
		currChar[2][45] = '1';
		currChar[1][45] = '0';
		currChar[0][45] = '0';
		currChar[15][44] = '0';
		currChar[14][44] = '0';
		currChar[13][44] = '1';
		currChar[12][44] = '1';
		currChar[11][44] = '0';
		currChar[10][44] = '0';
		currChar[9][44] = '0';
		currChar[8][44] = '0';
		currChar[7][44] = '0';
		currChar[6][44] = '0';
		currChar[4][44] = '0';
		currChar[5][44] = '0';
		currChar[3][44] = '1';
		currChar[2][44] = '1';
		currChar[1][44] = '0';
		currChar[0][44] = '0';
		currChar[15][43] = '0';
		currChar[14][43] = '0';
		currChar[13][43] = '1';
		currChar[12][43] = '1';
		currChar[11][43] = '0';
		currChar[10][43] = '0';
		currChar[9][43] = '0';
		currChar[8][43] = '0';
		currChar[7][43] = '0';
		currChar[6][43] = '0';
		currChar[4][43] = '0';
		currChar[5][43] = '0';
		currChar[3][43] = '1';
		currChar[2][43] = '1';
		currChar[1][43] = '0';
		currChar[0][43] = '0';
		currChar[15][42] = '0';
		currChar[15][41] = '0';
		currChar[14][42] = '0';
		currChar[15][40] = '0';
		currChar[13][42] = '1';
		currChar[14][41] = '0';
		currChar[12][42] = '1';
		currChar[14][40] = '0';
		currChar[11][42] = '0';
		currChar[13][41] = '1';
		currChar[10][42] = '0';
		currChar[13][40] = '1';
		currChar[9][42] = '0';
		currChar[12][41] = '1';
		currChar[8][42] = '0';
		currChar[12][40] = '1';
		currChar[7][42] = '0';
		currChar[11][41] = '0';
		currChar[6][42] = '0';
		currChar[11][40] = '0';
		currChar[4][42] = '0';
		currChar[10][41] = '0';
		currChar[5][42] = '0';
		currChar[10][40] = '0';
		currChar[3][42] = '1';
		currChar[9][41] = '0';
		currChar[2][42] = '1';
		currChar[9][40] = '0';
		currChar[1][42] = '0';
		currChar[8][41] = '0';
		currChar[0][42] = '0';
		currChar[7][41] = '0';
		currChar[8][40] = '0';
		currChar[6][41] = '0';
		currChar[7][40] = '0';
		currChar[4][41] = '0';
		currChar[6][40] = '0';
		currChar[5][41] = '0';
		currChar[4][40] = '0';
		currChar[3][41] = '1';
		currChar[5][40] = '0';
		currChar[2][41] = '1';
		currChar[3][40] = '1';
		currChar[1][41] = '0';
		currChar[2][40] = '1';
		currChar[0][41] = '0';
		currChar[1][40] = '0';
		currChar[0][40] = '0';
		currChar[15][39] = '0';
		currChar[14][39] = '0';
		currChar[13][39] = '1';
		currChar[12][39] = '1';
		currChar[11][39] = '0';
		currChar[10][39] = '0';
		currChar[9][39] = '0';
		currChar[8][39] = '0';
		currChar[7][39] = '0';
		currChar[6][39] = '0';
		currChar[4][39] = '0';
		currChar[5][39] = '0';
		currChar[3][39] = '1';
		currChar[2][39] = '1';
		currChar[1][39] = '0';
		currChar[0][39] = '0';
		currChar[15][38] = '0';
		currChar[14][38] = '0';
		currChar[13][38] = '1';
		currChar[12][38] = '1';
		currChar[11][38] = '0';
		currChar[10][38] = '0';
		currChar[9][38] = '0';
		currChar[8][38] = '0';
		currChar[7][38] = '0';
		currChar[6][38] = '0';
		currChar[4][38] = '0';
		currChar[5][38] = '0';
		currChar[3][38] = '1';
		currChar[2][38] = '1';
		currChar[1][38] = '0';
		currChar[0][38] = '0';
		currChar[15][37] = '0';
		currChar[14][37] = '0';
		currChar[13][37] = '1';
		currChar[12][37] = '1';
		currChar[11][37] = '0';
		currChar[10][37] = '0';
		currChar[9][37] = '0';
		currChar[8][37] = '0';
		currChar[7][37] = '0';
		currChar[6][37] = '0';
		currChar[4][37] = '0';
		currChar[5][37] = '0';
		currChar[3][37] = '1';
		currChar[2][37] = '1';
		currChar[1][37] = '0';
		currChar[0][37] = '0';
		currChar[15][36] = '0';
		currChar[14][36] = '0';
		currChar[13][36] = '1';
		currChar[12][36] = '1';
		currChar[11][36] = '0';
		currChar[10][36] = '0';
		currChar[9][36] = '0';
		currChar[8][36] = '0';
		currChar[7][36] = '0';
		currChar[6][36] = '0';
		currChar[4][36] = '0';
		currChar[5][36] = '0';
		currChar[3][36] = '1';
		currChar[2][36] = '1';
		currChar[1][36] = '0';
		currChar[0][36] = '0';
		currChar[15][35] = '0';
		currChar[14][35] = '0';
		currChar[13][35] = '1';
		currChar[12][35] = '1';
		currChar[11][35] = '0';
		currChar[10][35] = '0';
		currChar[9][35] = '0';
		currChar[8][35] = '0';
		currChar[7][35] = '0';
		currChar[6][35] = '0';
		currChar[4][35] = '0';
		currChar[5][35] = '0';
		currChar[3][35] = '1';
		currChar[2][35] = '1';
		currChar[1][35] = '0';
		currChar[0][35] = '0';
		currChar[15][34] = '0';
		currChar[14][34] = '0';
		currChar[13][34] = '1';
		currChar[12][34] = '1';
		currChar[11][34] = '1';
		currChar[10][34] = '1';
		currChar[9][34] = '1';
		currChar[8][34] = '1';
		currChar[7][34] = '1';
		currChar[6][34] = '1';
		currChar[4][34] = '1';
		currChar[5][34] = '1';
		currChar[3][34] = '1';
		currChar[2][34] = '1';
		currChar[1][34] = '0';
		currChar[0][34] = '0';
		currChar[15][33] = '0';
		currChar[15][32] = '0';
		currChar[14][33] = '0';
		currChar[15][31] = '0';
		currChar[13][33] = '1';
		currChar[14][32] = '0';
		currChar[12][33] = '1';
		currChar[15][30] = '0';
		currChar[11][33] = '1';
		currChar[13][32] = '1';
		currChar[10][33] = '1';
		currChar[14][31] = '0';
		currChar[9][33] = '1';
		currChar[12][32] = '1';
		currChar[8][33] = '1';
		currChar[15][29] = '0';
		currChar[7][33] = '1';
		currChar[6][33] = '1';
		currChar[11][32] = '0';
		currChar[4][33] = '1';
		currChar[13][31] = '1';
		currChar[5][33] = '1';
		currChar[10][32] = '0';
		currChar[3][33] = '1';
		currChar[14][30] = '0';
		currChar[2][33] = '1';
		currChar[9][32] = '0';
		currChar[1][33] = '0';
		currChar[12][31] = '1';
		currChar[0][33] = '0';
		currChar[8][32] = '0';
		currChar[7][32] = '0';
		currChar[15][28] = '0';
		currChar[6][32] = '0';
		currChar[11][31] = '0';
		currChar[4][32] = '0';
		currChar[13][30] = '1';
		currChar[5][32] = '0';
		currChar[10][31] = '0';
		currChar[3][32] = '1';
		currChar[14][29] = '0';
		currChar[2][32] = '1';
		currChar[9][31] = '0';
		currChar[1][32] = '0';
		currChar[12][30] = '1';
		currChar[0][32] = '0';
		currChar[8][31] = '0';
		currChar[15][27] = '0';
		currChar[7][31] = '0';
		currChar[6][31] = '0';
		currChar[11][30] = '0';
		currChar[4][31] = '0';
		currChar[13][29] = '1';
		currChar[5][31] = '0';
		currChar[10][30] = '0';
		currChar[3][31] = '1';
		currChar[14][28] = '0';
		currChar[2][31] = '1';
		currChar[9][30] = '0';
		currChar[1][31] = '0';
		currChar[12][29] = '1';
		currChar[0][31] = '0';
		currChar[8][30] = '0';
		currChar[15][26] = '0';
		currChar[7][30] = '0';
		currChar[11][29] = '0';
		currChar[6][30] = '0';
		currChar[4][30] = '0';
		currChar[13][28] = '1';
		currChar[5][30] = '0';
		currChar[10][29] = '0';
		currChar[3][30] = '1';
		currChar[14][27] = '0';
		currChar[2][30] = '1';
		currChar[9][29] = '0';
		currChar[1][30] = '0';
		currChar[12][28] = '1';
		currChar[0][30] = '0';
		currChar[8][29] = '0';
		currChar[7][29] = '0';
		currChar[14][26] = '0';
		currChar[6][29] = '0';
		currChar[11][28] = '0';
		currChar[4][29] = '0';
		currChar[13][27] = '1';
		currChar[5][29] = '0';
		currChar[10][28] = '0';
		currChar[3][29] = '1';
		currChar[13][26] = '0';
		currChar[2][29] = '1';
		currChar[9][28] = '0';
		currChar[1][29] = '0';
		currChar[12][27] = '1';
		currChar[0][29] = '0';
		currChar[8][28] = '0';
		currChar[12][26] = '1';
		currChar[7][28] = '0';
		currChar[6][28] = '0';
		currChar[11][27] = '0';
		currChar[4][28] = '0';
		currChar[11][26] = '1';
		currChar[5][28] = '0';
		currChar[10][27] = '0';
		currChar[3][28] = '1';
		currChar[10][26] = '1';
		currChar[2][28] = '1';
		currChar[9][27] = '0';
		currChar[1][28] = '0';
		currChar[9][26] = '1';
		currChar[0][28] = '0';
		currChar[8][27] = '0';
		currChar[8][26] = '1';
		currChar[7][27] = '0';
		currChar[6][27] = '0';
		currChar[7][26] = '1';
		currChar[4][27] = '0';
		currChar[6][26] = '1';
		currChar[5][27] = '0';
		currChar[4][26] = '1';
		currChar[3][27] = '1';
		currChar[5][26] = '1';
		currChar[2][27] = '1';
		currChar[3][26] = '1';
		currChar[1][27] = '0';
		currChar[2][26] = '0';
		currChar[0][27] = '0';
		currChar[1][26] = '0';
		currChar[0][26] = '0';
		currChar[15][25] = '0';
		currChar[14][25] = '0';
		currChar[13][25] = '0';
		currChar[12][25] = '0';
		currChar[11][25] = '0';
		currChar[10][25] = '0';
		currChar[9][25] = '0';
		currChar[8][25] = '0';
		currChar[7][25] = '0';
		currChar[6][25] = '0';
		currChar[4][25] = '0';
		currChar[5][25] = '0';
		currChar[3][25] = '0';
		currChar[2][25] = '0';
		currChar[1][25] = '0';
		currChar[0][25] = '0';
	}
	else { Serial.println("not implemetned yet"); }
}
