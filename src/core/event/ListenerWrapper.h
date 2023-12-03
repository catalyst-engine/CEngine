#ifndef CATALYST_LISTENERWRAPPER_H
#define CATALYST_LISTENERWRAPPER_H

#include <string>
#include "IListener.h"
#include "../../core/structures/List.h"
#include "../../core/debug/ILoggable.h"

namespace CEngine {
    class IEventPayload;

    class ListenerWrapper : public ILoggable{
    private:
        List<IListener> listeners;
    public:

        void addListener(IListener *listener);

        void removeListener(IListener *listener);

        size_t listenersSize();

        void callListeners(CEngine::IEventPayload *pPayload);
    };

}

#endif
