#include "EditorWindow.h"
#include "../../core/document/Document.h"
#include "views/hierarchy/HierarchyView.h"
#include "views/MainView.h"
#include "../../core/Runner.h"

namespace CEngine {
    void EditorWindow::onInitialize() {
        Document::registerView("MainView", new MainView);
        Document::registerView("HierarchyView", new HierarchyView);
        document->addView("MainView");
    }

    EditorWindow::EditorWindow() : IWindow() {
        document = new Document(&io, &engine);
        runner = new Runner(window, &io, document);
    }
}
