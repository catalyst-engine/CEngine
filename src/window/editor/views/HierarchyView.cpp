#include "HierarchyView.h"
#include "../../ui/document/Document.h"
#include "../../../ui/elements/EButton.h"
#include "../../../ui/elements/EMenuItem.h"
#include "../../../engine/Engine.h"
#include "../../../engine/world/WorldRegistry.h"
#include "../../../engine/world/World.h"
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
        addEmpty = (EMenuItem *) getElementById("hierarchyAddEmpty");
        hierarchyContainer = getElementById("hierarchyContainer");
        EventController::get()->addListener("click", this);
        hierarchyList = document->addElement(new HierarchyList, hierarchyContainer);
    }

    IElement *HierarchyView::copy() {
        return new HierarchyView;
    }

    void HierarchyView::onEvent(Catalyst::IEventPayload *payload) {
        Engine::getWorld()->addEntity();
    }
}