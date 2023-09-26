#include "Speaker.h"

#include "Settings.h"
#include "Arduino.h"

Speaker::Speaker() {
}

void Speaker::update() {
  if (busy){
    toneLenght -= 50;

    if (toneLenght <= 0){
      busy = false;
    }
  }
}

void Speaker::play(Note note) {
  busy = true;
  toneLenght = note.lenght;
}