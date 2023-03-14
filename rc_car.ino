#include "Motor.h"
#include "sbus.h"
#define SBUS_PIN 50

Motor motor1(2, 3);
Motor motor2(5, 4);
SBUS sbus;

void setup() {
  Serial.begin(9600);
  sbus.begin(SBUS_PIN, sbusNonBlocking);
}

void loop() {
  //  for (int i = 1; i <= 10; i ++) {
  //    Serial.print(sbus.getChannel(i));
  //    Serial.print(' ');
  //  }
  int xvel = sbus.getChannel(2) + 7;
  int zvel = sbus.getChannel(1) - 3;

  Serial.print(xvel);
  Serial.print(' ');
  Serial.println(zvel);

  if (xvel < 1000 || zvel < 1000) {
    xvel = 1500;
    zvel = 1500;
  }

  if (abs(xvel - 1500) < 100) {
    xvel = 1500;
  }

  if (abs(zvel - 1500) < 100) {
    zvel = 1500;
  }

  Serial.print(xvel);
  Serial.print(' ');
  Serial.println(zvel);

  xvel = map(xvel, 2000, 1000, -100, 100);
  zvel = map(zvel, 1000, 2000, -100, 100);

  Serial.print(xvel);
  Serial.print(' ');
  Serial.println(zvel);

  motor1.setSpeed(xvel - zvel);
  motor2.setSpeed(xvel + zvel);

  delay(100);
}
