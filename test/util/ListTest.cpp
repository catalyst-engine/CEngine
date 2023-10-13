#include <catch2/catch_test_macros.hpp>
#include "../../src/util/structures/List.h"

using namespace Catalyst;

List<int> *getPopulatedList() {
    auto *list = new List<int>();
    int value = 1;
    int value2 = 2;
    int value3 = 3;

    list->push(&value);
    list->push(&value2);
    list->push(&value3);

    return list;
}

TEST_CASE("Should add elements to list", "[list-add]") {
    auto *list = getPopulatedList();
    REQUIRE(list->getLength() == 3);
}

TEST_CASE("Should replaceAtIndex", "[list-replace]") {
    auto *list = getPopulatedList();
    REQUIRE(*list->get(0) == 1);
    int two = 2;
    list->replaceAt(0, &two);
    REQUIRE(*list->get(0) == two);
}

TEST_CASE("Should remove element from list", "[list-remove]") {
    auto *list = new List<int>();
    int value = 1;
    list->push(&value);

    REQUIRE(list->getLength() == 1);
    list->pop();
    REQUIRE(list->getLength() == 0);
}

TEST_CASE("Should remove element from index", "[list-remove-index]") {
    auto *list = getPopulatedList();
    int *value3 = list->get(2);
    list->removeAt(2);
    REQUIRE(list->includes(value3) == false);
    REQUIRE(list->getLength() == 2);
}

TEST_CASE("Should iterate", "[list-iterate]") {
    auto *list = getPopulatedList();

    REQUIRE(list->hasNext() == false);
    list->iterate();
    REQUIRE(list->hasNext() == true);
    list->next();
    list->next();
    REQUIRE(list->hasNext() == true);
    list->next();
    REQUIRE(list->hasNext() == false);
}

TEST_CASE("Should get first item", "[list-first]") {
    auto *list = getPopulatedList();
    int *pInt = list->get(0);
    REQUIRE(list->getFirst()->value == pInt);
}

TEST_CASE("Should get null as first item", "[list-first-null]") {
    auto *list = new List<int>();
    REQUIRE(list->getFirst() == nullptr);
}


TEST_CASE("Should get null as last item", "[list-last-null]") {
    auto *list = new List<int>();
    REQUIRE(list->getLast() == nullptr);
}

TEST_CASE("Should get last item", "[list-last]") {
    auto *list = getPopulatedList();
    int *pInt = list->get(2);
    REQUIRE(list->getLast()->value == pInt);
}
