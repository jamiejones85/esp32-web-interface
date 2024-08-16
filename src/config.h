#ifndef CONFIG_H
#define CONFIG_H

#define EEPROM_VERSION 1
typedef struct {
    int version;
    int canRXPin;
    int canTXPin;
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

    void saveSettings();
  private:
    EEPROMSettings settings;

};
#endif