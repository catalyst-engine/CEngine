
#ifndef CATALYST_IEVENTPAYLOAD_H
#define CATALYST_IEVENTPAYLOAD_H

#include <string>

namespace Catalyst {
    class IElement;

    class IEventPayload {
    private:
        std::string eventType;
        IElement *target = nullptr;
    public:
        explicit IEventPayload(std::string type, IElement *target);

        explicit IEventPayload(std::string type);

        const std::string &getEventType() const;

        IElement *getTarget() const;
    };
}

#endif
