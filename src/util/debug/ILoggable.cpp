#include "ILoggable.h"

namespace Catalyst {
    ILoggable::ILoggable(const char *name) {
        init(name);
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

    ILoggable::ILoggable() {
        init(typeid(this).name());
    }

    void ILoggable::init(const char *name) {
        logger = spdlog::stdout_color_mt(name);
        spdlog::set_pattern("%^[%T - %n] %v%$");
    }
}