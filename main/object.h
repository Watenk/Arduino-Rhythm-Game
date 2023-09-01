#pragma once

#include "Vector2Int.h"

class Object{
  public:
  Object(Vector2Int pos, Vector2Int velocity, int width, int height, bool isCircle);

  Vector2Int pos;
  Vector2Int velocity;
  int width;
  int height;
  bool isCircle;

  private:

};