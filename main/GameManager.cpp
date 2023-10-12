#include <Arduino.h>

#include "GameManager.h"
#include "Vector2Int.h"
#include "Notes.h"

GameManager::GameManager(){
  display = new Display();
  objectList = new List();
  speakerManager = new SpeakerManager();
  song = new Song();

  display->initialize();
  song->playSong();
}

void GameManager::update(Time* time){
  speakerManager->update(time);
  song->update(this, time);
}

void GameManager::fixedUpdate(){
  //Objects
  updateObjects();
  drawObjects();
}

void GameManager::playNote(Note note){

  int currentColumn = random(6);

  objectList->add(new Object(Vector2Int(10, 10), Vector2Int(0, 2), 5, 5, true));
}

void GameManager::updateObjects(){

  ListNode* currentObject = objectList->getHead();
  while (currentObject != NULL){
    currentObject->object->pos.x += currentObject->object->velocity.x;
    currentObject->object->pos.y += currentObject->object->velocity.y;
    
    if (currentObject->object->pos.y > 64){
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

  display->drawUI();

  display->updateDisplay();
}