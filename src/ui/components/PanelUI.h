
#ifndef CATALYST_ENGINE_PANELUI_H
#define CATALYST_ENGINE_PANELUI_H

#include "imgui.h"
#include "UIComponent.h"
namespace Catalyst::ui {
    class PanelUI : public UIComponent {
    public:
        void render() override;
    };
}

#endif //CATALYST_ENGINE_PANELUI_H
