#ifndef CATALYST_HIERARCHYLIST_H
#define CATALYST_HIERARCHYLIST_H

#include "../../../ui/elements/IElement.h"

namespace Catalyst {
    class EText;

    class HierarchyList : public IElement {
    private:
        EText *entityName = nullptr;
    public:
        void onInitialize() override;

        void render() override;
    };

}

#endif
