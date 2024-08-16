#ifndef CONFIG_H
#define CONFIG_H

#define EEPROM_VERSION 2
typedef struct {
    int version;
    int canRXPin;
    int canTXPin;
    int canEnablePin;
} EEPROMSettings;


class Config
{
  public:
    Config();
    void load();
    int getCanRXPin();
    void setCanRXPin(int pin);

    int getCanTXPin();
    void setCanTXPin(int pin);


    int getCanEnablePin();
    void setCanEnablePin(int pin);

    void saveSettings();
  private:
    EEPROMSettings settings;

};
#endif