#include "DFRobot_BloodOxygen_S.h"
#include "lcd.h"

#define MAX30102_I2C_ADDRESS    0x57

DFRobot_BloodOxygen_S_I2C max30102(&Wire, MAX30102_I2C_ADDRESS);

int heart_rate = 0;
int spo2 = 0;

char heart_rate_1[2], heart_rate_10[2], heart_rate_100[2];
char spo2_1[2], spo2_10[2], spo2_100[2];
