#include "EventControllerTest.h"
#include "catch2/catch_all.hpp"
#include "../../Tester.h"
#include "../../../src/ui/event/IListener.h"
#include "Listener.h"
#include "../../../src/ui/event/EventController.h"
#include "ListenerPayload.h"

namespace Catalyst::EventControllerTest {
    void shouldTriggerEvent() {
        auto l = new Listener;
        EventController::addListener("click", l);
        EventController::triggerEvent("click");

        REQUIRE(l->called == true);
    }

    void shouldTriggerEventByPayload() {
        auto l = new Listener;
        ListenerPayload p("click", 1);

        EventController::addListener("click", l);
        EventController::triggerEvent(p);

        REQUIRE(l->called == true);
        REQUIRE(l->event == &p);
    }

    void shouldNotTriggerEvent() {
        auto l = new Listener;
        EventController::addListener("click", l);
        EventController::removeListener("click", l);
        EventController::triggerEvent("click");

        REQUIRE(l->called == false);
    }

    void shouldTriggerMultiple() {
        auto l = new Listener;
        auto l1 = new Listener;
        auto l2 = new Listener;
        EventController::addListener("click", l);
        EventController::addListener("click1", l1);
        EventController::addListener("click2", l2);
        EventController::triggerEvent("click");
        EventController::triggerEvent("click1");
        EventController::triggerEvent("click2");

        REQUIRE(l->called == true);
        REQUIRE(l1->called == true);
        REQUIRE(l2->called == true);
    }


    Tester *createTester() {
        auto tester = new Tester("EventControllerTest");
        tester->registerTest("Should trigger event", shouldTriggerEvent);
        tester->registerTest("Should not trigger event", shouldNotTriggerEvent);
        tester->registerTest("Should trigger multiple events", shouldTriggerMultiple);
        tester->registerTest("Should trigger event by payload", shouldTriggerEventByPayload);
        return tester;
    }
}