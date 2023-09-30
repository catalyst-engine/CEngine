
#ifndef CATALYST_ENGINE_UICOMPONENT_H
#define CATALYST_ENGINE_UICOMPONENT_H

#include "../../util/structures/List.h"
#include "../../util/structures/DynamicMap.h"
#include "IComponent.h"

namespace Catalyst::ui {
    class UIComponent : public IComponent {
    private:
        Catalyst::util::structs::DynamicMap<std::string, IComponent> children;
        std::string id;
    public:
        /**
         * Updates component state
         */
        void update() override;

        /**
         * Renders component with state
         */
        void render() override;

        void setId(std::string &newId) override;

        std::string getId() override;

        Catalyst::util::structs::List<IComponent> *getChildren();

        void addChild(IComponent *child) override;

    protected:
        void renderChildren();
    };
}

#endif //CATALYST_ENGINE_UICOMPONENT_H
