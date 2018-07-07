// Copyright 2016 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include "common/string_util.h"
#include "core/core.h"
#include "core/hle/applets/erreula.h"

namespace HLE {
namespace Applets {

ResultCode ErrEula::ReceiveParameter(const Service::APT::MessageParameter& parameter) {
    if (parameter.signal != Service::APT::SignalType::Request) {
        LOG_ERROR(Applet_ErrEula, "unsupported signal {}", static_cast<u32>(parameter.signal));
        UNIMPLEMENTED();
        // TODO(Subv): Find the right error code
        return ResultCode(-1);
    }

    // The LibAppJustStarted message contains a buffer with the size of the framebuffer shared
    // memory.
    // Create the SharedMemory that will hold the framebuffer data
    Service::APT::CaptureBufferInfo capture_info;
    ASSERT(sizeof(capture_info) == parameter.buffer.size());

    memcpy(&capture_info, parameter.buffer.data(), sizeof(capture_info));

    // TODO: allocated memory never released
    using Kernel::MemoryPermission;
    // Allocate a heap block of the required size for this applet.
    heap_memory = std::make_shared<std::vector<u8>>(capture_info.size);
    // Create a SharedMemory that directly points to this heap block.
    framebuffer_memory = Kernel::SharedMemory::CreateForApplet(
        heap_memory, 0, capture_info.size, MemoryPermission::ReadWrite, MemoryPermission::ReadWrite,
        "ErrEula Memory");

    // Send the response message with the newly created SharedMemory
    Service::APT::MessageParameter result;
    result.signal = Service::APT::SignalType::Response;
    result.buffer.clear();
    result.destination_id = Service::APT::AppletId::Application;
    result.sender_id = id;
    result.object = framebuffer_memory;

    SendParameter(result);
    return RESULT_SUCCESS;
}

ResultCode ErrEula::StartImpl(const Service::APT::AppletStartupParameter& parameter) {
    is_running = true;

    ASSERT_MSG(parameter.buffer.size() == sizeof(config),
               "The size of the parameter (ErrEulaConfig) is wrong");

    std::memcpy(&config, parameter.buffer.data(), parameter.buffer.size());

    return RESULT_SUCCESS;
}

void ErrEula::Update() {
    if (Core::System::GetInstance().GetAppletFactories().erreula.IsRegistered("qt")) {
        Core::System::GetInstance().GetAppletFactories().erreula.Launch("qt", config);
        Finalize();
        return;
    }

    switch (config.error_type) {
    case ErrEulaErrorType::ErrorCode: {
        LOG_INFO(Applet_ErrEula, "Error Code: {:#010X}", config.error_code);
        break;
    }
    case ErrEulaErrorType::LocalizedErrorText:
    case ErrEulaErrorType::ErrorText: {
        LOG_INFO(Applet_ErrEula, "Error Code: {:#x}", config.error_code);
        LOG_INFO(Applet_ErrEula, "Error Text: {}", Common::UTF16ToUTF8(config.error_text));
        break;
    }
    case ErrEulaErrorType::Agree:
    case ErrEulaErrorType::Eula:
    case ErrEulaErrorType::EulaDrawOnly:
    case ErrEulaErrorType::EulaFirstBoot: {
        LOG_INFO(Applet_ErrEula, "EULA accepted");
        break;
    }
    }

    config.return_code = ErrEulaResult::Success;
    Finalize();
}

void ErrEula::Finalize() {
    // Let the application know that we're closing
    Service::APT::MessageParameter message;
    message.buffer.resize(sizeof(config));
    std::memcpy(message.buffer.data(), &config, message.buffer.size());
    message.signal = Service::APT::SignalType::WakeupByExit;
    message.destination_id = Service::APT::AppletId::Application;
    message.sender_id = id;
    SendParameter(message);

    is_running = false;
}
} // namespace Applets
} // namespace HLE
