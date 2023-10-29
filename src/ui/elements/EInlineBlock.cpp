#include "EInlineBlock.h"
#include "imgui.h"

namespace Catalyst {
    void EInlineBlock::render() {
        renderChildren();
        ImGui::SameLine();
    }

    IElement *EInlineBlock::copy() {
        return new EInlineBlock;
    }
}