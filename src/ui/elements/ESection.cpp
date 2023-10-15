#include "ESection.h"

namespace Catalyst {
    void ESection::render() {
        ImGui::Begin(title.c_str());
        renderChildren();
        ImGui::End();
    }

    IElement *ESection::copy() {
        return new ESection;
    }
}