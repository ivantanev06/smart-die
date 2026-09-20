#include <ArduinoBLE.h>
#include <LSM6DS3.h>
#include <Wire.h>

LSM6DS3 imu(I2C_MODE, 0x6A);

BLEService dieService(
  "19B10000-E8F2-537E-4F6C-D104768A1214"
);

BLECharacteristic imuCharacteristic(
  "19B10002-E8F2-537E-4F6C-D104768A1214",
  BLERead | BLENotify,
  16
);

const unsigned long SAMPLE_INTERVAL_MS = 20;
unsigned long lastSampleTime = 0;

struct __attribute__((packed)) IMUPacket {

  uint32_t time_ms;

  int16_t ax;
  int16_t ay;
  int16_t az;

  int16_t gx;
  int16_t gy;
  int16_t gz;
};

void setup() {
  Serial.begin(115200);

  if (imu.begin() != 0){
    Serial.println("IMU failed to start.");
    while (1);
  }

  Serial.println("IMU started.");

  if (!BLE.begin()){
    Serial.println("BLE failed to start.");
    while (1);
  }

  BLE.setLocalName("SmartDie");
  BLE.setAdvertisedService(dieService);
  dieService.addCharacteristic(imuCharacteristic);
  BLE.addService(dieService);
  BLE.advertise();
  Serial.println("SmartDie advertising...");
}

void loop() {
  BLE.poll();
  unsigned long now = millis();
  if (now - lastSampleTime >= SAMPLE_INTERVAL_MS) {
    lastSampleTime = now;
    float ax = imu.readFloatAccelX();
    float ay = imu.readFloatAccelY();
    float az = imu.readFloatAccelZ();

    float gx = imu.readFloatGyroX();
    float gy = imu.readFloatGyroY();
    float gz = imu.readFloatGyroZ();

    IMUPacket packet;
    packet.time_ms = now;
    packet.ax = (int16_t)(ax * 1000);
    packet.ay = (int16_t)(ay * 1000);
    packet.az = (int16_t)(az * 1000);

    packet.gx = (int16_t)(gx * 10);
    packet.gy = (int16_t)(gy * 10);
    packet.gz = (int16_t)(gz * 10);

    imuCharacteristic.writeValue(
      (uint8_t*)&packet,
      sizeof(packet)
    );
  }
}




