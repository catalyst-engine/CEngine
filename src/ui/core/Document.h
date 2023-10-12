#pragma once
#ifndef CATALYST_ENGINE_DOCUMENT_H
#define CATALYST_ENGINE_DOCUMENT_H

#include "../../util/structures/List.h"
#include "../../util/debug/ILoggable.h"
#include <string>

namespace Catalyst::ui {
    class IView;

    class AbstractController;

    class Document : public Catalyst::ILoggable {
    private:
        Catalyst::util::List<IView> views;
        Catalyst::util::List<AbstractController> controllers;

        IView *searchFor(Catalyst::util::ListItem<IView> *item, const std::string &id);

        size_t elementsSize = 0;

        void bindElement(IView *component, IView *parent);

    public:
        explicit Document() : Catalyst::ILoggable("Document") {}

        IView *getElementById(std::string id);

        void render();

        void update();

        size_t quantityOfElements() const;

        Catalyst::util::List<IView> getElements();

        template<class T>
        T *addElement(std::string id, IView *parent) {
            IView *found = getElementById(id);
            if (found != nullptr) {
                return (T *) found;
            }
            T *component = new T;
            component->setId(id);
            bindElement(component, parent);
            return component;
        }

        bool addElement(std::string id, IView *component, IView *parent);

    };

}

#endif
