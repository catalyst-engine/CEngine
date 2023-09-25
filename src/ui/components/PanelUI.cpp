
#include "PanelUI.h"

void PanelUI::render() {
    ImGui::Begin("Hello, world 2!");
    renderChildren();
    ImGui::End();
}
