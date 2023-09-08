#include "Speaker.h"

Speaker::Speaker(int pin) : isBusy(false), pinPower(0), pin(pin), speakerFreq(0), speakerHalfPeriod(0), remainingPlayTime(0), previousUpdate(0) {

}