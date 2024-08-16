#include "config.h"
#include <EEPROM.h>
Config::Config() {
}

void Config::load() {

    EEPROM.begin(sizeof(settings));
    EEPROM.get(0, settings);
    if (settings.version != EEPROM_VERSION) {
        //defaults
        settings.version = EEPROM_VERSION;
        settings.canRXPin = GPIO_NUM_26;
        settings.canTXPin = GPIO_NUM_25;
        settings.canEnablePin = 0;
    }
}
int Config::getCanRXPin() {
    return settings.canRXPin;
}

int Config::getCanTXPin() {
    return settings.canTXPin;
}

int Config::getCanEnablePin() {
    return settings.canEnablePin;
}


void Config::setCanEnablePin(int pin) {
    settings.canEnablePin = pin;
}

void Config::setCanTXPin(int pin) {
    settings.canTXPin = pin;
}

void Config::setCanRXPin(int pin) {
    settings.canRXPin = pin;
}

void Config::saveSettings() {
    EEPROM.put(0, settings); //save all change to eeprom
    EEPROM.commit();
}
