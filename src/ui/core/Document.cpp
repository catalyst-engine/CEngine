#include "Document.h"

#include <utility>
#include "../elements/ETree.h"
#include "../elements/EButton.h"
#include "../elements/EMenu.h"
#include "../elements/EMenuBar.h"
#include "../elements/EMenuItem.h"
#include "../elements/EText.h"
#include "../elements/ESection.h"
#include "../../util/structures/Map.cpp"
#include "../../util/StringUtils.h"

namespace Catalyst {
    bool Document::isReady = false;
    Catalyst::Map<std::string, IElement *> Document::registeredElements;
    Catalyst::Map<std::string, IView *> Document::registeredViews;

    void Document::init() {
        if (isReady) {
            return;
        }
        isReady = true;
        registerElement("EText", new EText);
        registerElement("ESection", new ESection);
        registerElement("ETree", new ETree);
        registerElement("EButton", new EButton);
        registerElement("EMenu", new EMenu);
        registerElement("EMenuBar", new EMenuBar);
        registerElement("EMenuItem", new EMenuItem);
    }

    void Document::registerElement(const char *tag, IElement *instance) {
        registeredElements.set(tag, instance);
    }

    void Document::registerView(const char *tag, IView *instance) {
        registeredViews.set(tag, instance);
    }

    IElement *Document::addElementInternal(IElement *element, IElement *parent) {
        auto pElement = elementsState.add(element, parent);
        if (pElement == nullptr) {
            return nullptr;
        }
        pElement->setDocument(this);
        return pElement;
    }

    IElement *Document::addElement(const char *tag) {
        return addElementInternal(createElement(tag), nullptr);
    }

    IElement *Document::addElement(const char *tag, std::string id, IElement *parent) {
        IElement *pElement = addElementInternal(createElement(tag), parent);
        if (pElement != nullptr) {
            pElement->setId(id);
        }
        return pElement;
    }

    IElement *Document::addElement(const char *tag, IElement *parent) {
        return addElementInternal(createElement(tag), parent);
    }

    IElement *Document::createElement(const char *tag) {
        if (!registeredElements.has(tag)) {
            return nullptr;
        }
        IElement *existing = registeredElements.get(tag);
        return existing->copy();
    }

    void Document::loadView(std::string &src, IView *parent) {
        CONSOLE_LOG("LOADING XML {0}", src)
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
            CONSOLE_LOG("Processing >>> {0}", tagName)
            const char *idAttr = node.attribute("id").as_string();
            IElement *element;
            if (registeredViews.has(tagName)) {
                CONSOLE_LOG(">>> Loading view")
                addViewInternal((IView *) registeredViews.get(tagName)->copy(), parent);
            } else {
                CONSOLE_LOG(">>> Loading element")
                if (strlen(idAttr) == 0) {
                    element = addElement(tagName, parent);
                } else {
                    element = addElement(tagName, idAttr, parent);
                }
                if (element != nullptr) {
                    CONSOLE_LOG("\tAttributes found for {0}:", tagName)
                    for (auto e: node.attributes()) {
                        CONSOLE_LOG("\t\t{0}:{1}", e.name(), e.as_string())
                    }
                    element->collectAttributes(node);
                    loadElements(node, element);
                }
            }
        }
    }

    void Document::addViewInternal(IView *view, IElement *parent) {
        viewsState.getViews()->push(view);
        std::string name = typeid(*view).name();
        name = name + ".xml";
        StringUtils::replace(name, "class ", "");
        StringUtils::replace(name, "Catalyst::", "");
        loadView(name, view);
        elementsState.add(view, parent);
        view->setDocument(this);
    }

    IElement *Document::addElement(IElement *element, IElement *parent) {
        return addElementInternal(element, parent);
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
}