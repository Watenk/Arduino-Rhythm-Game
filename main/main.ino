#include "GameManager.h"
#include "MemoryFree.h"
#include "Time.h"
#include "Settings.h"

GameManager* gameManager;
Time* time;

void setup() {

  Serial.begin(9600);
  pinMode(speaker1Pin, OUTPUT);
  pinMode(speaker2Pin, OUTPUT);
  pinMode(speaker3Pin, OUTPUT);
  pinMode(speaker4Pin, OUTPUT);

  gameManager = new GameManager();
  time = new Time();

  gameManager->startColdAsIce();
}

void loop() {

  time->update();
  gameManager->updateSound();

  if (time->tryFixedUpdate()){
    fixedUpdate();
  }

  //Serial.println(freeMemory());
}

void fixedUpdate(){
  gameManager->fixedUpdate();
}