#ifndef CATALYST_LISTENERPAYLOAD_H
#define CATALYST_LISTENERPAYLOAD_H

#include "../../../src/ui/event/IEventPayload.h"

namespace Catalyst {

    template<typename T>
    class ListenerPayload : public IEventPayload {
    private:
        T message;
    public:

        T getMessage();

        explicit ListenerPayload(const char string[6], T message);
    };
}

#endif
