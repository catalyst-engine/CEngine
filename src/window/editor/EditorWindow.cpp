#include "EditorWindow.h"
#include "../../ui/document/Document.h"
#include "views/HierarchyView.h"
#include "views/MainView.h"

namespace Catalyst {
    void EditorWindow::init() {
        Document::registerView("MainView", new MainView);
        Document::registerView("HierarchyView", new HierarchyView);
        document->addView("MainView");

    }
}
