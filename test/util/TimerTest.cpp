#include <catch2/catch_all.hpp>
#include "../../src/util/structures/Map.cpp"
#include "../../src/util/Timer.h"

using namespace Catalyst;

const char* name = "EXECUTION";
void execute() {
    Timer t(name);
    int i = 0;
    while (i < 1000000) {
        i++;
    }
}

TEST_CASE("Should track time", "[track-time]") {
    execute();
    long long value = Timer::getState()->get(name);
    REQUIRE(Timer::getState()->has(name) == true);
    REQUIRE(value > 0L);
}