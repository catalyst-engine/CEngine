#include <catch2/catch_all.hpp>
#include "../../src/util/structures/Map.cpp"

using namespace Catalyst;

TEST_CASE("Should add elements", "[map-add]") {
    Map<std::string, int> map;
    int value = 1;
    int value2 = 2;
    int value3 = 3;

    map.set("one", value);
    map.set("two", value2);
    map.set("three", value3);

    REQUIRE(map.getKeys().size() == 3);
    REQUIRE(map.get("two") == value2);
    REQUIRE(map.getSize() == 3);
}

TEST_CASE("Should have key", "[map-has]") {
    Map<std::string, int> map;
    int value3 = 3;
    map.set("three",value3);
    REQUIRE(map.has("three") == true);
}

TEST_CASE("Should not have key", "[map-has2]") {
    Map<std::string, int> map;
    REQUIRE(map.has("three") == false);
}

TEST_CASE("Should remove element", "[map-remove]") {
    Map<std::string, int> map;
    int value = 1;
    int value2 = 2;
    int value3 = 3;

    map.set("one", value);
    map.set("two", value2);
    map.set("three", value3);

    REQUIRE(map.getKeys().size() == 3);
    map.deleteKey("two");
    REQUIRE(map.get("two") == 0);
    REQUIRE(map.getKeys().size() == 2);
}

TEST_CASE("Should have element", "[map-get]") {
    struct Test {
        int a;
    };
    Map<std::string, Test*> map;
    Test value = Test{1};
    map.set("instance", &value);

    REQUIRE(map.get("instance") == &value);
}

TEST_CASE("Should return nullptr", "[map-get2]") {
    Map<std::string, int> map;
    REQUIRE(map.get("instance") == 0);
}

TEST_CASE("Should do nothing", "[map-remove]") {
    Map<std::string, int> map;
    map.deleteKey("instance");
}

TEST_CASE("Should clear", "[map-clear]") {
    Map<std::string, int> map;
    int value = 1;
    int value2 = 2;
    int value3 = 3;

    map.set("one", value);
    map.set("two", value2);
    map.set("three", value3);

    REQUIRE(map.getKeys().size() == 3);
    map.clear();
    REQUIRE(map.getKeys().size() == 0);
    REQUIRE(map.get("one") == 0);
}

TEST_CASE("Should return keys", "[map-keys]") {
    Map<const char *, int> map;
    int value = 1;
    int value2 = 2;
    int value3 = 3;
    bool existsKey1 = false;
    bool existsKey2 = false;
    bool existsKey3 = false;
    map.set("one", value);
    map.set("two", value2);
    map.set("three", value3);
    auto keys = map.getKeys();
    for (int i = 0; i < 3; i++) {
        if (strcmp(keys[i], "one") == 0) {
            existsKey1 = true;
        }
        if (strcmp(keys[i], "two") == 0) {
            existsKey2 = true;
        }
        if (strcmp(keys[i], "three") == 0) {
            existsKey3 = true;
        }
    }
    REQUIRE(existsKey1 == true);
    REQUIRE(existsKey2 == true);
    REQUIRE(existsKey3 == true);
}