#include "IEventPayload.h"

namespace Catalyst {
    IEventPayload::IEventPayload(const char *type) {
        eventType = type;
    }

    const std::string &IEventPayload::getEventType() const {
        return eventType;
    }
}