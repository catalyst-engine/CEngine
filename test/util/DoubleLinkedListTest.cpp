#define CATCH_CONFIG_MAIN

#include <catch.hpp>
#include "../../src/util/DoubleLinkedList.h"

TEST_CASE("Should add elements to list", "[list-add]") {
    auto *list = new Util::Basic::DoubleLinkedList<int>();
    int value = 1;
    int value2 = 2;
    int value3 = 3;
    list->push(&value);
    list->push(&value2);
    list->push(&value3);

    REQUIRE(list->getLength() == 3);
}

TEST_CASE("Should replaceAtIndex", "[list-replace]") {
    auto *list = new Util::Basic::DoubleLinkedList<int>();
    int value = 1;
    int value2 = 2;
    list->push(&value);
    REQUIRE(list->get(0) == &value);
    list->replaceAt(0, &value2);
    REQUIRE(list->get(0) == &value2);
    REQUIRE(list->getLength() == 1);
}

TEST_CASE("Should remove element from list", "[list-remove]") {
    auto *list = new Util::Basic::DoubleLinkedList<int>();
    int value = 1;
    list->push(&value);

    REQUIRE(list->getLength() == 1);
    list->pop();
    REQUIRE(list->getLength() == 0);
}

TEST_CASE("Should remove element from index", "[list-remove-index]") {
    auto *list = new Util::Basic::DoubleLinkedList<int>();
    int value = 1;
    int value2 = 2;
    int value3 = 3;

    list->push(&value);
    list->push(&value2);
    list->push(&value3);
    list->removeAt(2);

    REQUIRE(list->includes(&value3) == false);
    REQUIRE(list->getLength() == 2);
}

TEST_CASE("Should iterate", "[list-iterate]") {
    auto *list = new Util::Basic::DoubleLinkedList<int>();
    int value = 1;
    int value2 = 2;
    int value3 = 3;

    list->push(&value);
    list->push(&value2);
    list->push(&value3);

    REQUIRE(list->hasNext() == false);
    list->iterate();
    REQUIRE(list->hasNext() == true);
    list->next();
    list->next();
    REQUIRE(list->hasNext() == true);
    list->next();
    REQUIRE(list->hasNext() == false);
}