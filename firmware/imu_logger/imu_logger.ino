#include "LSM6DS3.h"
#include "Wire.h"

LSM6DS3 smartdie(I2C_MODE, 0x6A);

void setup() {
  Serial.begin(115200);

  if (smartdie.begin() == 0) {
    Serial.println("Device successfully connected!");
  } else {
    Serial.println("ERROR! Device not successfully connected!");
  }

  Serial.println("time_ms,ax,ay,az,wx,wy,wz");
}

void loop() {
  float ax = smartdie.readFloatAccelX();
  float ay = smartdie.readFloatAccelY();
  float az = smartdie.readFloatAccelZ();

  float wx = smartdie.readFloatGyroX();
  float wy = smartdie.readFloatGyroY();
  float wz = smartdie.readFloatGyroZ();

  unsigned long t = millis();

  Serial.print(t);
  Serial.print(",");
  Serial.print(ax);
  Serial.print(",");
  Serial.print(ay);
  Serial.print(",");
  Serial.print(az);
  Serial.print(",");
  Serial.print(wx);
  Serial.print(",");
  Serial.print(wy);
  Serial.print(",");
  Serial.println(wz);

  delay(20);
}
