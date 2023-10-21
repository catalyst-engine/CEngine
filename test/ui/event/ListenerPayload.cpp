#include "ListenerPayload.h"

namespace Catalyst {
    template<typename T>
    T ListenerPayload<T>::getMessage() {
        return message;
    }

    template<typename T>
    ListenerPayload<T>::ListenerPayload(const char *evT, T m) : IEventPayload(evT) {
        message = m;
    }
}