#pragma once
#include "UI.h"
#include "../../libs/imgui/imgui.h"

class Block : public UI::AbstractUI {
public:
    void render() override {
        ImGui::Begin("Hello, world 2!");
        renderChildren();
        ImGui::End();
    }
};
