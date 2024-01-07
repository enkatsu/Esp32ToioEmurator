// https://toio.github.io/toio-spec/docs/ble_button
#define LIGHT_CONTROL_CHARACTERISTIC_UUID "10B20103-5B3B-4571-9508-CF3EFCD7BBAE"

BLECharacteristic *addLightControlCharacteristic(BLEService *pService) {
  BLECharacteristic *characteristic = pService->createCharacteristic(
    LIGHT_CONTROL_CHARACTERISTIC_UUID,
    BLECharacteristic::PROPERTY_WRITE);
  return characteristic;
}
