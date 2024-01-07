// https://toio.github.io/toio-spec/docs/ble_id/
#define ID_INFO_CHARACTERISTIC_UUID "10B20101-5B3B-4571-9508-CF3EFCD7BBAE"
#define ID_INFO_POS_ID_SIZE 13
#define ID_INFO_STD_ID_SIZE 7
#define ID_INFO_POS_ID_MSD_SIZE 1
#define ID_INFO_STD_ID_MSD_SIZE 1
#define ID_INFO_POS_ID 0x01
#define ID_INFO_STD_ID 0x02
#define ID_INFO_POS_ID_MSD 0x03
#define ID_INFO_STD_ID_MSD 0x04

BLECharacteristic *addIdInfoCharacteristic(BLEService *pService) {
  return pService->createCharacteristic(
    ID_INFO_CHARACTERISTIC_UUID,
    BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY);
}

void setIdInfoPosId(BLECharacteristic *pCharacteristic,
                    uint16_t cubeX, uint16_t cubeY, uint16_t cubeAngle,
                    uint16_t sensorX, uint16_t sensorY, uint16_t sensorAngle) {
  uint8_t data[ID_INFO_POS_ID_SIZE] = {
    ID_INFO_POS_ID,
    cubeX >> 0 & 0xFF,
    cubeX >> 8 & 0xFF,
    cubeY >> 0 & 0xFF,
    cubeY >> 8 & 0xFF,
    cubeAngle >> 0 & 0xFF,
    cubeAngle >> 8 & 0xFF,
    sensorX >> 0 & 0xFF,
    sensorX >> 8 & 0xFF,
    sensorY >> 0 & 0xFF,
    sensorY >> 8 & 0xFF,
    sensorAngle >> 0 & 0xFF,
    sensorAngle >> 8 & 0xFF,
  };
  pCharacteristic->setValue(data, ID_INFO_POS_ID_SIZE);
}

void setIdInfoStdId(BLECharacteristic *pCharacteristic, uint32_t stdId, uint16_t cubeAngle) {
  uint8_t data[ID_INFO_STD_ID_SIZE] = {
    ID_INFO_STD_ID,
    stdId >> 0 & 0xFF,
    stdId >> 8 & 0xFF,
    stdId >> 16 & 0xFF,
    stdId >> 24 & 0xFF,
    cubeAngle >> 0 & 0xFF,
    cubeAngle >> 8 & 0xFF,
  };
  pCharacteristic->setValue(data, ID_INFO_STD_ID_SIZE);
}

void setIdInfoPosIdMsd(BLECharacteristic *pCharacteristic) {
  uint8_t data[ID_INFO_POS_ID_MSD_SIZE] = { ID_INFO_POS_ID_MSD };
  pCharacteristic->setValue(data, ID_INFO_POS_ID_MSD_SIZE);
}

void setIdInfoStdIdMsd(BLECharacteristic *pCharacteristic) {
  uint8_t data[ID_INFO_STD_ID_MSD_SIZE] = { ID_INFO_STD_ID_MSD };
  pCharacteristic->setValue(data, ID_INFO_STD_ID_MSD_SIZE);
}
