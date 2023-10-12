#pragma once
#ifndef CATALYST_ETEXT_H
#define CATALYST_ETEXT_H

#include <string>
#include "IElement.h"

namespace Catalyst::ui {
    class EText : public IElement {
        std::string text;
    public:
        void setText(std::string textV);
        void render() override;
        void collectAttributes(pugi::xml_node node) override;
        IElement * copy() override;
    };
}

#endif //CATALYST_ETEXT_H
