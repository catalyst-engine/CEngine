#include "catch2/catch_all.hpp"
#include "engine/EngineTest.h"
#include "Tester.h"
#include "util/LoggerTest.h"
#include "util/ListTest.h"
#include "util/MapTest.h"
#include "ui/DocumentTest.h"

TEST_CASE("Engine test", "[engine-test]") {
    Tester *tester = Catalyst::EngineTest::createTester();
    tester->run();
}

TEST_CASE("Logger test", "[logger-test]") {
    Tester *tester = Catalyst::LoggerTest::createTester();
    tester->run();
}

TEST_CASE("List test", "[list-test]") {
    Tester *tester = Catalyst::ListTest::createTester();
    tester->run();
}

TEST_CASE("Map test", "[map-test]") {
    Tester *tester = Catalyst::MapTest::createTester();
    tester->run();
}

TEST_CASE("Document test", "[document-test]") {
    Tester *tester = Catalyst::DocumentTest::createTester();
    tester->run();
}
