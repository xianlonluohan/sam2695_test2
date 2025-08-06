/**
 * @file dummy_device.h
 */
#pragma once

#ifndef _EM_DUMMY_DEVICE_H_
#define _EM_DUMMY_DEVICE_H_

#include <WString.h>
#include <Wire.h>
#include <stdint.h>

namespace em {
/**
 * @~Chinese
 * @class DummyDevice
 * @brief DummyDevice是一个用于测试的虚拟设备，默认I2C地址为0x10。
 * @example read_from_device.ino 从设备中读取数据。
 * @example write_to_device.ino 向设备中写入数据。
 */
/**
 * @~English
 * @class DummyDevice
 * @brief The DummyDevice is a virtual device used for testing, with a default I2C address of 0x10.
 * @example read_from_device.ino Read data from the device.
 * @example write_to_device.ino Write data to the device.
 */
class DummyDevice {
 public:
  static constexpr uint8_t kDefaultI2cAddress = 0x10;

  /**
   * @~Chinese
   * @enum ErrorCode
   * @brief 错误码。
   */
  /**
   * @~English
   * @enum ErrorCode
   * @brief Error codes.
   */
  enum ErrorCode : uint32_t {
    /**
     * @~Chinese
     * @brief 成功。
     */
    /**
     * @~English
     * @brief Success.
     */
    kOK = 0,

    /**
     * @~Chinese
     * @brief I2C数据太长，无法装入传输缓冲区。
     */
    /**
     * @~English
     * @brief I2C data too long to fit in transmit buffer.
     */
    kI2cDataTooLongToFitInTransmitBuffer = 1,

    /**
     * @~Chinese
     * @brief 在I2C发送地址时收到NACK。
     */
    /**
     * @~English
     * @brief NACK received on I2C transmit of address.
     */
    kI2cReceivedNackOnTransmitOfAddress = 2,

    /**
     * @~Chinese
     * @brief 在I2C发送数据时收到NACK。
     */
    /**
     * @~English
     * @brief NACK received on I2C transmit of data.
     */
    kI2cReceivedNackOnTransmitOfData = 3,

    /**
     * @~Chinese
     * @brief 其他I2C错误。
     */
    /**
     * @~English
     * @brief Other I2C errors.
     */
    kI2cOtherError = 4,

    /**
     * @~Chinese
     * @brief I2C通讯超时。
     */
    /**
     * @~English
     * @brief I2C communication timed out.
     */
    kI2cTimeout = 5,

    /**
     * @~Chinese
     * @brief 参数错误。
     */
    /**
     * @~English
     * @brief Invalid parameter.
     */
    kInvalidParameter = 6,

    /**
     * @~Chinese
     * @brief 未知错误。
     */
    /**
     * @~English
     * @brief Unknown error.
     */
    kUnknownError = 7,
  };

  /**
   * @~Chinese
   * @brief 构造函数，指定 I2C 地址和 TwoWire 对象。
   * @param i2c_address I2C 地址，默认为 @ref kDefaultI2cAddress 。
   * @param wire TwoWire 对象引用，默认为 Wire。
   */
  /**
   * @~English
   * @brief Constructor, specifying I2C address and TwoWire object.
   * @param i2c_address I2C address, defaults to @ref kDefaultI2cAddress.
   * @param wire TwoWire object reference, defaults to Wire.
   */
  explicit DummyDevice(const uint8_t i2c_address = kDefaultI2cAddress, TwoWire& wire = Wire);

  /**
   * @~Chinese
   * @brief 构造函数，使用默认 I2C 地址和指定的 TwoWire 对象。
   * @param wire TwoWire 对象引用。
   */
  /**
   * @~English
   * @brief Constructor using the default I2C address and a specified TwoWire object.
   * @param wire TwoWire object reference.
   */
  explicit DummyDevice(TwoWire& wire) : DummyDevice(kDefaultI2cAddress, wire) {
  }

  /**
   * @~Chinese
   * @brief 初始化函数，对设备进行初始化
   * @return 返回值请参考 @ref ErrorCode 。
   */
  /**
   * @~English
   * @brief Initialization function to initialize the device.
   * @return Please refer to @ref ErrorCode for the return value.
   */
  ErrorCode Init();

  /**
   * @~Chinese
   * @brief 向设备写入数据
   * @param[in] data 数据
   * @param[in] length 数据长度
   * @return 返回值请参考 @ref ErrorCode 。
   */
  /**
   * @~English
   * @brief Write data to the device.
   * @param[in] data The data.
   * @param[in] length The length of the data.
   * @return Please refer to @ref ErrorCode for the return value.
   */
  ErrorCode Write(const uint8_t* data, const uint32_t length);

  /**
   * @~Chinese
   * @brief 从设备读取数据
   * @param[in] buffer 数据存取地址
   * @param[in] expected_length 期望读取的数据长度
   * @param[out] actual_length 实际读取的数据长度
   * @return 返回值请参考 @ref ErrorCode 。
   */
  /**
   * @~English
   * @brief Read data from the device.
   * @param[in] buffer The address for data access.
   * @param[in] expected_length The expected length of the data to be read.
   * @param[out] actual_length The actual length of the data that has been read.
   * @return Please refer to @ref ErrorCode for the return value.
   */
  ErrorCode Read(const uint8_t* buffer, const uint32_t expected_length, uint32_t* const actual_length);

 private:
  DummyDevice(const DummyDevice&) = delete;
  DummyDevice& operator=(const DummyDevice&) = delete;

  const uint8_t i2c_address_ = kDefaultI2cAddress;
  TwoWire& wire_ = Wire;
};
}  // namespace em
#endif