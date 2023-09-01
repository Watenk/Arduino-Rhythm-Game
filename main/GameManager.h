#pragma once

#include "Object.h"

class GameManager{
  public:
    GameManager();
    void update();
    void startLvl01();
    void addObject(Vector2Int pos, Vector2Int velocity, int width, int height, bool isCircle);
    void removeObject();
    void drawObjects();
    void updateObjects();
    void addNote();

  private:
    Object* objects[10];
    int updateDelay;
    int currentObjectIndex;
};