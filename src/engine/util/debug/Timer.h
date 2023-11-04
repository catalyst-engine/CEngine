#pragma once
#ifndef CATALYST_TIMER_H
#define CATALYST_TIMER_H

#include "ILoggable.h"
#include <chrono>

namespace CEngine {
    template<typename K, typename V>
    class Map;

    class Timer : public ILoggable {
    private:
        static Map<const char *, long long> state;
        std::chrono::time_point<std::chrono::high_resolution_clock> start;
        const char *name;

        void finish();

    public:
        static Map<const char *, long long> *getState();

        explicit Timer(const char *name) : ILoggable(name) {
            this->name = name;
            start = std::chrono::high_resolution_clock::now();
        }

        ~Timer() {
            finish();
        }
    };

}

#endif //CATALYST_TIMER_H
