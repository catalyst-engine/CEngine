
#ifndef CATALYST_ENGINE_UICOMPONENT_H
#define CATALYST_ENGINE_UICOMPONENT_H

#include "../../../util/structures/List.h"
#include "../../../util/structures/DynamicMap.h"
#include "AbstractComponent.h"

namespace Catalyst::ui {
    class Component : public AbstractComponent {
    private:
        Catalyst::util::List<AbstractComponent> children;
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

        Catalyst::util::List<AbstractComponent> *getChildren() override;
    protected:
        void renderChildren();
    };
}
#endif //CATALYST_ENGINE_UICOMPONENT_H
