#include <Arduino.h>

#include "GameManager.h"
#include "Display.h"
#include "Vector2Int.h"
int currentObjectIndex;
int objectAmount = 10;

Display* display;

GameManager::GameManager(){
  display = new Display();
  display->initialize();
  currentObjectIndex = 0;

  for (int i = 0; i < objectAmount; i++){
    objects[i] = new Object(Vector2Int(-100, -100), Vector2Int(0, 0), 0, 0, false);
  }
}

void GameManager::update(){
  updateObjects();
  drawObjects();
}

void GameManager::updateObjects(){
  for (int i = 0; i < objectAmount; i++){
    Object* currentObject = objects[i];
    if (currentObject->pos.y < 10) { currentObject->velocity.y * -1; }
    if (currentObject->pos.y > 50) { currentObject->velocity.y * -1; }

    currentObject->pos.x += currentObject->velocity.x;
    currentObject->pos.y += currentObject->velocity.y;
  }
}

void GameManager::drawObjects(){
  display->clearDisplay();
  
  for (int i = 0; i < objectAmount; i++){
    display->draw(objects[i]);
  }
  display->updateDisplay();
}

void GameManager::startLvl01(){
  addObject(Vector2Int(0, 0), Vector2Int(0,0), 5, 5, false);

}

void GameManager::addNote(){
  
}

void GameManager::addObject(Vector2Int pos, Vector2Int velocity, int width, int height, bool isCircle){
  objects[currentObjectIndex]->pos = pos;
  objects[currentObjectIndex]->velocity = velocity;
  objects[currentObjectIndex]->width = width;
  objects[currentObjectIndex]->height = height;
  objects[currentObjectIndex]->isCircle = isCircle;
  currentObjectIndex++;
}

void GameManager::removeObject(){

}