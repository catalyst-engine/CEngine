#include "HierarchyView.h"
#include "../../ui/core/Document.h"
#include "../../../ui/elements/ETree.h"
#include "../../../ui/elements/EButton.h"
#include "../../../ui/elements/EMenuItem.h"

namespace Catalyst {
    void HierarchyView::onInitialize() {
        tree = (ETree *) getElementById("hierarchyTree");
        deleteButton = (EButton *) getElementById("hierarchyDeleteButton");
        selectAll = (EMenuItem *) getElementById("hierarchySelectAll");
        selectHierarchy = (EMenuItem *) getElementById("hierarchySelectHierarchy");
        selectInvert = (EMenuItem *) getElementById("hierarchySelectInvert");
        addEmpty = (EMenuItem *) getElementById("hierarchyAddEmpty");
    }
}