#ifndef CATALYST_EVENTCONTROLLER_H
#define CATALYST_EVENTCONTROLLER_H

#include <string>

namespace Catalyst {
    class IListener;

    class ListenerWrapper;

    class IEventPayload;

    template<typename K, typename V>
    class Map;

    class EventController {
    private:
        static Map<std::string, ListenerWrapper *> wrappers;

        static ListenerWrapper *getWrapper(const std::string& eventType, bool createIfNotPresent);

    public:
        static void addListener(const char *eventType, IListener *listener);

        static void removeListener(const char *eventType, IListener *listener);

        static void triggerEvent(IEventPayload &payload);

        static void triggerEvent(const char *eventType);
    };

}

#endif
