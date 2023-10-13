#ifndef CATALYST_ILOGGABLE_H
#define CATALYST_ILOGGABLE_H
#define CONSOLE_ERROR(...) this->setLoggingLevel(spdlog::level::err);this->getLogger()->error(__VA_ARGS__);
#define CONSOLE_WARN(...) this->setLoggingLevel(spdlog::level::warn);this->getLogger()->warn(__VA_ARGS__);
#define CONSOLE_LOG(...) this->setLoggingLevel(spdlog::level::info);this->getLogger()->info(__VA_ARGS__);
#define CONSOLE_TRACE(...) this->setLoggingLevel(spdlog::level::trace);this->getLogger()->trace(__VA_ARGS__);


#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace Catalyst {
    class ILoggable {
    private:
        std::shared_ptr<spdlog::logger> logger;
        void init(const char* name);
    public:
        static std::shared_ptr<spdlog::logger> getNewLogger(const char *name) {
            return spdlog::stdout_color_mt(name);
        }

        explicit ILoggable(const char *name);
        explicit ILoggable();

        spdlog::level::level_enum getLoggingLevel();

    protected:
        void setLoggingLevel(spdlog::level::level_enum level);

        std::shared_ptr<spdlog::logger> getLogger();
    };
}


#endif //CATALYST_ILOGGABLE_H
