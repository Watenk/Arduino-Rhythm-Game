#include <Arduino.h>

#include "GameManager.h"
#include "Vector2Int.h"

GameManager::GameManager(){
  display = new Display();
  objectList = new List();

  display->initialize();
}

void GameManager::update(int fpsMain){
  fps = fpsMain;

  updateObjects();
  drawObjects();
}

void GameManager::startLvl01(){

  //Test Notes
  objectList->add(new Object(Vector2Int(10, 10), Vector2Int(0, 2), 5, 5, true));
  objectList->add(new Object(Vector2Int(31, 10), Vector2Int(0, 2), 5, 5, true));
  objectList->add(new Object(Vector2Int(52, 10), Vector2Int(0, 2), 5, 5, true));
  objectList->add(new Object(Vector2Int(73, 10), Vector2Int(0, 2), 5, 5, true));
  objectList->add(new Object(Vector2Int(94, 10), Vector2Int(0, 2), 5, 5, true));
  objectList->add(new Object(Vector2Int(115, 10), Vector2Int(0, 2), 5, 5, true));
}

void GameManager::updateObjects(){

  ListNode* currentObject = objectList->getHead();
  while (currentObject != NULL){
    currentObject->object->pos.x += currentObject->object->velocity.x;
    currentObject->object->pos.y += currentObject->object->velocity.y;
    
    if (currentObject->object->pos.y > 50){
      objectList->add(new Object(Vector2Int(currentObject->object->pos.x, -20), Vector2Int(0, 2), 5, 5, true));
      objectList->remove(currentObject);
    }

    currentObject = currentObject->previousNode;
  }
}

void GameManager::drawObjects(){
  display->clearDisplay();
  
  ListNode* currentObject = objectList->getHead();
  while (currentObject != NULL){
    display->draw(currentObject->object);
    currentObject = currentObject->previousNode;
  }

  drawFpsCounter();
  display->drawUI();

  display->updateDisplay();
}

void GameManager::drawFpsCounter(){
  display->drawNumber(fps, Vector2Int(0, 0));
}