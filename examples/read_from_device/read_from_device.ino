/**
 * @~Chinese
 * @file read_from_device.ino
 * @brief 从设备中读取数据。
 * @example read_from_device.ino
 * 从设备中读取数据。
 */
/**
 * @~English
 * @file read_from_device.ino
 * @brief Read data from the device.
 * @example read_from_device.ino
 * Read data from the device.
 */
#include "dummy_device.h"
#include "dummy_device_lib.h"

namespace {
em::DummyDevice g_dummy_device;
}
void setup() {
  Serial.begin(115200);
  Serial.println("setup");
  Serial.println(String("dummy device lib version: ") + em::dummy_device_lib::Version());

  Wire.begin();

  const auto ret = g_dummy_device.Init();

  if (em::DummyDevice::kOK == ret) {
    Serial.println("dummy device initialization successful");
  } else {
    Serial.print("dummy device initialization failed: ");
    Serial.println(ret);
    while (true);
  }

  Serial.println("setup successful");
}

void loop() {
  uint8_t data[10] = {0};
  uint32_t length = 0;
  g_dummy_device.Read(data, sizeof(data), &length);
  delay(1000);
}
