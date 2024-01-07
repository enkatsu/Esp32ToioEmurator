// https://toio.github.io/toio-spec/docs/ble_motor
#define MOTOR_CONTROL_CHARACTERISTIC_UUID "10B20102-5B3B-4571-9508-CF3EFCD7BBAE"
#define MOVE_TO_TARGET 0x03
#define MOVE_TO_MULTIPLE_TARGET 0x04

class MotorControlCharacteristicCallbacks : public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *pCharacteristic) {
    uint8_t *data = pCharacteristic->getData();
    size_t len = pCharacteristic->getLength();
    uint8_t type = data[0];
    if (type == MOVE_TO_TARGET) {
      uint8_t controlIdentifier = data[1];
      uint8_t timeout = data[2];
      uint8_t moveType = data[3];
      uint8_t maxSpeed = data[4];
      uint8_t speedType = data[5];
      uint8_t reserved = data[6];
      uint16_t x = data[7] + (data[8] << 8);
      uint16_t y = data[9] + (data[10] << 8);
      uint16_t angle = data[11] + (data[12] << 8);
    }
  }
};

BLECharacteristic *addMotorControlCharacteristic(BLEService *pService) {
  BLECharacteristic *characteristic = pService->createCharacteristic(
    MOTOR_CONTROL_CHARACTERISTIC_UUID,
    BLECharacteristic::PROPERTY_WRITE_NR | BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY);
  characteristic->setCallbacks(new MotorControlCharacteristicCallbacks());
  return characteristic;
}
