#pragma once
#ifndef CATALYST_ESECTION_H
#define CATALYST_ESECTION_H


#include "imgui.h"
#include "IElement.h"

namespace Catalyst {
    class ESection : public IElement {
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
        IElement * copy() override;
    };
}

#endif //CATALYST_ESECTION_H
