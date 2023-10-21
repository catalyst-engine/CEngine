#ifndef CATALYST_ILISTENER_H
#define CATALYST_ILISTENER_H

#include <string>

namespace Catalyst {
    class IEventPayload;

    class IListener {
    public:
        virtual void onEvent(IEventPayload *payload);
    };

}

#endif
