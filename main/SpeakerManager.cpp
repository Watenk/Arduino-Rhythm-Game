#include "SpeakerManager.h"
#include "notes.h"
#include "Settings.h"
#include "Arduino.h"

#include <TimerOne.h>

SpeakerManager::SpeakerManager(){
  for (int i = 0; i < SpeakerAmount; i++){
    speakers[i] = new Speaker();
  }
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(update);
}

void SpeakerManager::play(Note note){

  Timer1.setPeriod(1000000 / (note.note * 2));
  toneDuration = note.lenght; // Set the duration of the tone
  toneStartTime = millis(); // Record the start time
  Timer1.start(); // Start the timer to generate the tone

// //Find avaible Speaker and play note
//   for (int i = 0; i < SpeakerAmount; i++){
//     Speaker* currentSpeaker = speakers[i];

//     if (!currentSpeaker->busy){
//       currentSpeaker->play(note);
//       break;
//     }
//   }
}

static void SpeakerManager::update(){
  static bool state = false;
  digitalWrite(11, state);
  state = !state;

  // for (int i = 0; i < SpeakerAmount; i++){
  //   speakers[i]->update();
  // }
}