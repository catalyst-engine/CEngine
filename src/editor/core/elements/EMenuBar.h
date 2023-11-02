#ifndef CATALYST_EMENUBAR_H
#define CATALYST_EMENUBAR_H

#include "IElement.h"

namespace Catalyst {

    class EMenuBar : public IElement  {
    private:
        bool mainMenu = true;
    public:

        void render() override;

        void collectAttributes(pugi::xml_node node) override;

        IElement * copy() override;
    };

}

#endif
