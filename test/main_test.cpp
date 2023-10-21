#include "catch2/catch_all.hpp"
#include "engine/EngineTest.h"
#include "Tester.h"
#include "util/LoggerTest.h"
#include "util/ListTest.h"
#include "util/MapTest.h"
#include "ui/document/DocumentTest.h"
#include "ui/event/EventControllerTest.h"

void run(int ind, bool all) {
    if (ind == 0 || all) {
        Tester *tester = Catalyst::EngineTest::createTester();
        tester->run();
    }
    if (ind == 1 || all) {
        Tester *tester = Catalyst::LoggerTest::createTester();
        tester->run();
    }
    if (ind == 2 || all) {
        Tester *tester = Catalyst::ListTest::createTester();
        tester->run();
    }
    if (ind == 3 || all) {
        Tester *tester = Catalyst::MapTest::createTester();
        tester->run();
    }
    if (ind == 4 || all) {
        Tester *tester = Catalyst::DocumentTest::createTester();
        tester->run();
    }
    if (ind == 5 || all) {
        Tester *tester = Catalyst::EventControllerTest::createTester();
        tester->run();
    }
}

TEST_CASE("Engine test", "[engine-test]") {
    run(0, false);
}

TEST_CASE("Logger test", "[logger-test]") {
    run(1, false);
}

TEST_CASE("List test", "[list-test]") {
    run(2, false);
}

TEST_CASE("Map test", "[map-test]") {
    run(3, false);
}

TEST_CASE("Document test", "[document-test]") {
    run(4, false);
}

TEST_CASE("EventController test", "[event-controller-test]") {
    run(5, false);
}

TEST_CASE("Run all", "[RUN_ALL]") {
    run(-1, true);
}