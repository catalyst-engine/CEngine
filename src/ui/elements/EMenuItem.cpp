#include "EMenuItem.h"
#include "imgui.h"

namespace Catalyst {
    void EMenuItem::render() {
        clicked = ImGui::MenuItem(title.c_str(), shortcut.c_str(), clicked, enabled);
        if (addSeparator) {
            ImGui::Separator();
        }
    }

    bool EMenuItem::isClicked() const {
        return clicked;
    }

    void EMenuItem::setShortcut(std::string t) {
        shortcut = std::move(t);
    }

    std::string EMenuItem::getShortcut() {
        return shortcut;
    }

    void EMenuItem::collectAttributes(pugi::xml_node node) {
        AbstractTitledElement::collectAttributes(node);
        shortcut = node.attribute("shortcut").as_string();
        enabled = node.attribute("enabled").as_bool();
        clicked = node.attribute("selected").as_bool();
        addSeparator = node.attribute("addSeparator").as_bool();
    }

    IElement *EMenuItem::copy() {
        return new EMenuItem;
    }

}