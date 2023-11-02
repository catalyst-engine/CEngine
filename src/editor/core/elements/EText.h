#pragma once
#ifndef CATALYST_ETEXT_H
#define CATALYST_ETEXT_H

#include <string>
#include "AbstractSimpleElement.h"

namespace Catalyst {
    class EText : public AbstractSimpleElement  {
    public:
        void render() override;

        void collectAttributes(pugi::xml_node node) override;

        IElement *copy() override;
    };
}

#endif
