/**
 * @file dummy_device.cpp
 */
#include "dummy_device.h"

#include <Arduino.h>

namespace em {

DummyDevice::DummyDevice(const uint8_t i2c_address, TwoWire& wire) : i2c_address_(i2c_address), wire_(wire) {
}

DummyDevice::ErrorCode DummyDevice::Init() {
  wire_.beginTransmission(i2c_address_);
  return static_cast<ErrorCode>(wire_.endTransmission());
}

DummyDevice::ErrorCode DummyDevice::Write(const uint8_t* data, const uint32_t length) {
  (void)data;
  (void)length;
  return kOK;
}

DummyDevice::ErrorCode DummyDevice::Read(const uint8_t* buffer, const uint32_t expected_length, uint32_t* const actual_length) {
  (void)buffer;
  (void)expected_length;
  (void)actual_length;
  return kOK;
}
}  // namespace em