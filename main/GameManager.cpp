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
  objectList->add(new Object(Vector2Int(0, 50), Vector2Int(0,0), 128, 2, false)); //Detection bar

  Object* circle = new Object(Vector2Int(10, 30), Vector2Int(1,0), 5, 5, true);
  objectList->add(circle);
  //objectList->remove(circle);
}

void GameManager::updateObjects(){

  ListNode* currentObject = objectList->getHead();
  while (currentObject != NULL){
    currentObject->object->pos.x += currentObject->object->velocity.x;
    currentObject->object->pos.y += currentObject->object->velocity.y;
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

  display->updateDisplay();
}

void GameManager::drawFpsCounter(){
  display->drawNumber(fps, Vector2Int(0, 0));
}

