#include <catch2/catch_all.hpp>
#include "../../src/util/ILoggable.h"

class Example : public Catalyst::ILoggable {
public:
    Example() : Catalyst::ILoggable("Example") {
    }

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

    bool hasLogger() {
        return getLogger() != nullptr;
    }
};

TEST_CASE("Should set info", "[log-info]") {
    Example c;
    c.log();
    REQUIRE(c.hasLogger() == true);
    REQUIRE(c.getLoggingLevel() == spdlog::level::info);
}

TEST_CASE("Should set warn", "[log-warn]") {
    Example c;
    c.warn();
    REQUIRE(c.hasLogger() == true);
    REQUIRE(c.getLoggingLevel() == spdlog::level::warn);
}

TEST_CASE("Should set error", "[log-err]") {
    Example c;
    c.error();
    REQUIRE(c.hasLogger() == true);
    REQUIRE(c.getLoggingLevel() == spdlog::level::err);
}

TEST_CASE("Should set trace", "[log-trace]") {
    Example c;
    c.trace();
    REQUIRE(c.hasLogger() == true);
    REQUIRE(c.getLoggingLevel() == spdlog::level::trace);
}