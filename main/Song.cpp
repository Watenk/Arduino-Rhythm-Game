#include "Song.h"
#include "Settings.h"
#include "object.h"
#include "GameManager.h"

const NoteData songData[] PROGMEM = {
{NoteD3, 200, 200},
{NoteE3, 200, 200},
{NoteFS3, 200, 200},
{NoteGS3, 200, 200},
{NoteAS3, 200, 200},
{NoteC4, 200, 200},
{NoteD4, 200, 200},
{NoteE4, 200, 200},
{NoteFS4, 200, 200},
{NoteGS4, 200, 200},
{NoteAS4, 200, 200},
{NoteB4, 200, 200},
};

void Song::playSong(){
  playSongBool = true;
}

void Song::update(GameManager* gameManager, Time* time){

  if (playSongBool == true){
    if (timeTillNextNote <= 0){
      Note note = getNote(currentIndex);

      timeTillNextNote = note.timeTillNextNote;
      gameManager->playNote(note);

      currentIndex++;
   }
   else{
      timeTillNextNote -= time->updateTime;
    }
  }
}

Note Song::getNote(int index) {
  NoteData noteDataEntry;
  memcpy_P(&noteDataEntry, &songData[index], sizeof(NoteData));
  noteDataEntry.note = pgm_read_word_near(&songData[index].note);
  noteDataEntry.length = pgm_read_word_near(&songData[index].length);
  noteDataEntry.timeTillNextNote = pgm_read_word_near(&songData[index].timeTillNextNote);
  noteDataEntry.timeTillNextNote = int (noteDataEntry.timeTillNextNote * SongSpeedMultiplier);
  return Note(noteDataEntry.note, noteDataEntry.length, noteDataEntry.timeTillNextNote);
}

