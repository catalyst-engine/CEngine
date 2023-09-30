
#ifndef CATALYST_ENGINE_TEXTUI_H
#define CATALYST_ENGINE_TEXTUI_H

#include "imgui.h"
#include "UIComponent.h"

namespace Catalyst::ui {
    class TextUI : public UIComponent {
    private:
        std::string text;
        ImFont *font = nullptr;
    protected:
        static ImFont *currentActiveFont;
    public:
        void setText(std::string c);
        void render() override;
    };
}
#endif //CATALYST_ENGINE_TEXTUI_H
