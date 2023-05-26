#include <M5Core2.h>
#include <stdio.h>

#define SERVO_PIN 26
#define SERVO_CH 0
#define PMW_HZ 50
#define PMW_BIT 16

#define MAX 7800
#define MIN 1700

void setup() {
  M5.begin(true, true, true, false);

  ledcSetup(SERVO_CH, PMW_HZ, PMW_BIT);
  ledcAttachPin(SERVO_PIN, SERVO_CH);

  M5.Lcd.setBrightness(200);
  M5.Lcd.setTextSize(2);
  M5.Lcd.setTextFont(7);

  M5.Lcd.setTextColor(GREEN);
}

void loop() {
  char str[128];
  for(int angle=0; angle<=180; angle+=45){
    int duty_cycle = map(angle, 0, 180, MIN, MAX);
    ledcWrite(SERVO_CH, duty_cycle);

    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setCursor(80, 80);
    sprintf(str, "%3d", angle);
    M5.Lcd.drawCentreString(str, 150, 70, 7);
    delay(1000);
  }
}
