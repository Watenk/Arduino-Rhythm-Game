#pragma once

class Speaker{
  public:
    Speaker(int pin);

    bool isBusy; 
    int pinPower;
    int pin;
    int speakerFreq;
    int speakerHalfPeriod;
    long remainingPlayTime;
    unsigned long previousUpdate;

  private:

};