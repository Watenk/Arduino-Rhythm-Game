#pragma once

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#include "Note.h"
#include "Settings.h"

class SpeakerManager{
  public:
    SpeakerManager();
    void play(Note note);

  private:
  Adafruit_PWMServoDriver pwm;
};