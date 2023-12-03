#include <catch2/catch_all.hpp>
#include "../../src/util/structures/Map.cpp"
#include "debug/Timer.h"
#include "../Tester.h"

namespace CEngine::TimerTest {


    const char *name = "EXECUTION";

    void execute() {
        Timer t(name);
        int i = 0;
        while (i < 1000000) {
            i++;
        }
    }

    void track() {
        execute();
        long long value = Timer::getState()->get(name);
        REQUIRE(Timer::getState()->has(name) == true);
        REQUIRE(value > 0L);
    }

    Tester *createTester() {
        auto *tester = new Tester("TimerTest");
        tester->registerTest("Should track time", track);
        return tester;
    }
}