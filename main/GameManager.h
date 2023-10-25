#pragma once

#include "Object.h"
#include "List.h"
#include "Display.h"
#include "SpeakerManager.h"
#include "Time.h"
#include "Note.h"
#include "Song.h"

class GameManager{
  public:
    GameManager();
    void fixedUpdate();
    void update(Time* time);
    void playSongNote(Note note);

  private:
    void drawObjects();
    void updateObjects();
    void handleInput();
    Object* checkIfObjectInPos(Vector2Int pos);
    void playNote(Object* object);

    List* objectList;
    Display* display;
    SpeakerManager* speakerManager;
    Song* song;

    int updateDelay;
    int currentObjectIndex;
};