#pragma once

#include "Vector2Int.h"
#include "Note.h"

class Object{
  public:
  Object(Vector2Int pos, Vector2Int velocity, int width, int height, bool isCircle, Note note);

  Vector2Int pos;
  Vector2Int velocity;
  Note note;
  int width;
  int height;
  bool isCircle;

  private:

};