#include "GameManager.h"
#include "MemoryFree.h"
#include "Time.h"
#include "Settings.h"

GameManager* gameManager;
Time* time;

void setup() {

  Serial.begin(9600);

  gameManager = new GameManager();
  time = new Time();

  gameManager->startColdAsIce();
}

void loop() {

  time->update();

  if (time->tryFixedUpdate()){
    fixedUpdate();
  }

  //Serial.println(freeMemory());
}

void fixedUpdate(){
  gameManager->fixedUpdate();
}