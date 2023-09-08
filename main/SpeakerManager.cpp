#include "SpeakerManager.h"
#include "Arduino.h"

SpeakerManager::SpeakerManager(){

}

void SpeakerManager::update(){

  unsigned long timeSinceStart = micros();

  for (int i = 0; i < speakerArraySize; i++){
    if (speakers[i].isBusy){
      Serial.print("RemainingPlayTime: ");
      Serial.println(speakers[i].remainingPlayTime);
      Serial.print("TimeSinceStart: ");
      Serial.println(timeSinceStart);
      Serial.print("previousUpdate: ");
      Serial.println(speakers[i].previousUpdate);
      Serial.println(" ");

      if (speakers[i].remainingPlayTime > 0){
        if (timeSinceStart - speakers[i].previousUpdate >= speakers[i].speakerHalfPeriod){
          if (speakers[i].previousUpdate != 0){
            speakers[i].remainingPlayTime -= timeSinceStart - speakers[i].previousUpdate;
          }
          speakers[i].previousUpdate = timeSinceStart;

          if (speakers[i].pinPower == 0){
            speakers[i].pinPower = 1;
          }
          else{
            speakers[i].pinPower = 0;
          }

          digitalWrite(speakers[i].pin, speakers[i].pinPower);
        }
      }
      else{
        speakers[i].isBusy = false;
      }
    }
  }
}

void SpeakerManager::play(int note, int lenght){

  if (!speakers[0].isBusy){
    playNote(0, note, lenght);
  }
  else if (!speakers[1].isBusy){
    playNote(1, note, lenght);
  }
  else if (!speakers[2].isBusy){
    playNote(2, note, lenght);
  }
  else if (!speakers[3].isBusy){
    playNote(3, note, lenght);
  }
}

void SpeakerManager::playNote(int speakerIndex, int note, int lenght){
  speakers[speakerIndex].isBusy = true;
  speakers[speakerIndex].speakerFreq = note;
  speakers[speakerIndex].remainingPlayTime = lenght;
  speakers[speakerIndex].speakerHalfPeriod = (1000000 / note) / 2;
}