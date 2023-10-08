#pragma once
#ifndef CATALYST_ENGINE_DOCUMENT_H
#define CATALYST_ENGINE_DOCUMENT_H

#include "../../../util/structures/List.h"
#include "debug/ILoggable.h"
#include <string>

namespace Catalyst::ui {
    class IView;

    class Document : public Catalyst::ILoggable {
    private:
        Catalyst::util::List<IView> roots;

        IView *searchFor(Catalyst::util::ListItem<IView> *item, const std::string &id);

        size_t elementsSize = 0;

        void bindElement(IView *component, IView *parent);

    public:
        explicit Document() : Catalyst::ILoggable("Document") {}

        void init();

        IView *getElementById(std::string id);

        void render();

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
