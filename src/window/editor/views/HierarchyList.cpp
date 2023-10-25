#include "HierarchyList.h"
#include "../../../engine/Engine.h"
#include "../../../engine/world/WorldRegistry.h"
#include "../../../engine/world/World.h"
#include "../../../ui/elements/EText.h"
#include "../../../ui/document/Document.h"
#include "../../../engine/components/CMetadata.h"
#include "../../../ui/elements/ETreeNode.h"
#include "../../../ui/elements/ETree.h"
#include "../../../ui/event/IEventPayload.h"
#include "../../../ui/event/EventController.h"

namespace Catalyst {
    void HierarchyList::onInitialize() {
        addEmpty = getElementById("hierarchyAddEmpty");
        tree = (ETree *) document->addElement("ETree", this);
        tree->setText("Hierarchy");
        EventController::get()->addListener("click", this);
    }

    void HierarchyList::onEvent(IEventPayload *payload) {
        if (payload->getTarget() == addEmpty) {
            entt::entity entity = Engine::getWorld()->addEntity();
            auto &component = Engine::getRegistry()->get<engine::CMetadata>(entity);
            auto *node = (ETreeNode *) document->addElement("ETreeNode", tree);

            // TODO - EVENT FOR ENTITY UPDATE
            node->setText(component.getName());
            node->setIsLeaf(true);
        }
    }
}