#include "Vector2Int.h"

Vector2Int::Vector2Int() : x(0), y(0){

}

Vector2Int::Vector2Int(int newX, int newY) : x(newX), y(newY){

}

//Operator Overoading
Vector2Int operator+=(Vector2Int vector1, Vector2Int vector2){
  int newX = vector1.x + vector2.x;
  int newY = vector1.y + vector2.y;
  return Vector2Int(newX, newY);
}

Vector2Int operator-=(Vector2Int vector1, Vector2Int vector2){
  int newX = vector1.x - vector2.x;
  int newY = vector1.y - vector2.y;
  return Vector2Int(newX, newY);
}