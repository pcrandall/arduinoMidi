
// Include Libraries
#include "Arduino.h"
#include "LiquidCrystal.h"
#include "Potentiometer.h"
#include "Button.h"
#include "SpeakerStereo3W.h"


// Pin Definitions
#define LCD_PIN_RS	7
#define LCD_PIN_E	6
#define LCD_PIN_DB4	2
#define LCD_PIN_DB5	3
#define LCD_PIN_DB6	4
#define LCD_PIN_DB7	5
#define POTENTIOMETER_5V_PIN_SIG	A3
#define PUSHBUTTON_1_PIN_2	8
#define PUSHBUTTON_2_PIN_2	9
#define PUSHBUTTON_3_PIN_2	10
#define STEREOSPEAKER_1_PIN_POS	11
#define STEREOSPEAKER_2_PIN_POS	12



// Global variables and defines
unsigned int StereoSpeaker_1HoorayLength          = 6;                                                      // amount of notes in melody
unsigned int StereoSpeaker_1HoorayMelody[]        = {NOTE_C4, NOTE_E4, NOTE_G4, NOTE_C5, NOTE_G4, NOTE_C5}; // list of notes. List length must match HoorayLength!
unsigned int StereoSpeaker_1HoorayNoteDurations[] = {8      , 8      , 8      , 4      , 8      , 4      }; // note durations; 4 = quarter note, 8 = eighth note, etc. List length must match HoorayLength!
unsigned int StereoSpeaker_2HoorayLength          = 6;                                                      // amount of notes in melody
unsigned int StereoSpeaker_2HoorayMelody[]        = {NOTE_C4, NOTE_E4, NOTE_G4, NOTE_C5, NOTE_G4, NOTE_C5}; // list of notes. List length must match HoorayLength!
unsigned int StereoSpeaker_2HoorayNoteDurations[] = {8      , 8      , 8      , 4      , 8      , 4      }; // note durations; 4 = quarter note, 8 = eighth note, etc. List length must match HoorayLength!
// object initialization
LiquidCrystal lcd(LCD_PIN_RS,LCD_PIN_E,LCD_PIN_DB4,LCD_PIN_DB5,LCD_PIN_DB6,LCD_PIN_DB7);
Potentiometer potentiometer_5v(POTENTIOMETER_5V_PIN_SIG);
Button pushButton_1(PUSHBUTTON_1_PIN_2);
Button pushButton_2(PUSHBUTTON_2_PIN_2);
Button pushButton_3(PUSHBUTTON_3_PIN_2);
SpeakerStereo3W StereoSpeaker_1(STEREOSPEAKER_1_PIN_POS);
SpeakerStereo3W StereoSpeaker_2(STEREOSPEAKER_2_PIN_POS);


// define vars for testing menu
const int timeout = 10000;       //define timeout of 10 sec
char menuOption = 0;
long time0;

// Setup the essentials for your circuit to work. It runs first every time your circuit is powered with electricity.
void setup() 
{
    // Setup Serial which is useful for debugging
    // Use the Serial Monitor to view printed messages
    Serial.begin(9600);
    while (!Serial) ; // wait for serial port to connect. Needed for native USB
    Serial.println("start");
    
    // set up the LCD's number of columns and rows
    lcd.begin(16, 2);
    pushButton_1.init();
    pushButton_2.init();
    pushButton_3.init();
    menuOption = menu();
    
}

// Main logic of your circuit. It defines the interaction between the components you selected. After setup, it runs over and over again, in an eternal loop.
void loop() 
{
    
    
    if(menuOption == '1') {
    // LCD 16x2 - Test Code
    // Print a message to the LCD.
    lcd.setCursor(0, 0);
    lcd.print("Circuito Rocks !");
    // Turn off the display:
    lcd.noDisplay();
    delay(500);
    // Turn on the display:
    lcd.display();
    delay(500);
    }
    else if(menuOption == '2') {
    // Rotary Potentiometer - 10k Ohm, Linear - Test Code
    int potentiometer_5vVal = potentiometer_5v.read();
    Serial.print(F("Val: ")); Serial.println(potentiometer_5vVal);

    }
    else if(menuOption == '3') {
    // Mini Pushbutton Switch #1 - Test Code
    //Read pushbutton state. 
    //if button is pressed function will return HIGH (1). if not function will return LOW (0). 
    //for debounce funtionality try also pushButton_1.onPress(), .onRelease() and .onChange().
    //if debounce is not working properly try changing 'debounceDelay' variable in Button.h
    bool pushButton_1Val = pushButton_1.read();
    Serial.print(F("Val: ")); Serial.println(pushButton_1Val);

    }
    else if(menuOption == '4') {
    // Mini Pushbutton Switch #2 - Test Code
    //Read pushbutton state. 
    //if button is pressed function will return HIGH (1). if not function will return LOW (0). 
    //for debounce funtionality try also pushButton_2.onPress(), .onRelease() and .onChange().
    //if debounce is not working properly try changing 'debounceDelay' variable in Button.h
    bool pushButton_2Val = pushButton_2.read();
    Serial.print(F("Val: ")); Serial.println(pushButton_2Val);

    }
    else if(menuOption == '5') {
    // Mini Pushbutton Switch #3 - Test Code
    //Read pushbutton state. 
    //if button is pressed function will return HIGH (1). if not function will return LOW (0). 
    //for debounce funtionality try also pushButton_3.onPress(), .onRelease() and .onChange().
    //if debounce is not working properly try changing 'debounceDelay' variable in Button.h
    bool pushButton_3Val = pushButton_3.read();
    Serial.print(F("Val: ")); Serial.println(pushButton_3Val);

    }
    else if(menuOption == '6') {
    // 3W Stereo Speaker #1 - Test Code
    // The Speaker will play the Hooray tune
    StereoSpeaker_1.playMelody(StereoSpeaker_1HoorayLength, StereoSpeaker_1HoorayMelody, StereoSpeaker_1HoorayNoteDurations); 
    delay(500);   
    }
    else if(menuOption == '7') {
    // 3W Stereo Speaker #2 - Test Code
    // The Speaker will play the Hooray tune
    StereoSpeaker_2.playMelody(StereoSpeaker_2HoorayLength, StereoSpeaker_2HoorayMelody, StereoSpeaker_2HoorayNoteDurations); 
    delay(500);   
    }
    
    if (millis() - time0 > timeout)
    {
        menuOption = menu();
    }
    
}



