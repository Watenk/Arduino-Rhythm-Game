#pragma once

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#include "Note.h"

class Speaker{
  public:
    Speaker();
    void initialize(Adafruit_PWMServoDriver* _pwm, int i);
    void fixedUpdate();
    void play(Note note);

    bool busy;
    int speakerID;

  private:
  Adafruit_PWMServoDriver* pwm;
  int toneLenght = 0;
  int fixedUpdateLenght;
};