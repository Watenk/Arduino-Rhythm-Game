#include <Arduino.h>

#include "GameManager.h"
#include "Vector2Int.h"
#include "Songs.h"
#include "Notes.h"
#include "Note.h"

GameManager::GameManager(){
  display = new Display();
  objectList = new List();
  speakerManager = new SpeakerManager();
  songs = new Songs();

  display->initialize();
}

void GameManager::fixedUpdate(){
  //Objects
  updateObjects();
  drawObjects();

  //Sound
  speakerManager->fixedUpdate();
}

void GameManager::startColdAsIce(){

  speakerManager->play(Note(A5, 2000, 100));
  speakerManager->play(Note(C5, 5000, 100));
  speakerManager->play(Note(E5, 10000, 100));
  //speakerManager->play(G5, 8000);

  //Test Notes
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