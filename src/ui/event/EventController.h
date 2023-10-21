#ifndef CATALYST_EVENTCONTROLLER_H
#define CATALYST_EVENTCONTROLLER_H

#include <string>
#include "../../util/debug/ILoggable.h"

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

        void addListener(const char *eventType, IListener *listener);

        void removeListener(const char *eventType, IListener *listener);

        void triggerEvent(IEventPayload &payload);

        void triggerEvent(const char *eventType);
    };

}

#endif
