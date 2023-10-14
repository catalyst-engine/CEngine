#include "EditorView.h"
#include "../../../ui/elements/EText.h"

namespace Catalyst {
    void EditorView::update() {
        i++;
        textField->setText(std::to_string(i));
    }

    void EditorView::onInitialize() {
        textField =  (EText*) getChildren()->getFirstValue()->getChildren()->getFirstValue();
    }
}