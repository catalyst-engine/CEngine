#ifndef CATALYST_EDITORVIEW_H
#define CATALYST_EDITORVIEW_H

#include <memory>
#include "../../../ui/views/IView.h"
#include "spdlog/logger.h"

namespace Catalyst {
    class EText;
    class EditorView : public IView {
    private:
        std::shared_ptr<spdlog::logger> logger;
        int i = 0;
        EText *textField;
    public:
        void update() override;

        void onInitialize() override;
    };
}
#endif
