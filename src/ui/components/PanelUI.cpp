
#include "PanelUI.h"
namespace Catalyst::ui {
    void PanelUI::render() {
        ImGui::Begin("Hello, world 2!");
        renderChildren();
        ImGui::End();
    }
}