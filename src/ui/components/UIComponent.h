
#ifndef CATALYST_ENGINE_UICOMPONENT_H
#define CATALYST_ENGINE_UICOMPONENT_H

#include "../../util/DoubleLinkedList.h"
#include "../../util/DynamicMap.h"
#include "IComponent.h"

class UIComponent : public IComponent{
private:
    DynamicMap<std::string, IComponent> children;
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

    Util::Basic::DoubleLinkedList<IComponent> *getChildren();

    void addChild(IComponent *child) override;
protected:
    void renderChildren();
};


#endif //CATALYST_ENGINE_UICOMPONENT_H
