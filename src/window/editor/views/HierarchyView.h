#ifndef CATALYST_HIERARCHYVIEW_H
#define CATALYST_HIERARCHYVIEW_H

#include "../../../ui/views/IView.h"

namespace Catalyst {
    class EMenuItem;

    class EButton;

    class ETree;

    class HierarchyView : public IView {
    private:
        EMenuItem *selectInvert = nullptr;
        EMenuItem *selectHierarchy = nullptr;
        EMenuItem *selectAll = nullptr;
        EButton *deleteButton = nullptr;
        ETree *tree = nullptr;
        EMenuItem *addEmpty = nullptr;
    public:
        void onInitialize() override;
    };

}

#endif
