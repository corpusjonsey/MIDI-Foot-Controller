/* DMC-6 Octatrack Firmware v1.0

  1:  INAB rec #61
  2:  Pickup Play/Stop #64
  3:  Active track down #69
  4:  Seq Start/Stop #34
  5:  Toggle Seq sync+start #71
  6:  Active track up #68

*/

#include <MIDI.h>
#include <Bounce.h>

#define BTN1 2
#define BTN2 3
#define BTN3 4
#define BTN4 5
#define BTN5 6
#define BTN6 7

#define LED1 9
#define LED2 14
#define LED3 15
#define LED4 16
#define LED5 17
#define LED6 13

#define MIDI_CHANNEL 9 // MIDI channel = Octatrack autochannel 9

int ledArray[] = {9, 14, 15, 16, 17, 13};
int ledVal[] = {0, 0, 0, 0, 0, 0};
int state = -1;

// Instantiate six debounce objects, 25 millisecond bounce time
Bounce bounce1 = Bounce(BTN1, 25);
Bounce bounce2 = Bounce(BTN2, 25);
Bounce bounce3 = Bounce(BTN3, 25);
Bounce bounce4 = Bounce(BTN4, 25);
Bounce bounce5 = Bounce(BTN5, 25);
Bounce bounce6 = Bounce(BTN6, 25);

MIDI_CREATE_DEFAULT_INSTANCE();

void setup() {
  MIDI.begin(MIDI_CHANNEL_OFF);

  pinMode(BTN1, INPUT); //define buttons as inputs
  pinMode(BTN2, INPUT);
  pinMode(BTN3, INPUT);
  pinMode(BTN4, INPUT);
  pinMode(BTN5, INPUT);
  pinMode(BTN6, INPUT);

  pinMode(LED1, OUTPUT); //define LEDs as outputs
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);

  digitalWrite(BTN1, HIGH); //button initial state is "HIGH"
  digitalWrite(BTN2, HIGH);
  digitalWrite(BTN3, HIGH);
  digitalWrite(BTN4, HIGH);
  digitalWrite(BTN5, HIGH);
  digitalWrite(BTN6, HIGH);

  //LED light show at startup.
  for (int i = 0; i < 3; i++) {
    digitalWrite(LED1, HIGH);
    delay(10);
    digitalWrite(LED4, LOW);
    delay(100);
    digitalWrite(LED2, HIGH);
    delay(10);
    digitalWrite(LED1, LOW);
    delay(100);
    digitalWrite(LED3, HIGH);
    delay(10);
    digitalWrite(LED2, LOW);
    delay(100);
    digitalWrite(LED6, HIGH);
    delay(10);
    digitalWrite(LED3, LOW);
    delay(100);
    digitalWrite(LED5, HIGH);
    delay(10);
    digitalWrite(LED6, LOW);
    delay(100);
    digitalWrite(LED4, HIGH);
    delay(10);
    digitalWrite(LED5, LOW);
    delay(100);
  }
}

void loop() {

  for (int i = 0; i < 6; i++) {
    digitalWrite(ledArray[i], ledVal[i]); //update LEDs
    ledVal[i] = 0;
  }
  delay(100);
  for (int i = 0; i < 6; i++) {
    digitalWrite(ledArray[i], ledVal[i]); //turn off LEDs
  }

  if (bounce1.update() ) { //if there is a button press
    if (bounce1.read() == LOW ) { //if button 1 is pressed
      midiNote(61); //send note
      state = 0; //update state
      ledVal[state] = 1;
    }
  }

  if (bounce2.update() ) {
    if (bounce2.read() == LOW ) { //if button 2 is pressed
      midiNote(64);
      state = 1;
      ledVal[state] = 1;
    }
  }

  if (bounce3.update() ) {
    if (bounce3.read() == LOW ) { //if button 3 is pressed
      midiNote(69);
      state = 2;
      ledVal[state] = 1;
    }
  }

  if (bounce4.update() ) {
    if (bounce4.read() == LOW ) { //if button 4 is pressed
      midiNote(34);
      state = 3;
      ledVal[state] = 1;
    }
  }

  if (bounce5.update() ) {
    if (bounce5.read() == LOW ) { //if button 5 is pressed
      midiNote(71);
      state = 4;
      ledVal[state] = 1;
    }
  }

  if (bounce6.update() ) {
    if (bounce6.read() == LOW ) {  //if button 6 is pressed
      midiNote(68);
      state = 5;
      ledVal[state] = 1;
    }
  }
}

void midiNote(int note) {
  MIDI.sendNoteOn(note, 127, MIDI_CHANNEL);
  delay(5);
  MIDI.sendNoteOff(note, 0, MIDI_CHANNEL);
}
