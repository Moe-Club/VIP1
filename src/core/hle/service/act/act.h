// Copyright 2016 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#pragma once

#include "common/common_types.h"
#include "core/hle/service/service.h"

namespace Service {
namespace ACT {

enum class BlkID : u32 {
    PersistentID = 0x5,
    TransferableIDBase = 0x6,
    MiiData = 0x7,
    NNID = 0x8,
    Birthday = 0xA,
    CountryName = 0xB,
    PrincipalID = 0xC,
    Unknown = 0xE,
    Unknown2 = 0xF,
    InfoStruct = 0x11,
    Unknown3 = 0x12,
    Gender = 0x13,
    Unknown4 = 0x14,
    NNID2 = 0x15,
    Unknown5 = 0x16,
    Unknown6 = 0x17,
    UTCOffset = 0x19,
    Unknown7 = 0x1A,
    U16MiiName = 0x1B,
    NNID3 = 0x1C,
    Unknown8 = 0x1D,
    TimeZoneLocation = 0x1E,
    Unknown9 = 0x1F,
    Unknown10 = 0x20,
    Unknown11 = 0x24,
    MiiImageURL = 0x25,
    PrincipleID = 0x26,
    Unknown12 = 0x27,
    Unknown13 = 0x28,
    Unknown14 = 0x2B,
    Age = 0x2C,
    Unknown15 = 0x2D,
    Unknown16 = 0x2E,
    CountryInfo = 0x2F
};

struct Birthday {
    u16 year;
    u8 month;
    u8 day;
};

struct InfoBlock {
    u32 PersistentID;
    u32 padding;
    u64 TransferableIDBase;
    u8 MiiData[0x60];
    char16_t MachinUserName[0xB];
    char AccountID[0x11];
    u8 padding2;
    Birthday birthday;
    u32 PrincipalID;
};

class Module final {
public:
    class Interface : public ServiceFramework<Interface> {
    public:
        Interface(std::shared_ptr<Module> act, const char* name, u32 max_session);

    protected:
        /**
         * ACT::Initialize service function
         *  Inputs:
         *      1 : SDK Version
         *      2 : Shared memory size
         *      3 : 0x20 (Kernel PID header)
         *      4 : 0x20 (The code to request the current process handle)
         *      5 : 0x00 (handle-transfer header for kernel)
         *      6 : Shared memory address value
         *  Outputs:
         *      1 : Result of function, 0 on success, otherwise error code
         */
        void Initialize(Kernel::HLERequestContext& ctx);

        /**
         * ACT::GetErrorCode service function.
         *  Inputs:
         *      1 : Input error code
         *  Outputs:
         *      1 : Result of function, 0 on success, otherwise error code
         *      2 : Output value
         */
        void GetErrorCode(Kernel::HLERequestContext& ctx);

        /**
         * ACT::GetAccountDataBlock service function
         *  Inputs:
         *      1 : Unknown, usually 0xFE?
         *      2 : Size
         *      3 : BlkID
         *      4 : (Size<<4) | 12
         *      5 : Output buffer ptr
         *  Outputs:
         *      1 : Result of function, 0 on success, otherwise error code
         */
        void GetAccountDataBlock(Kernel::HLERequestContext& ctx);

    private:
        std::shared_ptr<Module> act;
    };
};

void InstallInterfaces(SM::ServiceManager& service_manager);

} // namespace ACT
} // namespace Service
