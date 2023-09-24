#ifndef CATALYST_ENGINE_BLOCKCOMPONENT_H
#define CATALYST_ENGINE_BLOCKCOMPONENT_H
#pragma once

#include "UI.h"
#include "../../libs/imgui/imgui.h"
#include "AbstractUIComponent.h"

class BlockComponent : public AbstractUIComponent {
public:
    void render() override {
        ImGui::Begin("Hello, world 2!");
        renderChildren();
        ImGui::End();
    }
};

#endif