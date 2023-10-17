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
        static bool isReady;
        static Map<std::string, IView *> registeredViews;
        static Map<std::string, IElement *> registeredElements;
        ElementsState elementsState;
        ViewsState viewsState;


        IElement *addElementInternal(IElement *element, IElement *parent);

        void loadElements(pugi::xml_node root, IElement *parent);

        static void init();

        void loadView(std::string &src, IView *parent);

        void addViewInternal(IView *view, IElement *parent);

    public:

        explicit Document() {
            init();
        }

        static IElement *createElement(const char *tag);

        IElement *addElement(const char *tag, std::string id, IElement *parent);

        IElement *addElement(const char *tag, IElement *parent);

        IElement *addElement(IElement *element, IElement *parent);

        IElement *addElement(const char *tag);

        IElement *getElementById(std::string id, IElement *root);

        IElement *getElementById(std::string id);

        List<IView> *getViews();

        List<IElement> *getElements();

        /**
         * Class needs to be in the "Catalyst" namespace
         * @tparam T extends IView
         */
        template<class T>
        void addView() {
            addViewInternal(new T, nullptr);
        }


        /**
         * Class needs to be in the "Catalyst" namespace
         * @tparam T extends IView
         */
        template<class T>
        void addView(IView *parent) {
            addViewInternal(new T, parent);
        }

        /**
         * Register element instance
         * @param tag
         * @param instance
         */
        static void registerElement(const char *tag, IElement *instance);

        /**
         * Register view instance
         * @param tag
         * @param instance
         */
        static void registerView(const char *tag, IView *instance);
    };
}

#endif
