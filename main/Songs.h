#pragma once

#include <avr/pgmspace.h>

#include "Arduino.h"
#include "Notes.h"
#include "Note.h"
#include "Time.h"
#include "SpeakerManager.h"

struct NoteData {
  int note;   
  int length; 
  int timeTillNextNote; 
};

extern const NoteData songData[] PROGMEM;

class Songs{

public:
  Songs();
  void playSong();
  void update(SpeakerManager* speakerManager, Time* time);
  

private:

  NoteData getNoteData(int index);

  int currentIndex = 0;
  int timeTillNextNote = 0;
};

