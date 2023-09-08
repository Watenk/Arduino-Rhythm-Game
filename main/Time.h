#pragma once

class Time{
  public:
    Time();
    void update();
    bool tryFixedUpdate();
    unsigned int fps;
    unsigned long timeSinceStart;

  private:
    unsigned long previousUpdateTime;
    unsigned long previousFixedUpdateTime;
    unsigned long updateTime;
    unsigned long fixedUpdateTime;
};