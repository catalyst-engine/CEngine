#pragma once
#ifndef CATALYST_ABSTRACTCONTROLLER_H
#define CATALYST_ABSTRACTCONTROLLER_H


namespace Catalyst::ui {
    class IElement;

    class AbstractController {
    protected:
        IElement *view = nullptr;
    public:
        void bindView(IElement *pView);

        IElement *getBoundView();

        bool isValid();

        /**
         * Runs every frame to update component
         * */
        virtual void update() {

        }

        virtual AbstractController *copy() { return nullptr; }
    };
}
#endif
