#pragma once

#include "Object.h"

class Display{
  public:
    display();
    void initialize();
    void draw(Object* object);
    void updateDisplay();
    void clearDisplay();

  private:

};