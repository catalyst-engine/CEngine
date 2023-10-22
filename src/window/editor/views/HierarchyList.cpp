#include "HierarchyList.h"
#include "../../../engine/Engine.h"
#include "../../../engine/world/WorldRegistry.h"
#include "../../../engine/world/World.h"
#include "../../../ui/elements/EText.h"
#include "../../../ui/document/Document.h"
#include "../../../engine/components/CMetadata.h"

namespace Catalyst {
    void HierarchyList::render() {
        engine::WorldRegistry *pRegistry = Engine::getRegistry();
        entt::registry *pBasicRegistry = pRegistry->getRegistry();

        for (auto entity: pBasicRegistry->view<engine::CMetadata>()) {
            auto &component = pBasicRegistry->get<engine::CMetadata>(entity);
            entityName->setText(component.getName());
            block->render();
        }
    }

    void HierarchyList::onInitialize() {
        block = document->addElement("EInlineBlock", this);
        entityName = (EText *) document->addElement("EText", block);
    }
}