#pragma once
#ifndef CATALYST_TEXTVIEW_H
#define CATALYST_TEXTVIEW_H

#include <string>
#include "IView.h"

namespace Catalyst::ui {
    class TextView : public IView {
        std::string text;
    public:
        void setText(std::string textV);
        void render() override;
        void collectAttributes(pugi::xml_node node) override;
        IView * copy() override;
    };
}

#endif //CATALYST_TEXTVIEW_H
