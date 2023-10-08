#include "Editor.h"
#include "../../ui/core/ViewFactory.h"
#include "../../ui/core/ControllerFactory.h"
#include "../../ui/core/Window.h"
#include "controllers/EditorController.h"

namespace Catalyst::editor {
    void init(Catalyst::ui::Window &window) {
        Catalyst::ui::ViewFactory::init();
        Catalyst::ui::ControllerFactory::init();

        Catalyst::ui::ControllerFactory::registerController<EditorController>("EditorController");

        window.getBuilder()->loadFromXML("EditorView.xml");
    }
}