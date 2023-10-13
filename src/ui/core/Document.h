#pragma once
#ifndef CATALYST_ENGINE_DOCUMENT_H
#define CATALYST_ENGINE_DOCUMENT_H

#include "../../util/structures/List.h"
#include "ElementFactory.h"
#include <string>

namespace Catalyst {
    class IElement;

    class Document : public ElementFactory {
    private:
        Catalyst::List<IElement> elements;

        size_t elementsSize = 0;

        IElement *searchFor(Catalyst::ListItem<IElement> *item, const std::string &id);

        void bindElement(IElement *component, IElement *parent);

        IElement *addElementInternal(const char *tag, IElement *parent);

    public:

        IElement *getElementById(std::string id);

        size_t quantityOfElements() const;

        Catalyst::List<IElement> *getElements();

        IElement *addElement(const char *tag, std::string id, IElement *parent) override;

        IElement *addElement(const char *tag, IElement *parent) override;

        IElement *addElement(const char *tag);
    };
}

#endif
