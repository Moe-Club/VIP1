// Copyright 2018 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include "core/hle/service/mcu/rtc.h"

namespace Service {
namespace MCU {

RTC::RTC(std::shared_ptr<Module> mcu) : Module::Interface(std::move(mcu), "mcu::RTC", 1) {
    static const FunctionInfo functions[] = {
        {0x00010080, nullptr, "SetRTC"},
        {0x00020000, nullptr, "GetRTC"},
        {0x00030040, nullptr, "SetRTCSeconds"},
        {0x00040000, nullptr, "GetRTCSeconds"},
        {0x00050040, nullptr, "SetRTCMinutes"},
        {0x00060000, nullptr, "GetRTCMinutes"},
        {0x00070040, nullptr, "SetRTCHours"},
        {0x00080000, nullptr, "GetRTCHours"},
        {0x00090040, nullptr, "SetRTCDayOfWeek"},
        {0x000A0000, nullptr, "GetRTCDayOfWeek"},
        {0x000B0040, nullptr, "SetRTCDayOfMonth"},
        {0x000C0000, nullptr, "GetRTCDayOfMonth"},
        {0x000D0040, nullptr, "SetRTCMonth"},
        {0x000E0000, nullptr, "GetRTCMonth"},
        {0x000F0040, nullptr, "SetRTCYear"},
        {0x00100000, nullptr, "GetRTCYear"},
        {0x00110040, nullptr, "SetRTCLeapYearCounter"},
        {0x00120000, nullptr, "GetRTCLeapYearCounter"},
        {0x00130080, nullptr, "SetRTCAlarm"},
        {0x00140000, nullptr, "GetRTCAlarm"},
        {0x00150040, nullptr, "SetRTCAlarmComponent"},
        {0x00160000, nullptr, "GetRTCAlarmComponent"},
        {0x00170040, nullptr, "SetRTCAlarmComponent1"},
        {0x00180000, nullptr, "GetRTCAlarmComponent1"},
        {0x00190040, nullptr, "SetRTCAlarmComponent2"},
        {0x001A0000, nullptr, "GetRTCAlarmComponent2"},
        {0x001B0040, nullptr, "SetRTCAlarmComponent3"},
        {0x001C0000, nullptr, "GetRTCAlarmComponent3"},
        {0x001D0040, nullptr, "SetRTCAlarmComponent4"},
        {0x001E0000, nullptr, "GetRTCAlarmComponent4"},
        {0x001F0040, nullptr, "SetPedometerRecordingMode"},
        {0x00200000, nullptr, "GetPedometerRecordingMode"},
        {0x00210080, nullptr, "GetStepCount"},
        {0x00220042, nullptr, "ReadRegister4Fh"},
        {0x00240000, nullptr, "GetPowerEventHandle"},
        {0x00250000, nullptr, "GetPowerInterruptHistory"},
        {0x00260000, nullptr, "CheckRegister02hBit0"},
        {0x00270000, nullptr, "ClearRegister02hBit0"},
        {0x00280000, nullptr, "CheckRegister02hBit1"},
        {0x00290000, nullptr, "ClearRegister02hBit1"},
        {0x002A0000, nullptr, "GetShellState"},
        {0x002B0000, nullptr, "GetAdapterState"},
        {0x002C0000, &RTC::GetBatteryChargeState, "GetBatteryChargeState"},
        {0x002D0000, &RTC::D<&RTC::GetBatteryLevel, 0x002D>, "GetBatteryLevel"},
        {0x002E0000, nullptr, "GetBatteryEmptyPatternByte0"},
        {0x002F0000, nullptr, "GetBatteryEmptyPatternByte0_safeTM"},
        {0x00300040, nullptr, "SetLEDBrightness"},
        {0x00310000, nullptr, "GetLEDBrightness"},
        {0x00320000, nullptr, "PowerOff"},
        {0x00330000, nullptr, "HardwareReboot"},
        {0x00340000, nullptr, "WriteRegister"},
        {0x00360040, nullptr, "SetWatchdogTimer"},
        {0x00370000, nullptr, "GetWatchdogTimer"},
        {0x00380042, nullptr, "ReadInfoRegister"},
        {0x00390082, nullptr, "WriteLoop"},
        {0x003A0082, nullptr, "ReadLoop"},
        {0x003B0640, nullptr, "SetInfoLEDPattern"},
        {0x003C0040, nullptr, "SetInfoLEDPatternHeader"},
        {0x003D0000, nullptr, "GetInfoLEDStatus"},
        {0x003E0040, nullptr, "WriteRegister50h"},
        {0x003F0000, nullptr, "ReadRegister50h"},
        {0x00400040, nullptr, "WriteRegister51h"},
        {0x00410000, nullptr, "ReadRegister51h"},
        {0x00420040, nullptr, "SetBatteryEmptyLEDPattern"},
        {0x00430040, nullptr, "SetScreenFlickerTop"},
        {0x00440000, nullptr, "GetScreenFlickerTop"},
        {0x00450040, nullptr, "SetScreenFlickerBottom"},
        {0x00460000, nullptr, "GetScreenFlickerBottom"},
        {0x00470080, nullptr, "SetVolumeSliderBounds"},
        {0x00480000, nullptr, "GetVolumeSliderBounds"},
        {0x00490040, nullptr, "SetInterruptMask"},
        {0x004A0000, nullptr, "GetInterruptMask"},
        {0x004B0000, nullptr, "ExitExclusiveInterruptMode"},
        {0x004C0000, nullptr, "EnterExclusiveInterruptMode"},
        {0x004D0000, nullptr, "ReadInterrupt"},
        {0x004E0040, nullptr, "TriggerInterrupt"},
        {0x004F0040, nullptr, "SetMCUFirmUpdated"},
        {0x00500000, nullptr, "IsMCUFirmUpdated"},
        {0x00510040, nullptr, "SetSoftwareClosedFlag"},
        {0x00520000, nullptr, "GetSoftwareClosedFlag"},
        {0x00590040, nullptr, "SetLegacyJumpProhibitedFlag"},
        {0x005A0000, nullptr, "GetLegacyJumpProhibitedFlag"},
    };
    RegisterHandlers(functions);
}

} // namespace MCU
} // namespace Service
