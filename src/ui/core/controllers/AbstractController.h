#pragma once
#ifndef CATALYST_ABSTRACTCONTROLLER_H
#define CATALYST_ABSTRACTCONTROLLER_H


namespace Catalyst::ui {
    class IView;

    class AbstractController {
    protected:
        IView *view = nullptr;
    public:
        void bindView(IView *pView);

        IView *getBoundView();

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
