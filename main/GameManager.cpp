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
  Songs songs;

  display->initialize();
}

void GameManager::fixedUpdate(){

  updateObjects();
  drawObjects();
}

void GameManager::startColdAsIce(){

  speakerManager->play(Note(A5, 5000));
  //speakerManager->play(C5, 6000);
  //speakerManager->play(E5, 7000);
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