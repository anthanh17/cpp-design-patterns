// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SRC_BASE_MACROS_H_
#define SRC_BASE_MACROS_H_

#define DISALLOW_COPY(class_name)         \
  class_name(const class_name&) = delete; \
  [[nodiscard]] auto operator=(const class_name&)->class_name& = delete

#define DISALLOW_MOVE(class_name)    \
  class_name(class_name&&) = delete; \
  [[nodiscard]] auto operator=(class_name&&)->class_name& = delete

#define DEFAULT_COPY(class_name)           \
  class_name(const class_name&) = default; \
  [[nodiscard]] auto operator=(const class_name&)->class_name& = default

#define DEFAULT_MOVE(class_name)      \
  class_name(class_name&&) = default; \
  [[nodiscard]] auto operator=(class_name&&)->class_name& = default

#define DISALLOW_COPY_AND_MOVE(class_name) \
  DISALLOW_COPY(class_name);               \
  DISALLOW_MOVE(class_name)

#endif  // SRC_BASE_MACROS_H_
