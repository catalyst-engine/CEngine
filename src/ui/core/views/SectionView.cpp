#include "SectionView.h"
namespace Catalyst::ui {
    void SectionView::render() {
        ImGui::Begin("Hello, world 2!");
        renderChildren();
        ImGui::End();
    }
}