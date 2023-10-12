#pragma once
#ifndef CATALYST_SECTIONVIEW_H
#define CATALYST_SECTIONVIEW_H


#include "imgui.h"
#include "IView.h"

namespace Catalyst::ui {
    class SectionView : public IView {
    private:
        std::string title;
        ImVec2 size = ImVec2(10, 10);
    public:
        void setSize(float x, float y) {
            size.x = x;
            size.y = y;
        }

        void render() override;

        void collectAttributes(pugi::xml_node node) override;
        IView * copy() override;
    };
}

#endif //CATALYST_SECTIONVIEW_H
