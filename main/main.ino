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
  pinMode(Button1, INPUT);
  pinMode(Button2, INPUT);
  pinMode(Button3, INPUT);
  pinMode(Button4, INPUT);
  pinMode(Button5, INPUT);
  pinMode(Button6, INPUT);

  randomSeed(analogRead(0));
  gameManager = new GameManager();
  time = new Time();
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