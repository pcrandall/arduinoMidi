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

bool btnPrevious, btnPlayPause, btnNext;
bool PLAY = false;
Tone left;
Tone right;

void setup() {
  Serial.begin(9600);
  pinMode(Led_Start, OUTPUT);
  pinMode(Led_Left, OUTPUT);
  pinMode(Led_Right, OUTPUT);
  left.begin(Speaker_Left);
  right.begin(Speaker_Right);

  // Prepare the buttons to control the player
  btnPrevious = 0;
  pinMode(2, INPUT);

  btnPlayPause = 0;
  pinMode(3, INPUT);

  btnNext = 0;
  pinMode(4, INPUT);

}

void loop() {

  /* // Check the three buttons that control the player */
  /* btn = digitalRead(2); */
  /* if (btn != btnPrevious) */
  /* { */
  /*   if (btn != 0) */
  /*   { */
  /*     // Skip to the previous song */
  /*   } */
  /*   btnPrevious = btn; */
  /*   // Simple debounce for the button */
  /*   delay(100); */
  /* } */

  /* btn = digitalRead(3); */
  /* if (btn != btnPlayPause) */
  /* { */
  /*   if (btn != 0) */
  /*   { */
  /*     // Either play or pause the player */
  /*   } */
  /*   btnPlayPause = btn; */
  /*   // Simple debounce for the button */
  /*   delay(100); */
  /* } */

  /* btn = digitalRead(4); */
  /* if (btn != btnNext) */
  /* { */
  /*   if (btn != 0) */
  /*   { */
  /*     // Skip to the next song */
  /*   } */
  /*   btnNext = btn; */
  /*   // Simple debounce for the button */
  /*   delay(100); */
  /* } */
  Serial.println("INIT");
  while (1) {

    playTitanic();
  }
}

bool playButton(int buttonPin, bool playing) {
  while (1) {
    btnPlayPause = digitalRead(buttonPin);
    if (btnPlayPause == LOW) {
      playing = !playing;
    }
    if (playing == true) {
      Serial.println("Play");
      return true;
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

void playNotes(int _left, int _right, int _duration) {
  if (playButton(2, PLAY) == true) {
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

}

void silence(int _duration) {
  int timeDelay = _duration - 4;
  delay(timeDelay);
}

void titanic1() {
  Serial.println("TITANIC1");
  playNotes(NOTE_E5, NOTE_E4, threeEighths);
  playNotes(NOTE_B3, NOTE_E4, eighth);
  playNotes(NOTE_E5, NOTE_E4, quarter);
  playNotes(NOTE_E5, NOTE_E4, quarter);
  playNotes(NOTE_B3, NOTE_DS5, quarter);
  playNotes(NOTE_B3, NOTE_E5, eighth);
  playNotes(NOTE_FS3, NOTE_E5, eighth);
  playNotes(NOTE_B3, NOTE_E5, quarter);
  playNotes(NOTE_B3, NOTE_E5, quarter);

}

void titanic2() {
  Serial.println("TITANIC2");
  playNotes(NOTE_A3, NOTE_DS5, quarter);
  playNotes(NOTE_A3, NOTE_E5, eighth);
  playNotes(NOTE_E3, NOTE_E5, eighth);
  playNotes(NOTE_A3, NOTE_E5, quarter);
  playNotes(NOTE_A3, NOTE_FS5, quarter);
  playNotes(NOTE_B3, NOTE_GS5, half);
  playNotes(NOTE_FS3, NOTE_FS5, half);
}

void titanic3() {
  Serial.println("TITANIC3");
  playNotes(NOTE_A3, NOTE_B4, threeEighths);
  playNotes(NOTE_E3, NOTE_B4, eighth);
  playNotes(NOTE_A3, NOTE_B4, threeEighths);
  playNotes(NOTE_E3, NOTE_B4, eighth);
  playNotes(NOTE_A3, NOTE_B4, threeEighths);
  playNotes(NOTE_E3, NOTE_B4, eighth);
  playNotes(NOTE_B3, NOTE_CS5, eighth);
  playNotes(NOTE_A3, NOTE_B4, eighth);
  playNotes(NOTE_GS3, NOTE_CS5, eighth);
  playNotes(NOTE_FS3, NOTE_DS5, eighth);
}

void titanic4() {
  Serial.println("TITANIC4");
  playNotes(NOTE_CS4, NOTE_E5, threeEighths);
  playNotes(NOTE_GS3, NOTE_E5, eighth);
  playNotes(NOTE_CS4, NOTE_E5, half);
  playNotes(NOTE_B3, NOTE_FS5, threeEighths);
  playNotes(NOTE_FS3, NOTE_FS5, eighth);
  playNotes(NOTE_B3, NOTE_FS5, quarter);
  playNotes(NOTE_B3, NOTE_B4, quarter);
  playNotes(NOTE_A3, NOTE_B5, threeEighths);
  playNotes(NOTE_E3, NOTE_B5, eighth);
  playNotes(NOTE_A3, NOTE_A5, quarter);
  playNotes(NOTE_GS3, NOTE_GS5, quarter);
  playNotes(NOTE_B3, NOTE_FS5, threeEighths);
  playNotes(NOTE_FS3, NOTE_FS5, eighth);
  playNotes(NOTE_B3, NOTE_GS5, quarter);
  playNotes(NOTE_FS3, NOTE_A5, quarter);
  playNotes(NOTE_CS4, NOTE_GS5, threeEighths);
  playNotes(NOTE_GS3, NOTE_GS5, eighth);
  playNotes(NOTE_CS4, NOTE_FS5, quarter);
  playNotes(NOTE_GS3, NOTE_E5, quarter);
  playNotes(NOTE_B3, NOTE_DS5, quarter);
  playNotes(NOTE_B3, NOTE_E5, eighth);
  playNotes(NOTE_FS3, NOTE_E5, eighth);
  playNotes(NOTE_B3, NOTE_E5, quarter);
}

void titanic5() {
  Serial.println("TITANIC5");
  playNotes(NOTE_FS3, NOTE_E5, quarter);
  playNotes(NOTE_A3, NOTE_DS5, quarter);
  playNotes(NOTE_A3, NOTE_E5, eighth);
  playNotes(NOTE_E3, NOTE_E5, eighth);
  playNotes(NOTE_A3, NOTE_E5, quarter);
  playNotes(NOTE_A3, NOTE_FS5, quarter);
  playNotes(NOTE_B3, NOTE_GS5, half);
  playNotes(NOTE_FS3, NOTE_FS5, half);
}

void titanic6() {
  Serial.println("TITANIC6");
  playNotes(NOTE_FS3, NOTE_DS5, quarter);
  playNotes(NOTE_A3, NOTE_CS5, threeEighths);
  playNotes(NOTE_E3, NOTE_CS5, eighth);
  playNotes(NOTE_A3, NOTE_CS5, threeEighths);
  playNotes(NOTE_E3, NOTE_CS5, eighth);
  playNotes(NOTE_A3, NOTE_CS5, threeEighths);
  playNotes(NOTE_E3, NOTE_CS5, eighth);
  playNotes(NOTE_B3, NOTE_CS5, eighth);
  playNotes(NOTE_A3, NOTE_B4, eighth);
  playNotes(NOTE_GS3, NOTE_CS5, eighth);
  playNotes(NOTE_FS3, NOTE_DS5, eighth);
}
