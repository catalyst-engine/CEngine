#include "Document.h"
#include "../elements/IElement.h"
#include "../elements/EText.h"
#include "../elements/ESection.h"
#include "../../util/structures/Map.cpp"

namespace Catalyst {
    bool Document::isReady = false;
    Catalyst::Map<std::string, IElement *> Document::registeredElements;

    void Document::init() {
        if (isReady) {
            return;
        }
        isReady = true;
        registeredElements.set("EText", new EText);
        registeredElements.set("ESection", new ESection);
    }


    IElement *Document::addElementInternal(const char *tag, IElement *parent) {
        auto element = elementsState.add(createElement(tag), parent);
        if (element == nullptr) {
            return nullptr;
        }
        element->setDocument(this);
        return element;
    }

    IElement *Document::addElement(const char *tag) {
        return addElementInternal(tag, nullptr);
    }

    IElement *Document::addElement(const char *tag, std::string id, IElement *parent) {
        IElement *pElement = addElementInternal(tag, parent);
        if(pElement != nullptr) {
            pElement->setId(id);
        }
        return pElement;
    }

    IElement *Document::addElement(const char *tag, IElement *parent) {
        return addElementInternal(tag, parent);
    }

    ElementsState *Document::getElementsState() {
        return &elementsState;
    }

    IElement *Document::createElement(const char *tag) {
        if (!registeredElements.has(tag)) {
            return nullptr;
        }
        IElement *existing = registeredElements.get(tag);
        return existing->copy();
    }

    void Document::loadView(std::string &src) {
        CONSOLE_LOG("LOADING XML {0}", src)
        pugi::xml_document doc;
        pugi::xml_parse_result result = doc.load_file(src.c_str());
        if (!result) {
            CONSOLE_ERROR("XML NOT FOUND")
            return;
        }
        pugi::xml_node root = doc.root();
        for (pugi::xml_node node: root.children()) {
            loadElements(node, nullptr);
        }
    }

    void Document::loadElements(pugi::xml_node root, IElement *parent) {
        CONSOLE_LOG("LOADING ROOT {0}", root.name())
        for (pugi::xml_node node: root.children()) {
            const char *tagName = node.name();
            CONSOLE_LOG("PROCESSING NODE {0}", tagName)
            const char *idAttr = node.attribute("id").as_string();
            IElement *pView;
            if (strlen(idAttr) == 0) {
                pView = addElement(tagName, parent);
            } else {
                pView = addElement(tagName, idAttr, parent);
            }
            if (pView != nullptr) {
                pView->collectAttributes(node);
                loadElements(node, pView);
            }
        }
    }

    ViewsState *Document::getViewsState() {
        return &viewsState;
    }

    void Document::replace(std::string &str, const std::string &from, const std::string &to) {
        size_t start_pos = str.find(from);
        if (start_pos == std::string::npos) {
            return;
        }
        str.replace(start_pos, from.length(), to);
    }

    void Document::addViewInternal(IView *view) {
        viewsState.getViews()->push(view);
        std::string name = typeid(*view).name();
        name = name + ".xml";
        replace(name, "class ", "");
        replace(name, "Catalyst::", "");
        loadView(name);
    }
}