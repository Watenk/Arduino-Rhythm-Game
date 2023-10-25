#pragma once
                            
#include "Object.h"
class SpeakerManager;

class Display{
  public:
    display();
    void initialize();
    void draw(Object* object);
    void drawNumber(int number, Vector2Int pos);
    void drawUI();
    void updateDisplay();
    void clearDisplay();

  private:

};                                                                                                                                                                                        