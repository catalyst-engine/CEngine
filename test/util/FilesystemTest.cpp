#define CATCH_CONFIG_MAIN

#include "../../libs/catch2/catch.h"
#include "../../src/util/Filesystem.h"

TEST_CASE("Should create file", "[file create]") {
    auto *list = new Util::Basic::LinkedList<int>();
    int value = 1;
    int value2 = 2;
    int value3 = 3;
    list->push(&value);
    list->push(&value2);
    list->push(&value3);

    REQUIRE(list->getLength() == 3);
}