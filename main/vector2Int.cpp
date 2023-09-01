#include "vector2Int.h"

vector2Int::vector2Int() : x(0), y(0){

}

vector2Int::vector2Int(int newX, int newY) : x(newX), y(newY){

}

//Operator Overoading
vector2Int operator+=(vector2Int vector1, vector2Int vector2){
  int newX = vector1.x + vector2.x;
  int newY = vector1.y + vector2.y;
  return vector2Int(newX, newY);
}

vector2Int operator-=(vector2Int vector1, vector2Int vector2){
  int newX = vector1.x - vector2.x;
  int newY = vector1.y - vector2.y;
  return vector2Int(newX, newY);
}