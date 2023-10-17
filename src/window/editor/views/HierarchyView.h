#ifndef CATALYST_HIERARCHYVIEW_H
#define CATALYST_HIERARCHYVIEW_H

#include "../../../ui/views/IView.h"

namespace Catalyst {
    class EMenuItem;

    class EButton;

    class ETree;

    class EText;

    class ESection;

    class HierarchyView : public IView {
    protected:
        EMenuItem *selectInvert = nullptr;
        EMenuItem *selectHierarchy = nullptr;
        EMenuItem *selectAll = nullptr;
        EButton *deleteButton = nullptr;
        EText *entityName;
        EMenuItem *addEmpty = nullptr;
    public:
        void onInitialize() override;

        void render() override;

        IElement * copy() override;
    };

}

#endif