// Menu function for selecting the components to be tested
// Follow serial monitor for instrcutions
char menu()
{

    Serial.println(F("\nWhich component would you like to test?"));
    Serial.println(F("(1) LCD 16x2"));
    Serial.println(F("(2) Rotary Potentiometer - 10k Ohm, Linear"));
    Serial.println(F("(3) Mini Pushbutton Switch #1"));
    Serial.println(F("(4) Mini Pushbutton Switch #2"));
    Serial.println(F("(5) Mini Pushbutton Switch #3"));
    Serial.println(F("(6) 3W Stereo Speaker #1"));
    Serial.println(F("(7) 3W Stereo Speaker #2"));
    Serial.println(F("(menu) send anything else or press on board reset button\n"));
    while (!Serial.available());

    // Read data from serial monitor if received
    while (Serial.available()) 
    {
        char c = Serial.read();
        if (isAlphaNumeric(c)) 
        {   
            
            if(c == '1') 
    			Serial.println(F("Now Testing LCD 16x2"));
    		else if(c == '2') 
    			Serial.println(F("Now Testing Rotary Potentiometer - 10k Ohm, Linear"));
    		else if(c == '3') 
    			Serial.println(F("Now Testing Mini Pushbutton Switch #1"));
    		else if(c == '4') 
    			Serial.println(F("Now Testing Mini Pushbutton Switch #2"));
    		else if(c == '5') 
    			Serial.println(F("Now Testing Mini Pushbutton Switch #3"));
    		else if(c == '6') 
    			Serial.println(F("Now Testing 3W Stereo Speaker #1"));
    		else if(c == '7') 
    			Serial.println(F("Now Testing 3W Stereo Speaker #2"));
            else
            {
                Serial.println(F("illegal input!"));
                return 0;
            }
            time0 = millis();
            return c;
        }
    }
}

/*******************************************************

*    Circuito.io is an automatic generator of schematics and code for off
*    the shelf hardware combinations.

*    Copyright (C) 2016 Roboplan Technologies Ltd.

*    This program is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.

*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.

*    You should have received a copy of the GNU General Public License
*    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*    In addition, and without limitation, to the disclaimers of warranties 
*    stated above and in the GNU General Public License version 3 (or any 
*    later version), Roboplan Technologies Ltd. ("Roboplan") offers this 
*    program subject to the following warranty disclaimers and by using 
*    this program you acknowledge and agree to the following:
*    THIS PROGRAM IS PROVIDED ON AN "AS IS" AND "AS AVAILABLE" BASIS, AND 
*    WITHOUT WARRANTIES OF ANY KIND EITHER EXPRESS OR IMPLIED.  ROBOPLAN 
*    HEREBY DISCLAIMS ALL WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT 
*    NOT LIMITED TO IMPLIED WARRANTIES OF MERCHANTABILITY, TITLE, FITNESS 
*    FOR A PARTICULAR PURPOSE, NON-INFRINGEMENT, AND THOSE ARISING BY 
*    STATUTE OR FROM A COURSE OF DEALING OR USAGE OF TRADE. 
*    YOUR RELIANCE ON, OR USE OF THIS PROGRAM IS AT YOUR SOLE RISK.
*    ROBOPLAN DOES NOT GUARANTEE THAT THE PROGRAM WILL BE FREE OF, OR NOT 
*    SUSCEPTIBLE TO, BUGS, SECURITY BREACHES, OR VIRUSES. ROBOPLAN DOES 
*    NOT WARRANT THAT YOUR USE OF THE PROGRAM, INCLUDING PURSUANT TO 
*    SCHEMATICS, INSTRUCTIONS OR RECOMMENDATIONS OF ROBOPLAN, WILL BE SAFE 
*    FOR PERSONAL USE OR FOR PRODUCTION OR COMMERCIAL USE, WILL NOT 
*    VIOLATE ANY THIRD PARTY RIGHTS, WILL PROVIDE THE INTENDED OR DESIRED
*    RESULTS, OR OPERATE AS YOU INTENDED OR AS MAY BE INDICATED BY ROBOPLAN. 
*    YOU HEREBY WAIVE, AGREE NOT TO ASSERT AGAINST, AND RELEASE ROBOPLAN, 
*    ITS LICENSORS AND AFFILIATES FROM, ANY CLAIMS IN CONNECTION WITH ANY OF 
*    THE ABOVE. 
********************************************************/