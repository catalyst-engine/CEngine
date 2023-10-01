#pragma once
#ifndef CATALYST_SECTIONVIEW_H
#define CATALYST_SECTIONVIEW_H


#include "imgui.h"
#include "AbstractView.h"

namespace Catalyst::ui {
    class SectionView : public AbstractView {
    private:
        std::string title;
        ImVec2 size = ImVec2(10, 10);
    public:
        void setSize(float x, float y) {
            size.x = x;
            size.y = y;
        }

        void render() override;

        void load(pugi::xml_node node) override;
    };
}

#endif //CATALYST_SECTIONVIEW_H
