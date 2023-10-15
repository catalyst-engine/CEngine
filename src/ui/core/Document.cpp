#include "Document.h"
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

    void Document::init() {
        if (isReady) {
            return;
        }
        isReady = true;
        registeredElements.set("EText", new EText);
        registeredElements.set("ESection", new ESection);
        registeredElements.set("ETree", new ETree);
        registeredElements.set("EButton", new EButton);
        registeredElements.set("EMenu", new EMenu);
        registeredElements.set("EMenuBar", new EMenuBar);
        registeredElements.set("EMenuItem", new EMenuItem);
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
                CONSOLE_LOG("\tAttributes found for {0}:", tagName)
                for (auto e: node.attributes()) {
                    CONSOLE_LOG("\t\t{0}:{1}", e.name(), e.as_string())
                }
                pView->collectAttributes(node);
                loadElements(node, pView);
            }
        }
    }

    ViewsState *Document::getViewsState() {
        return &viewsState;
    }


    void Document::addViewInternal(IView *view, IView *parent) {
        viewsState.getViews()->push(view);
        std::string name = typeid(*view).name();
        name = name + ".xml";
        StringUtils::replace(name, "class ", "");
        StringUtils::replace(name, "Catalyst::", "");
        loadView(name, view);

        elementsState.add(view, parent);
        view->setDocument(this);

        view->onInitialize();
    }

    IElement *Document::addElement(IElement *element, IElement *parent) {
        return addElementInternal(element, parent);
    }
}