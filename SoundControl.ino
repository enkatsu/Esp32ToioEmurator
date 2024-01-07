// https://toio.github.io/toio-spec/docs/ble_button
#define SOUND_CONTROL_CHARACTERISTIC_UUID "10B20104-5B3B-4571-9508-CF3EFCD7BBAE"

BLECharacteristic *addSoundControlCharacteristic(BLEService *pService) {
  BLECharacteristic *characteristic = pService->createCharacteristic(
    SOUND_CONTROL_CHARACTERISTIC_UUID,
    BLECharacteristic::PROPERTY_WRITE);
  return characteristic;
}
