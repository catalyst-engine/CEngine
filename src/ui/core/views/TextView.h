#pragma once
#ifndef CATALYST_TEXTVIEW_H
#define CATALYST_TEXTVIEW_H

#include <string>
#include "AbstractView.h"

namespace Catalyst::ui {
    class TextView : public AbstractView {
        std::string text;
    public:
        void setText(std::string textV);
        void render() override;
        void load(pugi::xml_node node) override;

    };
}

#endif //CATALYST_TEXTVIEW_H
