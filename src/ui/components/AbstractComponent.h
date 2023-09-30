
#ifndef CATALYST_ENGINE_ICOMPONENT_H
#define CATALYST_ENGINE_ICOMPONENT_H

#include <string>

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

        virtual void addChild(AbstractComponent *child) {}
    };
}
#endif //CATALYST_ENGINE_ICOMPONENT_H

