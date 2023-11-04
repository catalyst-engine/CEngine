#include "HierarchyList.h"
#include "../../../../../engine/Engine.h"
#include "../../../../../engine/world/WorldController.h"
#include "../../../../core/elements/EText.h"
#include "../../../../core/document/Document.h"
#include "../../../../../engine/components/CMetadata.h"
#include "../../../../../engine/event/IEventPayload.h"
#include "../../../../core/elements/ETreeNode.h"
#include "../../../../core/elements/ETree.h"
#include "stores/SelectionStore.h"

namespace Catalyst {
    void HierarchyList::onInitialize() {
        addEmpty = getElementById("hierarchyAddEmpty");
        tree = (ETree *) document->addElement("ETree", this);
        tree->setText("Hierarchy");
        EventController::get()->addListener("click", this);
        EventController::get()->addListener(SelectionStore::getStoreId(), this);

    }

    void HierarchyList::onEvent(IEventPayload *payload) {
        if (payload->getEventType() == SelectionStore::getStoreId()) {
            const std::string &selectedEntity = SelectionStore::getData()->getSelectedEntity();
            auto *treeNode = (ETreeNode *) getChildElementById(selectedEntity);
            auto *treeNodeLast = (ETreeNode *) getChildElementById(previouslySelected);

            if (treeNodeLast != nullptr) {
                treeNodeLast->setSelected(false);
            }

            if (treeNode != nullptr) {
                treeNode->setSelected(true);
            }

            previouslySelected = selectedEntity;
        } else if (payload->getEventType() == "click") {
            auto *pElement = (IElement *) payload->getTarget();
            if (pElement == addEmpty) {
                entt::entity entity = Engine::getWorld()->addEntity();
                auto &component = Engine::getRegistry()->get<engine::CMetadata>(entity);
                auto *node = (ETreeNode *) document->addElement("ETreeNode", tree);

                // TODO - EVENT FOR ENTITY UPDATE
                node->setText(component.getName());
                node->setIsLeaf(true);
                node->setId(component.getEntityUUID());
            } else if (pElement != nullptr && pElement->getParent() == tree) {
                SelectionState *state = SelectionStore::getData();
                state->setSelectedEntity(pElement->getId());
                SelectionStore::updateData(state);
            }
        }
    }
}