#include "SpeakerManager.h"
#include "notes.h"
#include "Settings.h"

SpeakerManager::SpeakerManager(){
  pwm = Adafruit_PWMServoDriver();
  pwm.begin();
  pwm.setPWMFreq(PWMFrequency); 

  for (int i = 0; i < SpeakerAmount; i++){
    speakers[i] = new Speaker();
    speakers[i]->initialize(&pwm, i);
  }
}

void SpeakerManager::play(Note note){

//Find avaible Speaker and play note
  for (int i = 0; i < SpeakerAmount; i++){
    Speaker* currentSpeaker = speakers[i];

    if (!currentSpeaker->busy){
      currentSpeaker->play(note);
      break;
    }
  }
}

void SpeakerManager::fixedUpdate(){
  for (int i = 0; i < SpeakerAmount; i++){
    speakers[i]->fixedUpdate();
  }
}