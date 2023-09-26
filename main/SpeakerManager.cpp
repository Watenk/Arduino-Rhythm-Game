#include "SpeakerManager.h"
#include "notes.h"
#include "Settings.h"
#include "Arduino.h"

#include <TimerOne.h>
#include <TimerTwo.h>

//Add extra timers???

SpeakerManager::SpeakerManager(){
  //Timer1
  Timer1.initialize(1000000); //Timer update Speed in microSeconds
  Timer1.attachInterrupt(updateSpeaker1);
  Timer1.start(); 

  //Timer2
  Timer2.initialize(1000000);
  Timer2.attachInterrupt(updateSpeaker2);
  Timer2.start();
}

void SpeakerManager::play(Note note){
  Timer1.setPeriod(1000000 / (NoteC4 * 2));
  Timer2.setPeriod(1000000 / (NoteE4 * 2));
}

static void SpeakerManager::updateSpeaker1(){

  static bool stateSpeaker1 = false;
  digitalWrite(Speaker1, stateSpeaker1);
  stateSpeaker1 = !stateSpeaker1;
}

static void SpeakerManager::updateSpeaker2(){

  static bool stateSpeaker2 = false;
  digitalWrite(Speaker2, stateSpeaker2);
  stateSpeaker2 = !stateSpeaker2;
}