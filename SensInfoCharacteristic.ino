// https://toio.github.io/toio-spec/docs/ble_sensor/
#define SENS_INFO_CHARACTERISTIC_UUID "10B20106-5B3B-4571-9508-CF3EFCD7BBAE"
#define SENS_INFO_MOTION_ID 0x81
#define SENS_INFO_MOTION_DETECT_SIZE 6

BLECharacteristic *addSensInfoCharacteristic(BLEService *pService) {
  return pService->createCharacteristic(
    SENS_INFO_CHARACTERISTIC_UUID,
    BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE | BLECharacteristic::PROPERTY_NOTIFY);
}

void setSensInfoMotionDetectionReq(BLECharacteristic *pCharacteristic) {
  uint8_t data[ID_INFO_POS_ID_MSD_SIZE] = { ID_INFO_POS_ID_MSD };
  pCharacteristic->setValue(data, ID_INFO_POS_ID_MSD_SIZE);
}

void setSensInfoMotionDetection(BLECharacteristic *pCharacteristic,
                                uint8_t type,
                                uint8_t horizontal,
                                uint8_t collision,
                                uint8_t doubleTap,
                                uint8_t attitude,
                                uint8_t shake) {
  uint8_t data[SENS_INFO_MOTION_DETECT_SIZE] = {
    type,
    horizontal,
    collision,
    doubleTap,
    attitude,
    shake,
  };
  pCharacteristic->setValue(data, SENS_INFO_MOTION_DETECT_SIZE);
}
