#include <7semi_DS18B20.h>

DS18B20_7semi sensor(13);  // data pin 2

void setup() {
  Serial.begin(115200);
  if (!sensor.begin()) {
    Serial.println("No DS18B20 found!");
    while (1)
      ;
  }
  uint8_t count = sensor.searchDevices();
  Serial.print("Found devices: ");
  Serial.println(count);
}

void loop() {
  uint8_t addr[8];
  if (sensor.getAddress(0, addr)) {
    float t = sensor.readTemperature(addr);
    Serial.print("Temp C: ");
    Serial.println(t);
  }
  delay(1000);
}
