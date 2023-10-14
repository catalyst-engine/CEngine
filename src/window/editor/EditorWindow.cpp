#include "EditorWindow.h"
#include "views/EditorView.h"
#include "../../ui/core/Document.h"

namespace Catalyst {
    void EditorWindow::init() {
        document->addView<EditorView>();
    }
}
