#pragma once 

#include "Notes.h"
#include "Note.h"

class SongTest{

  //Lead
  Note notes1[] = {
    Note(NOTE_A5, 10, 10), 
    Note(NOTE_B5, 10, 10)
  }

  //Chords
  Note notes2[] = {
    Note(NOTE_C5, 10, 0), Note(NOTE_E5, 10, 0), Note(NOTE_G5, 10, 0), //C5 chord
    //next Note
  }
}