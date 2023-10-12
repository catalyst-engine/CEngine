#pragma once
#ifndef CATALYST_ENGINE_DOCUMENT_H
#define CATALYST_ENGINE_DOCUMENT_H

#include "../../util/structures/List.h"
#include "../../util/debug/ILoggable.h"
#include <string>

namespace Catalyst::ui {
    class IElement;

    class AbstractController;

    class Document : public Catalyst::ILoggable {
    private:
        Catalyst::util::List<IElement> views;
        Catalyst::util::List<AbstractController> controllers;

        IElement *searchFor(Catalyst::util::ListItem<IElement> *item, const std::string &id);

        size_t elementsSize = 0;

        void bindElement(IElement *component, IElement *parent);

    public:
        explicit Document() : Catalyst::ILoggable("Document") {}

        IElement *getElementById(std::string id);

        void render();

        void update();

        size_t quantityOfElements() const;

        Catalyst::util::List<IElement> getElements();

        template<class T>
        T *addElement(std::string id, IElement *parent) {
            IElement *found = getElementById(id);
            if (found != nullptr) {
                return (T *) found;
            }
            T *component = new T;
            component->setId(id);
            bindElement(component, parent);
            return component;
        }

        bool addElement(std::string id, IElement *component, IElement *parent);

    };

}

#endif
