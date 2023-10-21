#include "EventController.h"
#include "../../util/structures/Map.cpp"
#include "ListenerWrapper.h"
#include "IEventPayload.h"

namespace Catalyst {
    Map<std::string, ListenerWrapper *> EventController::wrappers;

    void EventController::removeListener(const char *eventType, IListener *listener) {
        ListenerWrapper *pWrapper = getWrapper(eventType, false);
        if (pWrapper == nullptr) return;
        pWrapper->removeListener(listener);

        if (pWrapper->listenersSize() == 0) {
            wrappers.deleteKey(eventType);
            delete pWrapper;
        }
    }

    void EventController::addEventListener(const char *eventType, IListener *listener) {
        ListenerWrapper *pWrapper = getWrapper(eventType, true);
        pWrapper->addListener(listener);
    }

    ListenerWrapper *EventController::getWrapper(std::string eventType, bool createIfNotPresent) {
        ListenerWrapper *pWrapper = nullptr;
        if (wrappers.has(eventType)) {
            pWrapper = wrappers.get(eventType);
        } else if (createIfNotPresent) {
            pWrapper = new ListenerWrapper;
            wrappers.set(eventType, pWrapper);
        }
        return pWrapper;
    }

    void EventController::triggerEvent(IEventPayload *payload) {
        ListenerWrapper *pWrapper = getWrapper(payload->getEventType(), false);
        if (pWrapper == nullptr) {
            return;
        }
        pWrapper->callListeners(payload);
        delete payload;
    }

    void EventController::triggerEvent(const char *eventType) {
        triggerEvent(new IEventPayload(eventType));
    }
}