#include "GameManager.h"
#include "MemoryFree.h"
#include "Time.h"
#include "Settings.h"

GameManager* gameManager;
Time* time;

void setup() {

  Serial.begin(9600);
  pinMode(Speaker1, OUTPUT);
  pinMode(Speaker2, OUTPUT);

  gameManager = new GameManager();
  time = new Time();

  gameManager->startColdAsIce();
}

void loop() {

  time->update();
  gameManager->update(time);

  //Serial.println(freeMemory());

  //Try FixedUpdate
  if (time->tryFixedUpdate()){
    fixedUpdate();
  }
}

void fixedUpdate(){
  gameManager->fixedUpdate();
}