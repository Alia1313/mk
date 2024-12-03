#include <DHT.h>
#include <LiquidCrystal.h>
#include <SFE_BMP180.h>
#include <DS3232RTC.h>

DHT tempAndHumiditySensor(13, DHT11);
SFE_BMP180 pressureSensor;
LiquidCrystal screen(12, 11, 5, 4, 3, 2);

void setup() {
  tempAndHumiditySensor.begin();
  screen.begin(16, 2);
  pressureSensor.begin();
  Serial.begin(9600);
}

void loop() {
  double p, t;
  pressureSensor.getPressure(p, t);
  screen.setCursor(0, 0);
  screen.print(hour());
  screen.print(":");
  screen.print(minute());
  screen.print(":");
  screen.print(second());
  screen.print("|");
  screen.print(tempAndHumiditySensor.readTemperature());
  screen.print("C");
  screen.setCursor(0, 1);
  screen.print(tempAndHumiditySensor.readHumidity());
  screen.print("|");
  screen.print(p);
}
