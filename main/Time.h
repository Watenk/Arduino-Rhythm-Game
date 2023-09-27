#pragma once

class Time{
  public:
    Time();
    void update();
    bool tryFixedUpdate();
    unsigned int fps;
    unsigned long timeSinceStart;
    unsigned long updateTime;

  private:
    unsigned long previousUpdateTime;
    unsigned long previousFixedUpdateTime;
    unsigned long fixedUpdateTime;
};