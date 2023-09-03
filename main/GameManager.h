#pragma once

#include "Object.h"
#include "List.h"
#include "Display.h"

class GameManager{
  public:
    GameManager();
    void update(int fps);
    void startLvl01();
    void drawObjects();
    void updateObjects();
    void drawFpsCounter();

  private:
    List* objectList;
    Display* display;
    int updateDelay;
    int currentObjectIndex;
    int fps;
};