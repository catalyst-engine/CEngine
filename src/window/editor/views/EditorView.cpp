#include "EditorView.h"
#include "../../../ui/elements/EText.h"
#include "imgui.h"

namespace Catalyst {
    void EditorView::update() {
//        i++;
//        textField->setText(std::to_string(i));
    }

    void EditorView::onInitialize() {
        textField =  (EText*) getChildren()->getFirstValue()->getChildren()->getFirstValue();
    }

    void EditorView::render() {
        IElement::render();
        static bool show = true;
        ImGui::ShowDemoWindow(&show);
    }
}