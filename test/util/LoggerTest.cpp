#include <catch2/catch_all.hpp>
#include "debug/ILoggable.h"
#include "../Tester.h"

namespace Catalyst::LoggerTest {

    class Example : public Catalyst::ILoggable {
    public:
        void log() {
            CONSOLE_LOG("EXAMPLE {0}", "INJECT")
        }

        void warn() {
            CONSOLE_WARN("EXAMPLE {0}", "INJECT")
        }

        void error() {
            CONSOLE_ERROR("EXAMPLE {0}", "INJECT")
        }

        void trace() {
            CONSOLE_TRACE("EXAMPLE {0}", "INJECT")
        }

    };

    void loggerName() {
        Example c;
        c.log();
        REQUIRE(c.getLogger()->name().find("class Catalyst::LoggerTest::Example") != std::string::npos);
    }

    void loggerSwitch() {
        Example c;

        REQUIRE(c.hasLogger() == false);
        c.log();
        REQUIRE(c.hasLogger() == true);

        ILoggable::setLoggingLevel(spdlog::level::err);
        REQUIRE(c.getLoggingLevel() == spdlog::level::err);

        ILoggable::setLoggingLevel(spdlog::level::info);
        REQUIRE(c.getLoggingLevel() == spdlog::level::info);

        ILoggable::setLoggingLevel(spdlog::level::warn);
        REQUIRE(c.getLoggingLevel() == spdlog::level::warn);

        ILoggable::setLoggingLevel(spdlog::level::trace);
        REQUIRE(c.getLoggingLevel() == spdlog::level::trace);
    }

    void loggerDestroy() {
        size_t initialSize = ILoggable::activeLoggersSize();
        {
            Example c;
            c.log();
            REQUIRE(ILoggable::activeLoggersSize() == initialSize+1);
        }
        REQUIRE(ILoggable::activeLoggersSize() == initialSize);
    }

    Tester *createTester() {
        auto *tester = new Tester("LoggerTest");
        tester->registerTest("Should set logger name to class name", loggerName);
        tester->registerTest("Should destroy logger", loggerDestroy);
        tester->registerTest("Should switch logging level", loggerSwitch);
        return tester;
    }

}