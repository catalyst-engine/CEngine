#include "HierarchyView.h"
#include "../../ui/core/Document.h"
#include "../../../ui/elements/EButton.h"
#include "../../../ui/elements/EMenuItem.h"
#include "../../../engine/Engine.h"
#include "../../../engine/world/WorldRegistry.h"
#include "../../../engine/world/World.h"
#include "../../../engine/components/CMetadata.h"
#include "../../../ui/elements/EText.h"
#include "../../../ui/elements/DynamicElement.h"

namespace Catalyst {
    void HierarchyView::onInitialize() {
        entityName = (EText *) getElementById("EntityName");
        deleteButton = (EButton *) getElementById("hierarchyDeleteButton");
        selectAll = (EMenuItem *) getElementById("hierarchySelectAll");
        selectHierarchy = (EMenuItem *) getElementById("hierarchySelectHierarchy");
        selectInvert = (EMenuItem *) getElementById("hierarchySelectInvert");
        addEmpty = (EMenuItem *) getElementById("hierarchyAddEmpty");
        auto section = (ESection *) getElementById("hierarchyContainer");

        auto *injectableElement = new DynamicElement(this, [](IElement *e) {
            auto *element = (HierarchyView *) e;
            if (element->addEmpty->isClicked()) {
                Engine::getWorld()->addEntity();
                element->addEmpty->setClicked(false);
            }
            engine::WorldRegistry *pRegistry = Engine::getRegistry();
            entt::registry *pBasicRegistry = pRegistry->getRegistry();

            element->entityName->setActive(true);
            for (auto entity: pBasicRegistry->view<engine::CMetadata>()) {
                auto &component = pBasicRegistry->get<engine::CMetadata>(entity);
                element->entityName->setText(component.getName());
                element->entityName->render();
            }
            element->entityName->setActive(false);
        });
        document->addElement((IElement *) injectableElement, (IElement *) section);
    }

    void HierarchyView::render() {
        renderChildren();
    }

    IElement *HierarchyView::copy() {
        return new HierarchyView;
    }
}