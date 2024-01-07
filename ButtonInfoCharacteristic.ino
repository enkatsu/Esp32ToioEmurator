// https://toio.github.io/toio-spec/docs/ble_button
#define BUTTON_INFO_CHARACTERISTIC_UUID "10B20107-5B3B-4571-9508-CF3EFCD7BBAE"

BLECharacteristic *addButtonInfoCharacteristic(BLEService *pService) {
  BLECharacteristic *characteristic = pService->createCharacteristic(
    BUTTON_INFO_CHARACTERISTIC_UUID,
    BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY);
  return characteristic;
}
