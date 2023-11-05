#include "EInlineBlock.h"
#include "imgui.h"

namespace CEngine {
    void EInlineBlock::render() {
        renderChildren();
        ImGui::SameLine();
    }

    IElement *EInlineBlock::copy() {
        return new EInlineBlock;
    }
}