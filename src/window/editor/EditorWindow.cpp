#include "EditorWindow.h"
#include "../../ui/core/Document.h"
#include "views/HierarchyView.h"
#include "views/MainView.h"

namespace Catalyst {
    void EditorWindow::init() {
        Document::registerView("HierarchyView", new HierarchyView);
        document->addView<MainView>();
    }
}
