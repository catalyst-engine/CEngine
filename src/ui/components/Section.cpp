#include "Section.h"
namespace Catalyst::ui {
    void Section::render() {
        ImGui::Begin("Hello, world 2!");
        renderChildren();
        ImGui::End();
    }
}