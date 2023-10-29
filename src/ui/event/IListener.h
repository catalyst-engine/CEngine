#ifndef CATALYST_ILISTENER_H
#define CATALYST_ILISTENER_H

#include <string>
#include "../../util/debug/ILoggable.h"

namespace Catalyst {
    class IEventPayload;

    class IListener : public ILoggable {
    public:
        virtual void onEvent(IEventPayload *payload);
    };

}

#endif
