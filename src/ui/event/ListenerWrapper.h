#ifndef CATALYST_LISTENERWRAPPER_H
#define CATALYST_LISTENERWRAPPER_H

#include <string>
#include "IListener.h"
#include "../../util/structures/List.h"

namespace Catalyst {
    class IEventPayload;

    class ListenerWrapper {
    private:
        List<IListener> listeners;
    public:

        void addListener(IListener *listener);

        void removeListener(IListener *listener);

        size_t listenersSize();

        void callListeners(Catalyst::IEventPayload *pPayload);
    };

}

#endif
