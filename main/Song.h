#pragma once

#include <avr/pgmspace.h>

#include "Arduino.h"
#include "Notes.h"
#include "Note.h"
#include "Time.h"
class GameManager;

struct NoteData {
  int note;   
  int length; 
  int timeTillNextNote; 
};

extern const NoteData songData[] PROGMEM;

class Song{

public:
  void playSong();
  void update(GameManager* gameManager, Time* time);

private:
  Note getNote(int index);

  int currentIndex = 0;
  int timeTillNextNote = 0;
  bool playSongBool = false;
};

