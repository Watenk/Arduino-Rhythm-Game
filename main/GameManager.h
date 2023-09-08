#pragma once

#include "Object.h"
#include "List.h"
#include "Display.h"
#include "Songs.h"
#include "SpeakerManager.h"

class GameManager{
  public:
    GameManager();
    void updateSound();
    void fixedUpdate();
    void drawObjects();
    void updateObjects();

    //Songs
    void startColdAsIce();

  private:
    List* objectList;
    Display* display;
    SpeakerManager* speakerManager;
    Songs songs;

    int updateDelay;
    int currentObjectIndex;
};