#include "EText.h"
#include "imgui.h"

#include <utility>

namespace Catalyst::ui {

    void EText::render() {
        ImGui::Text("%s", text.c_str());
    }

    void EText::setText(std::string textV) {
        text = std::move(textV);
    }

    void EText::collectAttributes(pugi::xml_node node) {
        setText(node.text().as_string());
    }

    IElement *EText::copy() {
        return new EText;
    }
}
