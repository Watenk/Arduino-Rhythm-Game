#include "SpeakerManager.h"

SpeakerManager::SpeakerManager(){
  pwm = Adafruit_PWMServoDriver();
  pwm.begin();
  pwm.setPWMFreq(1000); //Between 1000 (1kHZ) and 2000 (2kHZ)
}

void SpeakerManager::play(Note note){
  int pwmValue = 523;
  pwm.setPWM(0, 0, pwmValue);
}