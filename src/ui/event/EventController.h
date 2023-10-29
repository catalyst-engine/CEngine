#ifndef CATALYST_EVENTCONTROLLER_H
#define CATALYST_EVENTCONTROLLER_H

#include <string>
#include "../../util/debug/ILoggable.h"
#include "../elements/IElement.h"

namespace Catalyst {
    class IListener;

    class ListenerWrapper;

    class IEventPayload;

    template<typename K, typename V>
    class Map;

    class EventController : public ILoggable {
    private:
        static EventController *instance;

        static Map<std::string, ListenerWrapper *> wrappers;

        static ListenerWrapper *getWrapper(const std::string &eventType, bool createIfNotPresent);

        explicit EventController();

    public:
        static EventController *get();

        void addListener(std::string eventType, IListener *listener);

        void removeListener(std::string eventType, IListener *listener);

        void triggerEvent(IEventPayload &payload);

        void triggerEvent(const std::string& eventType);

        void triggerEvent(const std::string& eventType, Catalyst::IElement *target);
    };

}

#endif
