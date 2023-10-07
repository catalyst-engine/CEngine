#include "ILoggable.h"

namespace Catalyst {
    ILoggable::ILoggable(const char *name) {
        logger = spdlog::stdout_color_mt(name);
        spdlog::set_pattern("%^[%T - %n] %v%$");
    }

    std::shared_ptr<spdlog::logger> ILoggable::getLogger() {
        return logger;
    }

    void ILoggable::setLoggingLevel(spdlog::level::level_enum level) {
        logger->set_level(level);
    }

    spdlog::level::level_enum ILoggable::getLoggingLevel() {
        return logger->level();
    }
}