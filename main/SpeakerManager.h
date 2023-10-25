#pragma once

#include "Note.h"
#include "Settings.h"
#include "notes.h"
#include "Time.h"

class SpeakerManager{
  public:
    SpeakerManager();
    void playNote(Note note);
    void update(Time* time);

  private:
  //Speaker1
  static void updateSpeaker1();
  void speaker1Play(Note note);
  bool speaker1Busy = false;
  int speaker1RemainingTime = 0;

  //Speaker2
  static void updateSpeaker2();
  void speaker2Play(Note note);
  bool speaker2Busy = false;
  int speaker2RemainingTime = 0;
};