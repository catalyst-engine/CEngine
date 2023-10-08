#ifndef CATALYST_EDITORCONTROLLER_H
#define CATALYST_EDITORCONTROLLER_H

#include "../../../ui/core/controllers/AbstractController.h"
#include "spdlog/logger.h"

namespace Catalyst::editor {
    class EditorController : public Catalyst::ui::AbstractController {
    private:
        std::shared_ptr<spdlog::logger> logger;
    public:
        EditorController();

        void update() override;
    };
}

#endif
