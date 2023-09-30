
#ifndef CATALYST_ENGINE_ICOMPONENT_H
#define CATALYST_ENGINE_ICOMPONENT_H

#include <string>
#include "../../../util/structures/List.h"

namespace Catalyst::ui {
    class AbstractComponent {
    public:
        /**
         * Updates component state
         */
        virtual void update() {}

        /**
         * Renders component with state
         */
        virtual void render() {}

        virtual void setId(std::string &newId) {}

        virtual std::string getId() {
            return "";
        }

        virtual Catalyst::util::List<AbstractComponent> *getChildren() {
            return nullptr;
        }
    };
}
#endif //CATALYST_ENGINE_ICOMPONENT_H
