
#ifndef CATALYST_IEVENTPAYLOAD_H
#define CATALYST_IEVENTPAYLOAD_H

#include <string>

namespace Catalyst {
    class IEventPayload {
    private:
        std::string eventType;
    public:
        explicit IEventPayload(const char *type);

        const std::string &getEventType() const;
    };
}

#endif
