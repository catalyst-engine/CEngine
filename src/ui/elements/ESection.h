#pragma once
#ifndef CATALYST_ESECTION_H
#define CATALYST_ESECTION_H


#include "imgui.h"
#include "IElement.h"
#include "AbstractTitledElement.h"

namespace Catalyst {
    class ESection : public AbstractTitledElement {
    private:
        ImVec2 size = ImVec2(10, 10);
    public:
        void setSize(float x, float y) {
            size.x = x;
            size.y = y;
        }

        void render() override;

        IElement * copy() override;
    };
}

#endif //CATALYST_ESECTION_H
