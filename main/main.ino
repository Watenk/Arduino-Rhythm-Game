#include "gameManager.h"

#include "MemoryFree.h"

GameManager* gameManager;
unsigned long time;
unsigned long timeSinceLastUpdate;
unsigned long lastUpdateTime;
int fps;

void setup() {

  //Initialize
  Serial.begin(9600);
  gameManager = new GameManager();

  gameManager->startLvl01();
}

void loop() {
  Serial.println(freeMemory());
  UpdateGameManager();
}

void UpdateGameManager(){
  //Update the GameManager 24 times a second
  time = millis();
  timeSinceLastUpdate = time - lastUpdateTime;
  if (timeSinceLastUpdate > 42){
    gameManager->update(fps);
    fps = 1000 / timeSinceLastUpdate;
    timeSinceLastUpdate = 0;
    lastUpdateTime = time;
  }
}