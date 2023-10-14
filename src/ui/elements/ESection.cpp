#include "ESection.h"

namespace Catalyst {
    void ESection::render() {
        ImGui::Begin(title.c_str());
        renderChildren();
        ImGui::End();
    }

    void ESection::collectAttributes(pugi::xml_node node) {
        title = node.attribute("title").as_string();
    }

    IElement *ESection::copy() {
        return new ESection;
    }
}