#include "EditorWindow.h"
#include "views/EditorView.h"
#include "../../ui/core/Document.h"
#include "views/HierarchyView.h"

namespace Catalyst {
    void EditorWindow::init() {
        document->addView<EditorView>();
        document->addView<HierarchyView>();
    }
}
