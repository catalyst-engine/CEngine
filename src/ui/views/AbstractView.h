#pragma once
#ifndef CATALYST_ENGINE_UICOMPONENT_H
#define CATALYST_ENGINE_UICOMPONENT_H

#include "IView.h"

namespace Catalyst::ui {
    class AbstractView : public IView {
    private:
        Catalyst::util::List<IView> children;
        std::string id;
    public:
        /**
        * Updates component state by executing controller
        */
        void update() override;

        /**
        * Renders component with state
        */
        void render() override;

        void setId(std::string &newId) override;

        std::string getId() override;

        Catalyst::util::List<IView> *getChildren() override;

    protected:
        void renderChildren();
    };
}
#endif //CATALYST_ENGINE_UICOMPONENT_H
