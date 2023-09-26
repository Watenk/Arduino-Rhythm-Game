#pragma once

#include "Note.h"
#include "Settings.h"

class SpeakerManager{
  public:
    SpeakerManager();
    void play(Note note);

  private:
  static void updateSpeaker1();
  static void updateSpeaker2();
};