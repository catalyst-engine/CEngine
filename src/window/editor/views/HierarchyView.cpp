#include "HierarchyView.h"
#include "../../ui/document/Document.h"
#include "../../../ui/elements/EButton.h"
#include "../../../ui/elements/EMenuItem.h"
#include "../../../ui/elements/EText.h"
#include "../../../ui/event/EventController.h"
#include "HierarchyList.h"

namespace Catalyst {
    void HierarchyView::onInitialize() {
        CONSOLE_LOG("Initializing hierarchy")
        deleteButton = (EButton *) getElementById("hierarchyDeleteButton");
        selectAll = (EMenuItem *) getElementById("hierarchySelectAll");
        selectHierarchy = (EMenuItem *) getElementById("hierarchySelectHierarchy");
        selectInvert = (EMenuItem *) getElementById("hierarchySelectInvert");
        hierarchyContainer = getElementById("hierarchyContainer");
        hierarchyList = document->addElement(new HierarchyList, hierarchyContainer);
    }

    IElement *HierarchyView::copy() {
        return new HierarchyView;
    }

}