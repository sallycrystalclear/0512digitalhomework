#include "pitches.h"




int melody0[] = {
  NOTE_C4, NOTE_C4, NOTE_C4, NOTE_E4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_E4,  NOTE_E4, NOTE_E4, NOTE_G4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_B3,
};


int noteDurations[] = {
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1
};
int melody1[]={
NOTE_A3, NOTE_C4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_G4, NOTE_E4, NOTE_A4, NOTE_C4, NOTE_E4, NOTE_D4, NOTE_A4, NOTE_A5,  
};
int noteDurationsD[] = {
  4, 4, 4, 8, 4, 4, 8, 4, 4, 2, 4, 4, 2, 4, 4, 2
};
int melodynum=0;
#define BUTTON 6
byte presentState=1, previousState=1, patternNumber=0;


void setup() {
  pinMode(6,INPUT_PULLUP);
}


void loop() {
 
  if(melodynum==0)
  {
    for (int thisNote = 0; thisNote < 16; thisNote++)
    {
      int noteDuration = 1000 / noteDurations[thisNote];
      tone(8, melody0[thisNote], noteDuration);


      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      noTone(8);
      presentState=digitalRead(6);
      if(presentState==0&&previousState==1)
      {
        melodynum=melodynum+1;
        break;
      }
      previousState==presentState;
    }
  }
  if(melodynum==1)
  {
    for (int thisNote = 0; thisNote < 16; thisNote++)
    {
      int noteDuration = 1000 / noteDurationsD[thisNote];
      tone(8, melody1[thisNote], noteDuration);


      int pauseBetweenNotes = noteDuration * 1.30;


      delay(pauseBetweenNotes);
      noTone(8);
      presentState=digitalRead(6);
      if(presentState==0&&previousState==1)
      {
        melodynum=melodynum-1;
        break;
      }
      previousState==presentState;
  }
  }
}

