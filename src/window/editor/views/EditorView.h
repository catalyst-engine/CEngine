#ifndef CATALYST_EDITORVIEW_H
#define CATALYST_EDITORVIEW_H

#include <memory>
#include "../../../ui/views/IView.h"
#include "spdlog/logger.h"

namespace Catalyst {
    class EditorView : public IView {
    private:
        std::shared_ptr<spdlog::logger> logger;
        int i = 0;
    public:
        void update() override;
    };
}
#endif
