#ifndef CATALYST_ABSTRACTTITLEDELEMENT_H
#define CATALYST_ABSTRACTTITLEDELEMENT_H

#include "IElement.h"

namespace Catalyst {

    class AbstractTitledElement : public IElement {
    protected:
        std::string title;
    public:
        std::string getTitle();

        void setTitle(std::string t);

        void collectAttributes(pugi::xml_node node) override;
    };

}

#endif
