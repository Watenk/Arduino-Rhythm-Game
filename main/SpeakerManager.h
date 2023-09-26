#pragma once

#include "Note.h"
#include "Settings.h"
#include "Speaker.h"

class SpeakerManager{
  public:
    SpeakerManager();
    void play(Note note);

  private:
  Speaker* speakers[SpeakerAmount];
  static void update();

  unsigned long toneStartTime = 0; // Variable to store the start time of the tone
  unsigned long toneDuration = 0;
};