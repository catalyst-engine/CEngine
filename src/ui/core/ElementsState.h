#ifndef CATALYST_ELEMENTSSTATE_H
#define CATALYST_ELEMENTSSTATE_H

#include "../../util/structures/List.h"
#include "../../util/debug/ILoggable.h"
#include <string>

namespace Catalyst {
    class IElement;

    template<typename K, typename V>
    class Map;

    class ElementsState : public ILoggable {
    private:

        Catalyst::List<IElement> elements;

        IElement *searchFor(Catalyst::ListItem<IElement> *item, const std::string &id);

        IElement *getElementByIdInternal(std::string &id, ListItem<IElement> *root);

        IElement *addElementInternal(IElement *element, IElement *parent);

        IElement *createElement(const char *tag);

    public:

        explicit ElementsState();

        static Map<std::string, IElement *> registeredElements;

        IElement *add(IElement *element, IElement *parent);

        IElement *getElementById(std::string id);

        IElement *getElementById(std::string id, IElement *root);

        Catalyst::List<IElement> *getElements();

        IElement *addElement(const char *tag);

        IElement *addElement(const char *tag, std::string id, IElement *parent);

        IElement *addElement(IElement *element, IElement *parent);

        IElement *addElement(const char *tag, IElement *parent);
    };
}

#endif
