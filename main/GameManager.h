#pragma once

#include "Object.h"
#include "List.h"
#include "Display.h"
#include "Songs.h"
#include "SpeakerManager.h"

class GameManager{
  public:
    GameManager();
    void fixedUpdate();
    void update();

    //Songs
    void startColdAsIce();

  private:
    void drawObjects();
    void updateObjects();

    List* objectList;
    Display* display;
    SpeakerManager* speakerManager;
    Songs* songs;

    int updateDelay;
    int currentObjectIndex;
};