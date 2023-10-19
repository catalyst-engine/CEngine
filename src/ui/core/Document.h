#pragma once
#ifndef CATALYST_ENGINE_DOCUMENT_H
#define CATALYST_ENGINE_DOCUMENT_H

#include "../../util/structures/List.h"
#include "ElementsState.h"
#include "pugixml.hpp"
#include "ViewsState.h"
#include <string>

namespace Catalyst {
    template<typename K, typename V>
    class Map;

    class IElement;

    class IView;

    class Document : public ILoggable {
    private:
        ElementsState elementsState;
        ViewsState viewsState;

        IElement *addElementInternal(IElement *element);

        void loadElements(pugi::xml_node root, IElement *parent);

        void loadView(std::string &src, IView *parent);

        IView *addViewInternal(const char *tag, IElement *parent);

    public:


        IElement *addElement(const char *tag, const char *id, IElement *parent);

        IElement *addElement(const char *tag, IElement *parent);

        IElement *addElement(IElement *element, IElement *parent);

        IElement *addElement(const char *tag);

        IElement *getElementById(std::string id, IElement *root);

        IElement *getElementById(std::string id);

        List<IView> *getViews();

        List<IElement> *getElements();

        /**
         * Register view instance
         * @param tag
         * @param instance
         */
        static void registerView(const char *tag, IView *instance);

        IView *addView(const char *tag, IElement *parent);

        IView *addView(const char *tag);
    };
}

#endif
