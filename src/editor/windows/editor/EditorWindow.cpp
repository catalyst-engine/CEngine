#include "EditorWindow.h"
#include "../../core/document/Document.h"
#include "views/hierarchy/HierarchyView.h"
#include "views/MainView.h"

namespace Catalyst {
    void EditorWindow::init() {
        Document::registerView("MainView", new MainView);
        Document::registerView("HierarchyView", new HierarchyView);
        document->addView("MainView");

    }
}
