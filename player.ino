#include <Tone.h>

#define Speaker_Left 12
#define Speaker_Right 11
#define Led_Left 10
#define Led_Right 9
#define Led_Start 8

int Bpm = 120;
int whole = 240000 / Bpm;
int threeQuarters = 180000 / Bpm;
int half = 120000 / Bpm;
int threeEighths = 90000 / Bpm;
int quarter = 60000 / Bpm;
int eighth = 30000 / Bpm;

Tone left;
Tone right;

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  pinMode(Led_Start, OUTPUT);
  pinMode(Led_Left, OUTPUT);
  pinMode(Led_Right, OUTPUT);
  left.begin(Speaker_Left);
  right.begin(Speaker_Right);
}

void loop() {
  Serial.println("INIT");
  while (1) {
    playButton(2); // wait for play to be pressed
  }
}

void playButton(int buttonPin) {
  int buttonState = 0;
  while (1) {
    buttonState = digitalRead(buttonPin);
    if (buttonState == HIGH) {
      playTitanic();
      return;
    }
  }
}

void playTitanic() {

  Serial.println("NOW PLAYING TITANIC");
  titanic1();
  titanic2();
  titanic1();
  titanic3();
  titanic1();
  titanic2();
  titanic1();
  titanic3();
  titanic4();
  titanic6();
  titanic4();
  titanic5();
}

void playStereo(int _left, int _right, int _duration) {
  int timeDelay = _duration - 4;
  left.play(_left, _duration);
  right.play(_right, _duration);
  digitalWrite(Led_Left, HIGH);
  digitalWrite(Led_Right, HIGH);
  delay(timeDelay);
  digitalWrite(Led_Left, LOW);
  digitalWrite(Led_Right, LOW);
  delay(5);
}

void silence(int _duration) {
  int timeDelay = _duration - 4;
  delay(timeDelay);
}

void titanic1() {

  Serial.println("NOW PLAYING TITANIC1");
  playStereo(NOTE_E5, NOTE_E4, threeEighths);
  playStereo(NOTE_B3, NOTE_E4, eighth);
  playStereo(NOTE_E5, NOTE_E4, quarter);
  playStereo(NOTE_E5, NOTE_E4, quarter);
  playStereo(NOTE_B3, NOTE_DS5, quarter);
  playStereo(NOTE_B3, NOTE_E5, eighth);
  playStereo(NOTE_FS3, NOTE_E5, eighth);
  playStereo(NOTE_B3, NOTE_E5, quarter);
  playStereo(NOTE_B3, NOTE_E5, quarter);

}

void titanic2() {
  Serial.println("NOW PLAYING TITANIC2");
  playStereo(NOTE_A3, NOTE_DS5, quarter);
  playStereo(NOTE_A3, NOTE_E5, eighth);
  playStereo(NOTE_E3, NOTE_E5, eighth);
  playStereo(NOTE_A3, NOTE_E5, quarter);
  playStereo(NOTE_A3, NOTE_FS5, quarter);
  playStereo(NOTE_B3, NOTE_GS5, half);
  playStereo(NOTE_FS3, NOTE_FS5, half);
}

void titanic3() {
  Serial.println("NOW PLAYING TITANIC3");
  playStereo(NOTE_A3, NOTE_B4, threeEighths);
  playStereo(NOTE_E3, NOTE_B4, eighth);
  playStereo(NOTE_A3, NOTE_B4, threeEighths);
  playStereo(NOTE_E3, NOTE_B4, eighth);
  playStereo(NOTE_A3, NOTE_B4, threeEighths);
  playStereo(NOTE_E3, NOTE_B4, eighth);
  playStereo(NOTE_B3, NOTE_CS5, eighth);
  playStereo(NOTE_A3, NOTE_B4, eighth);
  playStereo(NOTE_GS3, NOTE_CS5, eighth);
  playStereo(NOTE_FS3, NOTE_DS5, eighth);
}

void titanic4() {
  Serial.println("NOW PLAYING TITANIC4");
  playStereo(NOTE_CS4, NOTE_E5, threeEighths);
  playStereo(NOTE_GS3, NOTE_E5, eighth);
  playStereo(NOTE_CS4, NOTE_E5, half);
  playStereo(NOTE_B3, NOTE_FS5, threeEighths);
  playStereo(NOTE_FS3, NOTE_FS5, eighth);
  playStereo(NOTE_B3, NOTE_FS5, quarter);
  playStereo(NOTE_B3, NOTE_B4, quarter);
  playStereo(NOTE_A3, NOTE_B5, threeEighths);
  playStereo(NOTE_E3, NOTE_B5, eighth);
  playStereo(NOTE_A3, NOTE_A5, quarter);
  playStereo(NOTE_GS3, NOTE_GS5, quarter);
  playStereo(NOTE_B3, NOTE_FS5, threeEighths);
  playStereo(NOTE_FS3, NOTE_FS5, eighth);
  playStereo(NOTE_B3, NOTE_GS5, quarter);
  playStereo(NOTE_FS3, NOTE_A5, quarter);
  playStereo(NOTE_CS4, NOTE_GS5, threeEighths);
  playStereo(NOTE_GS3, NOTE_GS5, eighth);
  playStereo(NOTE_CS4, NOTE_FS5, quarter);
  playStereo(NOTE_GS3, NOTE_E5, quarter);
  playStereo(NOTE_B3, NOTE_DS5, quarter);
  playStereo(NOTE_B3, NOTE_E5, eighth);
  playStereo(NOTE_FS3, NOTE_E5, eighth);
  playStereo(NOTE_B3, NOTE_E5, quarter);
}

void titanic5() {
  Serial.println("NOW PLAYING TITANIC5");
  playStereo(NOTE_FS3, NOTE_E5, quarter);
  playStereo(NOTE_A3, NOTE_DS5, quarter);
  playStereo(NOTE_A3, NOTE_E5, eighth);
  playStereo(NOTE_E3, NOTE_E5, eighth);
  playStereo(NOTE_A3, NOTE_E5, quarter);
  playStereo(NOTE_A3, NOTE_FS5, quarter);
  playStereo(NOTE_B3, NOTE_GS5, half);
  playStereo(NOTE_FS3, NOTE_FS5, half);
}

void titanic6() {
  Serial.println("NOW PLAYING TITANIC6");
  playStereo(NOTE_FS3, NOTE_DS5, quarter);
  playStereo(NOTE_A3, NOTE_CS5, threeEighths);
  playStereo(NOTE_E3, NOTE_CS5, eighth);
  playStereo(NOTE_A3, NOTE_CS5, threeEighths);
  playStereo(NOTE_E3, NOTE_CS5, eighth);
  playStereo(NOTE_A3, NOTE_CS5, threeEighths);
  playStereo(NOTE_E3, NOTE_CS5, eighth);
  playStereo(NOTE_B3, NOTE_CS5, eighth);
  playStereo(NOTE_A3, NOTE_B4, eighth);
  playStereo(NOTE_GS3, NOTE_CS5, eighth);
  playStereo(NOTE_FS3, NOTE_DS5, eighth);
}
