#define TOIO_SERVICE_UUID "10B20100-5B3B-4571-9508-CF3EFCD7BBAE"
#define COMPLETE_LOCAL_NAME "toio Core Cube-a0a"

#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>


void startAdvertising();
void printMacAddress();

class ServerCallbacks : public BLEServerCallbacks {
  void onConnect(BLEServer *pServer) {
    Serial.println("onConnect");
  };
  void onDisconnect(BLEServer *pServer) {
    Serial.println("onDisconnect");
    startAdvertising();
  }
};

void setup() {
  Serial.begin(115200);
  delay(500);

  Serial.println("Starting BLE work!");

  BLEDevice::init(COMPLETE_LOCAL_NAME);
  BLEServer *pServer = BLEDevice::createServer();
  pServer->setCallbacks(new ServerCallbacks());
  BLEService *pService = pServer->createService(TOIO_SERVICE_UUID);

  BLECharacteristic *idInfoCharacteristic = addIdInfoCharacteristic(pService);
  BLECharacteristic *sensInfoCharacteristic = addSensInfoCharacteristic(pService);
  BLECharacteristic *motorControlCharacteristic = addMotorControlCharacteristic(pService);
  BLECharacteristic *buttonInfoCharacteristic = addButtonInfoCharacteristic(pService);
  BLECharacteristic *batteryInfoCharacteristic = addBatteryInfoCharacteristic(pService);
  BLECharacteristic *lightControlCharacteristic = addLightControlCharacteristic(pService);
  BLECharacteristic *soundControlCharacteristic = addSoundControlCharacteristic(pService);

  setIdInfoPosId(idInfoCharacteristic, 0x02c5, 0x017f, 0x0132, 0x02bc, 0x0182, 0x0132);

  pService->start();
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  startAdvertising();
  Serial.println("Characteristic defined! Now you can read it in your phone!");
  printMacAddress();
}

void loop() {
  delay(2000);
}

void printMacAddress() {
  uint8_t mac[6];
  esp_read_mac(mac, ESP_MAC_BT);
  Serial.printf("mac: %02X:%02X:%02X:%02X:%02X:%02X\r\n", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
}

void startAdvertising() {
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(TOIO_SERVICE_UUID);
  pAdvertising->setScanResponse(true);
  pAdvertising->setMinPreferred(0x06);
  pAdvertising->setMinPreferred(0x12);
  BLEDevice::startAdvertising();
}
