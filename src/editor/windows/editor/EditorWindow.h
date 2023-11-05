#ifndef CATALYST_EDITORWINDOW_H
#define CATALYST_EDITORWINDOW_H


#include "../../core/IWindow.h"
#include "../../../engine/Engine.h"

namespace CEngine {
    class EditorWindow : public IWindow {
    private:
        Engine engine;
    public:
        explicit EditorWindow();
        void onInitialize() override;
    };
}

#endif
