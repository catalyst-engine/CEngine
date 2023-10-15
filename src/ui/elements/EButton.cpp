#include "EButton.h"

#include <utility>
#include "imgui.h"

namespace Catalyst {
    bool EButton::isClicked() const {
        return clicked;
    }

    void EButton::render() {
        clicked = ImGui::Button(title.c_str());
    }

    const std::string &EButton::getTitle() const {
        return title;
    }

    void EButton::setTitle(std::string t) {
        EButton::title = std::move(t);
    }
}