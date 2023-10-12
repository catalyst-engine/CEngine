#include "Editor.h"
#include "../../ui/core/ViewFactory.h"
#include "../core/Window.h"
#include "controllers/EditorController.h"

namespace Catalyst::editor {
    void init(Catalyst::ui::Window &window) {
        Catalyst::ui::ViewFactory::init();
    }
}