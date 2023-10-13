#include "ElementFactory.h"
#include <string>
#include "../elements/IElement.h"
#include "../elements/EText.h"
#include "../elements/ESection.h"
#include "../../util/structures/Map.cpp"
#include "../../util/UUID.h"

namespace Catalyst {
    bool ElementFactory::isReady = false;
    Catalyst::Map<std::string, IElement *> ElementFactory::registered;

    IElement *ElementFactory::createElement(const char *tag) {
        if (!registered.has(tag)) {
            return nullptr;
        }
        IElement *existing = registered.get(tag);
        return existing->copy();
    }

    void ElementFactory::init() {
        if (isReady) {
            return;
        }
        isReady = true;
        registered.set("EText", new EText);
        registered.set("ESection", new ESection);
    }


    void ElementFactory::create(const char *src) {
        init();
        CONSOLE_LOG("LOADING XML {0}", src)
        pugi::xml_document doc;
        pugi::xml_parse_result result = doc.load_file(src);
        if (!result) {
            CONSOLE_ERROR("XML NOT FOUND")
            return;
        }
        pugi::xml_node root = doc.root();
        for (pugi::xml_node node: root.children()) {
            load(node, nullptr);
        }
    }

    void ElementFactory::prepare(pugi::xml_node node, IElement *parent) {

        const char *tagName = node.name();
        CONSOLE_LOG("PROCESSING NODE {0}", tagName)
        const char *idAttr = node.attribute("id").as_string();
        IElement *pView = nullptr;
        if (strlen(idAttr) == 0) {
            pView = addElement(tagName, parent);
        } else {
            pView = addElement(tagName, idAttr, parent);
        }
        if (pView != nullptr) {
            pView->collectAttributes(node);
            load(node, pView);
        }
    }

    void ElementFactory::load(pugi::xml_node root, IElement *parent) {
        CONSOLE_LOG("LOADING ROOT {0}", root.name())

        for (pugi::xml_node node: root.children()) {
            prepare(node, parent);
        }
    }

    IElement *ElementFactory::addElement(const char *tag, std::string id, IElement *parent) {
        return nullptr;
    }

    IElement *ElementFactory::addElement(const char *tag, IElement *parent) {
        return nullptr;
    }
}