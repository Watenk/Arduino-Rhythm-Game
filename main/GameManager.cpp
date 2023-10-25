#include <Arduino.h>

#include "GameManager.h"
#include "Vector2Int.h"
#include "Notes.h"
#include "Settings.h"

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
  handleInput();
}

void GameManager::fixedUpdate(){
  //Objects
  updateObjects();
  drawObjects();
}

void GameManager::handleInput(){

  if (digitalRead(Button1) == HIGH){
    Object* currentObject = checkIfObjectInPos(Vector2Int(10, 50));
    if (currentObject != NULL){
      playNote(currentObject);
    }
  }

  if (digitalRead(Button2) == HIGH){
    Object* currentObject = checkIfObjectInPos(Vector2Int(31, 50));
    if (currentObject != NULL){
      playNote(currentObject);
    }
  }

  if (digitalRead(Button3) == HIGH){
    Object* currentObject = checkIfObjectInPos(Vector2Int(52, 50));
    if (currentObject != NULL){
      playNote(currentObject);
    }
  }

  if (digitalRead(Button4) == HIGH){
    Object* currentObject = checkIfObjectInPos(Vector2Int(73, 50));
    if (currentObject != NULL){
      playNote(currentObject);
    }
  }

  if (digitalRead(Button5) == HIGH){
    Object* currentObject = checkIfObjectInPos(Vector2Int(94, 50));
    if (currentObject != NULL){
      playNote(currentObject);
    }
  }

  if (digitalRead(Button6) == HIGH){
    Object* currentObject = checkIfObjectInPos(Vector2Int(115, 50));
    if (currentObject != NULL){
      playNote(currentObject);
    }
  }
}

Object* GameManager::checkIfObjectInPos(Vector2Int pos){
  ListNode* currentObject = objectList->getHead();
  while (currentObject != NULL){

    if (currentObject->object->pos.x == pos.x){
      if (currentObject->object->pos.y > 50 - HitAllowance && currentObject->object->pos.y < 50 + HitAllowance){
        return currentObject->object;
      }
    }

    currentObject = currentObject->previousNode;
  }

  return NULL;
}

void GameManager::playSongNote(Note note){

  int randomColumn = random(6);

  if (randomColumn == 0){
    objectList->add(new Object(Vector2Int(10, NoteSpawnHeight), Vector2Int(0, 2), 5, 5, true, note));
  }
  else if (randomColumn == 1){
    objectList->add(new Object(Vector2Int(31, NoteSpawnHeight), Vector2Int(0, 2), 5, 5, true, note));
  }
  else if (randomColumn == 2){
    objectList->add(new Object(Vector2Int(52, NoteSpawnHeight), Vector2Int(0, 2), 5, 5, true, note));
  }
  else if (randomColumn == 3){
    objectList->add(new Object(Vector2Int(73, NoteSpawnHeight), Vector2Int(0, 2), 5, 5, true, note));
  }
  else if (randomColumn == 4){
    objectList->add(new Object(Vector2Int(94, NoteSpawnHeight), Vector2Int(0, 2), 5, 5, true, note));
  }
  else if (randomColumn == 5){
    objectList->add(new Object(Vector2Int(115, NoteSpawnHeight), Vector2Int(0, 2), 5, 5, true, note));
  }
}

void GameManager::playNote(Object* object){
  speakerManager->playNote(object->note);

  ListNode* currentObject = objectList->getHead();
  while (currentObject != NULL){
    
    if (currentObject->object == object){
      objectList->remove(currentObject);
    }

    currentObject = currentObject->previousNode;
  }
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