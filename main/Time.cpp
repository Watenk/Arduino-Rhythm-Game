#include "Time.h"
#include "Arduino.h"
#include "Settings.h"

Time::Time() : previousUpdateTime(0), previousFixedUpdateTime(0){
  
}

void Time::update(){
  timeSinceStart = millis();

  updateTime = timeSinceStart - previousUpdateTime;
  previousUpdateTime = timeSinceStart;
  fixedUpdateTime = timeSinceStart - previousFixedUpdateTime;
  fps = 1000 / fixedUpdateTime;
}

bool Time::tryFixedUpdate(){

  //Do update
  if (fixedUpdateTime > (1000 / FixedUpdateSpeed)){
    previousFixedUpdateTime = timeSinceStart;
    return true;
  }
  //Dont update
  else{
    return false;
  }
}