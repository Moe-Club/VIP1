// Copyright 2016 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include "common/assert.h"
#include "core/hle/kernel/client_port.h"
#include "core/hle/kernel/client_session.h"
#include "core/hle/kernel/errors.h"
#include "core/hle/kernel/hle_ipc.h"
#include "core/hle/kernel/kernel.h"
#include "core/hle/kernel/server_port.h"
#include "core/hle/kernel/server_session.h"

namespace Kernel {

ClientPort::ClientPort() {}
ClientPort::~ClientPort() {}

ResultVal<SharedPtr<ClientSession>> ClientPort::Connect() {
    // Note: Threads do not wait for the server endpoint to call
    // AcceptSession before returning from this call.

    if (active_sessions >= max_sessions) {
        return ERR_MAX_CONNECTIONS_REACHED;
    }
    active_sessions++;

    // Create a new session pair, let the created sessions inherit the parent port's HLE handler.
    auto sessions = ServerSession::CreateSessionPair(server_port->GetName(), this);

    if (server_port->hle_handler)
        server_port->hle_handler->ClientConnected(std::get<SharedPtr<ServerSession>>(sessions));
    else
        server_port->pending_sessions.push_back(std::get<SharedPtr<ServerSession>>(sessions));

    // Wake the threads waiting on the ServerPort
    server_port->WakeupAllWaitingThreads();

    return MakeResult(std::get<SharedPtr<ClientSession>>(sessions));
}

} // namespace Kernel