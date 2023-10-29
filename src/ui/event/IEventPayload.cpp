#include "IEventPayload.h"

#include <utility>

namespace Catalyst {

    IEventPayload::IEventPayload(std::string type, IElement *t) {
        eventType = std::move(type);
        target = t;
    }

    const std::string &IEventPayload::getEventType() const {
        return eventType;
    }

    IElement *IEventPayload::getTarget() const {
        return target;
    }

    IEventPayload::IEventPayload(std::string type) {
        eventType = std::move(type);
    }
}