#include "SpeakerManager.h"
#include "Arduino.h"

#include <TimerOne.h>
#include <TimerTwo.h>

//Add extra timers???

SpeakerManager::SpeakerManager(){
  //Timer1
  Timer1.initialize(1000000); 
  Timer1.attachInterrupt(updateSpeaker1);
  Timer1.stop();

  //Timer2
  Timer2.initialize(1000000);
  Timer2.attachInterrupt(updateSpeaker2);
  Timer2.stop();
}

void SpeakerManager::playNote(Note note){

  if (!speaker1Busy){
    speaker1Play(note);
  }
  else if (!speaker2Busy){
    speaker2Play(note);
  }
  else{
    Serial.print("Note with frequency ");
    Serial.print(note.note);
    Serial.println(" Skipped Because all speakers are busy");
  }
}

//Play a note///////////////////////////////////////////////////////

void SpeakerManager::speaker1Play(Note note){
  Timer1.setPeriod(1000000 / (note.note * 2));
  speaker1RemainingTime = note.lenght;
  speaker1Busy = true;
  Timer1.start(); 
}

void SpeakerManager::speaker2Play(Note note){
  Timer2.setPeriod(1000000 / (note.note * 2));
  speaker2RemainingTime = note.lenght;
  speaker2Busy = true;
  Timer2.start();
}

//Update the speakerLenghtTimers/////////////////////////////////////

void SpeakerManager::update(Time* time){
  //Speaker1
  if (speaker1Busy){
    speaker1RemainingTime -= time->updateTime;

    if (speaker1RemainingTime <= 0){
      speaker1Busy = false;
      Timer1.stop();
    }
  }

  //Speaker2
  if (speaker2Busy){
    speaker2RemainingTime -= time->updateTime;

    if (speaker2RemainingTime <= 0){
      speaker2Busy = false;
      Timer2.stop();
    }
  }
}

//Update the speakersToneGeneration//////////////////////////////////

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

