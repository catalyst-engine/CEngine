#include "TextView.h"
#include "imgui.h"

#include <utility>

namespace Catalyst::ui {

    void TextView::render() {
        ImGui::Text("%s", text.c_str());
    }

    void TextView::setText(std::string textV) {
        text = std::move(textV);
    }

    void TextView::load(pugi::xml_node node) {
        setText(node.text().as_string());
    }
}
