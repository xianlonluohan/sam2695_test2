#pragma once

#ifndef _EM_DUMMY_DEVICE_LIB_H_
#define _EM_DUMMY_DEVICE_LIB_H_

/**
 * @file dummy_device_lib.h
 */

/**
 * @mainpage
 * @~Chinese
 * - Github链接： https://github.com/emakefun-arduino-library/em_dummy_device
 * @~English
 * - Github link: https://github.com/emakefun-arduino-library/em_dummy_device
 */

#include <WString.h>

namespace em {
namespace dummy_device_lib {
/**
 * @~Chinese
 * @brief 主版本号。
 */
/**
 * @~English
 * @brief Major version number.
 */
constexpr uint8_t kVersionMajor = 1;

/**
 * @~Chinese
 * @brief 次版本号。
 */
/**
 * @~English
 * @brief Minor version number.
 */
constexpr uint8_t kVersionMinor = 0;

/**
 * @~Chinese
 * @brief 修订版本号。
 */
/**
 * @~English
 * @brief Patch version number.
 */
constexpr uint8_t kVersionPatch = 2;

/**
 * @~Chinese
 * @brief 获取版本号字符串。
 * @return 版本号字符串，格式为 major.minor.patch。
 */
/**
 * @~English
 * @brief Get the version number string.
 * @return The version number string in the format of major.minor.patch.
 */
String Version() {
  return String(kVersionMajor) + '.' + kVersionMinor + '.' + kVersionPatch;
}
}  // namespace dummy_device_lib
}  // namespace em
#endif