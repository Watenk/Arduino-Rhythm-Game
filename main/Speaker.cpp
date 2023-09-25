#include "Speaker.h"

#include "Settings.h"
#include "Arduino.h"

Speaker::Speaker() {
}

void Speaker::initialize(Adafruit_PWMServoDriver *_pwm, int i){
  pwm = _pwm;
  speakerID = i;
  fixedUpdateLenght = int(1000.0f / float(FixedUpdateSpeed));
  pwm->setPWM(speakerID, 0, 0);
}

void Speaker::fixedUpdate() {
  Serial.println(toneLenght);
  if (busy){
    toneLenght -= 50;

    if (toneLenght <= 0){
      busy = false;
      pwm->setPWM(speakerID, 0, 0);
    }
  }
}

void Speaker::play(Note note) {
  busy = true;
  toneLenght = note.lenght;
Serial.println(toneLenght);
  float dutyCycle = float(note.note) / float(PWMFrequency) * 4096.0f;

  pwm->setPWM(speakerID, 0, dutyCycle);

  if (dutyCycle > 4095) {
    Serial.println("DutyCycle / Tone too high. Try increasing the PWMFrequency or use lower tones");
  }
}