#pragma once

#include "UI.h"
#include "../../libs/imgui/imgui.h"

namespace Text {
    ImFont *currentActiveFont = nullptr;

    class Text : public UI::AbstractUI {
    private:
        char const *text = "";
        ImFont *font = nullptr;
    public:
        void setText(char const *c) {
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
            ImGui::Text(text);
        }
    };

}