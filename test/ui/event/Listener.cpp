#include "Listener.h"

namespace Catalyst {
    void Listener::onEvent(Catalyst::IEventPayload *payload) {
        called = true;
        event = payload;
    }
}