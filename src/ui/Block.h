//
// Created by russi on 9/23/2023.
//

#ifndef CATALYST_ENGINE_BLOCK_H
#define CATALYST_ENGINE_BLOCK_H


#include "UIComponent.h"
#include "../../libs/imgui/imgui.h"

class Block : public ui::AbstractUI {
public:
    void Render() override {
        ImGui::Begin("Hello, world 2!");
        ImGui::Text("This is some useful text.");
        ImGui::End();
    }
};

#endif //CATALYST_ENGINE_BLOCK_H
