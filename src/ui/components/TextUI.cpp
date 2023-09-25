
#include "TextUI.h"

namespace TextUI {
    ImFont *currentActiveFont = nullptr;

    void TextUI::render() {
        bool isFontValid = TextUI::font != nullptr && TextUI::font != currentActiveFont;
        if (isFontValid) {
            ImGui::PopFont();
            ImGui::PushFont(TextUI::font);
            currentActiveFont = TextUI::font;
        } else {
            currentActiveFont = nullptr;
        }
        ImGui::Text(nullptr, &TextUI::text);
    }

    void TextUI::setText(std::string c) {
        text = c;
    }
} // TextUI