// Copyright 2018 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#pragma once

#include <memory>
#include "core/hle/service/mcu/mcu.h"

namespace Service {
namespace MCU {

class NWM final : public Module::Interface {
public:
    explicit NWM(std::shared_ptr<Module> mcu);
};

} // namespace MCU
} // namespace Service
