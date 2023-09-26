#pragma once

#include "Note.h"

class Speaker{
  public:
    Speaker();
    void update();
    void play(Note note);

    bool busy = false;
    int speakerID;
    int dutyCycle;

  private:
  int toneLenght = 0;
  int fixedUpdateLenght;
};