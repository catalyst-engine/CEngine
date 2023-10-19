#include "Document.h"

#include <utility>
#include "../elements/ETree.h"

#include "../elements/ESection.h"
#include "../../util/structures/Map.cpp"
#include "../../util/StringUtils.h"
#include "../../ui/views/IView.h"

namespace Catalyst {

    void Document::registerView(const char *tag, IView *instance) {
        ViewsState::registeredViews.set(tag, instance);
    }

    IElement *Document::addElementInternal(IElement *element) {
        if (element) element->setDocument(this);
        return element;
    }

    IElement *Document::addElement(const char *tag) {
        return addElementInternal(elementsState.addElement(tag));
    }

    IElement *Document::addElement(const char *tag, const char *id, IElement *parent) {
        return addElementInternal(elementsState.addElement(tag, id, parent));
    }

    IElement *Document::addElement(IElement *element, IElement *parent) {
        return addElementInternal(elementsState.addElement(element, parent));
    }

    IElement *Document::addElement(const char *tag, IElement *parent) {
        return addElementInternal(elementsState.addElement(tag, parent));
    }


    void Document::loadView(std::string &src, IView *parent) {
        CONSOLE_WARN("LOADING XML {0}", src)
        pugi::xml_document doc;
        pugi::xml_parse_result result = doc.load_file(src.c_str());
        if (!result) {
            CONSOLE_ERROR("XML NOT FOUND")
            return;
        }
        pugi::xml_node root = doc.root();
        for (pugi::xml_node node: root.children()) {
            loadElements(node, parent);
        }
    }

    void Document::loadElements(pugi::xml_node root, IElement *parent) {
        for (pugi::xml_node node: root.children()) {
            const char *tagName = node.name();
            CONSOLE_WARN("Parsing {0}", tagName)
            const char *idAttr = node.attribute("id").as_string();
            IElement *element;
            if (ViewsState::registeredViews.has(tagName)) {
                addViewInternal(tagName, parent);
                continue;
            }

            if (strlen(idAttr) == 0) {
                element = addElement(tagName, parent);
            } else {
                element = addElement(tagName, idAttr, parent);
            }
            if (element != nullptr) {
                element->collectAttributes(node);
                loadElements(node, element);
            }
        }
    }

    IElement *Document::getElementById(std::string id, IElement *root) {
        return elementsState.getElementById(std::move(id), root);
    }

    IElement *Document::getElementById(std::string id) {
        return elementsState.getElementById(std::move(id));
    }

    List<IView> *Document::getViews() {
        return viewsState.getViews();
    }

    List<IElement> *Document::getElements() {
        return elementsState.getElements();
    }

    IView *Document::addViewInternal(const char *tag, IElement *parent) {
        IView *view = viewsState.addView(tag);
        if (view) {
            std::string name = typeid(*view).name();
            name = name + ".xml";
            StringUtils::replace(name, "class ", "");
            StringUtils::replace(name, "Catalyst::", "");
            loadView(name, view);
            addElement(view, parent);
        }
        return view;
    }

    IView *Document::addView(const char *tag, IElement *parent) {
        return addViewInternal(tag, parent);
    }

    IView *Document::addView(const char *tag) {
        return addViewInternal(tag, nullptr);
    }
}