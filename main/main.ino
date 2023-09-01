#include "gameManager.h"

GameManager* gameManager;
unsigned long time;
unsigned long timeSinceLastUpdate;
unsigned long lastUpdateTime;

void setup() {

  //Initialize
  Serial.begin(9600);
  gameManager = new GameManager();

  gameManager->startLvl01();
}

void loop() {

  UpdateGameManager();
}

void UpdateGameManager(){
  //Update the GameManager 10 times a second
  time = millis();
  timeSinceLastUpdate = time - lastUpdateTime;
  if (timeSinceLastUpdate > 1000){
    gameManager->update();
    timeSinceLastUpdate = 0;
    lastUpdateTime = time;
  }
}