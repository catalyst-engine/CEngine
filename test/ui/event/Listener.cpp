#include "Listener.h"

namespace CEngine {
    void Listener::onEvent(CEngine::IEventPayload *payload) {
        called = true;
        event = payload;
    }
}