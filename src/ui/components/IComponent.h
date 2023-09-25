
#ifndef CATALYST_ENGINE_ICOMPONENT_H
#define CATALYST_ENGINE_ICOMPONENT_H

#include <string>

class IComponent {
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

    virtual void addChild(IComponent *child){}

};

#endif //CATALYST_ENGINE_ICOMPONENT_H
