#ifndef CATALYST_ENGINE_TEXTCOMPONENT_H
#define CATALYST_ENGINE_TEXTCOMPONENT_H
#pragma once

#include "UI.h"
#include "../../libs/imgui/imgui.h"
#include "AbstractUIComponent.h"

namespace Text {
    ImFont *currentActiveFont = nullptr;

    class TextComponent : public AbstractUIComponent {
    private:
        std::string text = "";
        ImFont *font = nullptr;
    public:
        void setText(std::string c) {
            text = c;
        }

        void render() override {
            bool isFontValid = font != nullptr && font != currentActiveFont;
            if (isFontValid) {
                ImGui::PopFont();
                ImGui::PushFont(font);
                currentActiveFont = font;
            } else {
                currentActiveFont = nullptr;
            }
            ImGui::Text(nullptr, &text);
        }
    };

}
#endif