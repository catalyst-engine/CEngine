#ifndef CATALYST_EMENUITEM_H
#define CATALYST_EMENUITEM_H

#include "IElement.h"
#include "AbstractTitledElement.h"

namespace Catalyst {

    class EMenuItem : public AbstractTitledElement {
    private:
        std::string shortcut;
        bool addSeparator = false;
        bool enabled = true;
        bool checked = false;
    public:

        std::string getShortcut();

        void setShortcut(std::string t);

        void collectAttributes(pugi::xml_node node) override;

        void render() override;

        IElement * copy() override;


    };

}

#endif
