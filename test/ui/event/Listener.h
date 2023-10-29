#ifndef CATALYST_LISTENER_H
#define CATALYST_LISTENER_H

#include "../../../src/ui/event/IListener.h"

namespace Catalyst {

    class Listener : public IListener {
    private:
        void onEvent(Catalyst::IEventPayload *payload) override;
    public:
        bool called = false;
        IEventPayload *event = nullptr;
    };
}

#endif
