#include "IEventPayload.h"

namespace Catalyst {
    IEventPayload::IEventPayload(const char *type) {
        eventType = type;
    }

    IEventPayload::IEventPayload(const char *type, IElement *t) {
        eventType = type;
        target = t;
    }

    const std::string &IEventPayload::getEventType() const {
        return eventType;
    }

    IElement *IEventPayload::getTarget() const {
        return target;
    }
}