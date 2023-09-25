#pragma once

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#include "Note.h"
#include "Settings.h"
#include "Speaker.h"

class SpeakerManager{
  public:
    SpeakerManager();
    void play(Note note);
    void fixedUpdate();

  private:
  Adafruit_PWMServoDriver pwm;
  Speaker* speakers[SpeakerAmount];
};