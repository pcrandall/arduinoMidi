#include <Tone.h>

#define Speaker_Left 12
#define Speaker_Right 11
#define Led_Left 10
#define Led_Right 9
#define Led_Start 8

#define MI3    165
#define FA3    175
#define FA_d3  185
#define SOL3   196
#define SOL_d3 208
#define LA3    220
#define LA_d3  233
#define SI3    247
#define DO4    262
#define DO_d4  277
#define RE4    294
#define RE_d4  311
#define MI4    330
#define FA4    349
#define FA_d4  370
#define SOL4   392
#define SOL_d4 415
#define LA4    440
#define LA_d4  466
#define SI4    494
#define DO5    523
#define DO_d5  554
#define RE5    587
#define RE_d5  622
#define MI5    659
#define FA5    698
#define FA_d5  740
#define SOL5   784
#define SOL_d5 831
#define LA5    880
#define LA_d5  932
#define SI5    988
#define DO6    1046
#define DO_d6  1109
#define RE6    1175
#define RE_d6  1245
#define MI6    1319
#define FA6    1397
#define FA_d6  1480
#define SOL6   1568
#define SOL_d6 1661
#define LA6   1760
#define LA_d6  1865

int tempo = 120;
int redonda = 240000 / tempo;
int blancapto = 180000 / tempo;
int blanca = 120000 / tempo;
int negrapto = 90000 / tempo;
int negra = 60000 / tempo;
int corcheapto = 45000 / tempo;
int corchea = 30000 / tempo;
int semicopto = 22500 / tempo;
int semico = 15000 / tempo;

Tone left;
Tone right;

void setup() {
  pinMode(playButton, INPUT_PULLUP);
  pinMode(Led_Start, OUTPUT);
  pinMode(Led_Left, OUTPUT);
  pinMode(Led_Right, OUTPUT);
  left.begin(Speaker_Left);
  right.begin(Speaker_Right);
}

void loop() {
    while (1){
        playButton(2); // wait for play to be pressed
    }
}

void playButton(int buttonPin){
    int buttonState = 0;
    while (1){
        buttonState = digitalRead(buttonPin);
        if (buttonState == HIGH){
            return;
        }
    }
}

void playTitanic(){
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

void playStereo(int _left, int _right, int tempo) {
  int timeDelay = tempo - 4;
  left.play(_left, tempo);
  right.play(_right, tempo);
  digitalWrite(Led_Left, HIGH);
  digitalWrite(Led_Right, HIGH);
  delay(timeDelay);
  digitalWrite(Led_Left, LOW);
  digitalWrite(Led_Right, LOW);
  delay(5);
}

void playMono(int _left, int tempo) {
  int timeDelay = tempo - 4;
  left.play(_left, tempo);
  digitalWrite(Led_Left, HIGH);
  delay(timeDelay);
  digitalWrite(Led_Left, LOW);
  delay(5);
}

void silence(int tempo) {
  int timeDelay = tempo - 4;
  delay(timeDelay);
}

void titanic1() {
  playStereo(MI5, MI4, negrapto);
  playStereo(SI3, MI4, corchea);
  playStereo(MI5, MI4, negra);
  playStereo(MI5, MI4, negra);
  playStereo(SI3, RE_d5, negra);
  playStereo(SI3, MI5, corchea);
  playStereo(FA_d3, MI5, corchea);
  playStereo(SI3, MI5, negra);
  playStereo(SI3, MI5, negra);

}
void titanic2() {
  playStereo(LA3, RE_d5, negra);
  playStereo(LA3, MI5, corchea);
  playStereo(MI3, MI5, corchea);
  playStereo(LA3, MI5, negra);
  playStereo(LA3, FA_d5, negra);
  playStereo(SI3, SOL_d5, blanca);
  playStereo(FA_d3, FA_d5, blanca);
}

void titanic3() {
  playStereo(LA3, SI4, negrapto);
  playStereo(MI3, SI4, corchea);
  playStereo(LA3, SI4, negrapto);
  playStereo(MI3, SI4, corchea);
  playStereo(LA3, SI4, negrapto);
  playStereo(MI3, SI4, corchea);
  playStereo(SI3, DO_d5, corchea);
  playStereo(LA3, SI4, corchea);
  playStereo(SOL_d3, DO_d5, corchea);
  playStereo(FA_d3, RE_d5, corchea);
}

void titanic4() {
  playStereo(DO_d4, MI5, negrapto);
  playStereo(SOL_d3, MI5, corchea);
  playStereo(DO_d4, MI5, blanca);
  playStereo(SI3, FA_d5, negrapto);
  playStereo(FA_d3, FA_d5, corchea);
  playStereo(SI3, FA_d5, negra);
  playStereo(SI3, SI4, negra);
  playStereo(LA3, SI5, negrapto);
  playStereo(MI3, SI5, corchea);
  playStereo(LA3, LA5, negra);
  playStereo(SOL_d3, SOL_d5, negra);
  playStereo(SI3, FA_d5, negrapto);
  playStereo(FA_d3, FA_d5, corchea);
  playStereo(SI3, SOL_d5, negra);
  playStereo(FA_d3, LA5, negra);
  playStereo(DO_d4, SOL_d5, negrapto);
  playStereo(SOL_d3, SOL_d5, corchea);
  playStereo(DO_d4, FA_d5, negra);
  playStereo(SOL_d3, MI5, negra);
  playStereo(SI3, RE_d5, negra);
  playStereo(SI3, MI5, corchea);
  playStereo(FA_d3, MI5, corchea);
  playStereo(SI3, MI5, negra);
}

void titanic5() {
  playStereo(FA_d3, MI5, negra);
  playStereo(LA3, RE_d5, negra);
  playStereo(LA3, MI5, corchea);
  playStereo(MI3, MI5, corchea);
  playStereo(LA3, MI5, negra);
  playStereo(LA3, FA_d5, negra);
  playStereo(SI3, SOL_d5, blanca);
  playStereo(FA_d3, FA_d5, blanca);
}

void titanic6() {
  playStereo(FA_d3, RE_d5, negra);
  playStereo(LA3, DO_d5, negrapto);
  playStereo(MI3, DO_d5, corchea);
  playStereo(LA3, DO_d5, negrapto);
  playStereo(MI3, DO_d5, corchea);
  playStereo(LA3, DO_d5, negrapto);
  playStereo(MI3, DO_d5, corchea);
  playStereo(SI3, DO_d5, corchea);
  playStereo(LA3, SI4, corchea);
  playStereo(SOL_d3, DO_d5, corchea);
  playStereo(FA_d3, RE_d5, corchea);
}
