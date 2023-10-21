#include "Document.h"

#include <utility>
#include "../elements/ETree.h"

#include "../elements/ESection.h"
#include "../../util/structures/Map.cpp"
#include "../../util/StringUtils.h"
#include "../../ui/views/IView.h"

namespace Catalyst {

    void Document::registerView(const char *tag, IView *instance) {
        ViewController::registeredViews.set(tag, instance);
    }

    IElement *Document::addElementInternal(IElement *element) {
        if (element) element->setDocument(this);
        return element;
    }

    IElement *Document::addElement(const char *tag) {
        return addElementInternal(elementController.addElement(tag));
    }

    IElement *Document::addElement(const char *tag, const char *id, IElement *parent) {
        return addElementInternal(elementController.addElement(tag, id, parent));
    }

    IElement *Document::addElement(IElement *element, IElement *parent) {
        return addElementInternal(elementController.addElement(element, parent));
    }

    IElement *Document::addElement(const char *tag, IElement *parent) {
        return addElementInternal(elementController.addElement(tag, parent));
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
            if (ViewController::registeredViews.has(tagName)) {
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
        return elementController.getElementById(std::move(id), root);
    }

    IElement *Document::getElementById(std::string id) {
        return elementController.getElementById(std::move(id));
    }

    List<IView> *Document::getViews() {
        return viewController.getViews();
    }

    List<IElement> *Document::getElements() {
        return elementController.getElements();
    }

    IView *Document::addViewInternal(const char *tag, IElement *parent) {
        IView *view = viewController.addView(tag);
        if (view) {
            std::string name = typeid(*view).name();
            name = name + ".xml";
            StringUtils::replace(name, "class ", "");
            StringUtils::replace(name, "Catalyst::", "");
            loadView(name, view);
            addElement(view, parent);
            initializeElement(view);
        }
        return view;
    }

    void Document::initializeElement(IElement *element) {
        element->onInitialize();
        List<IElement> *children = element->getChildren();
        children->iterate();
        while (children->hasNext()) {
            IElement *pElement = children->next();
            initializeElement(pElement);
        }
    }

    IView *Document::addView(const char *tag, IElement *parent) {
        return addViewInternal(tag, parent);
    }

    IView *Document::addView(const char *tag) {
        return addViewInternal(tag, nullptr);
    }

    Document::Document(ImGuiIO *pIo) {
        ioController.setIo(pIo);
    }
}