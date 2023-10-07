#include "DocumentBuilder.h"

#include "views/IView.h"
#include "controllers/AbstractController.h"
#include "Document.h"
#include "ViewFactory.h"
#include "ControllerFactory.h"

using namespace std;
namespace Catalyst::ui {
    bool DocumentBuilder::loadFromXML(const char *xmlFileName) {
        CONSOLE_LOG("LOADING XML {0}", xmlFileName)

        pugi::xml_document doc;
        pugi::xml_parse_result result = doc.load_file(xmlFileName);
        if (!result) {
            CONSOLE_ERROR("XML NOT FOUND")
            return false;
        }
        pugi::xml_node root = doc.root();
        for (pugi::xml_node node: root.children()) {
            loadIntoDocument(node, nullptr);
        }

        return true;
    }

    void DocumentBuilder::loadIntoDocument(pugi::xml_node root, IView *parent) {
        CONSOLE_LOG("LOADING ROOT {0}", root.name())

        for (pugi::xml_node node: root.children()) {
            processNode(node, parent);
        }
    }

    void DocumentBuilder::processNode(pugi::xml_node node, IView *parent) {
        const char *tagName = node.name();
        CONSOLE_LOG("PROCESSING NODE {0}", tagName)

        const char *idAttr = node.attribute("id").as_string();
        const char *controllerAttr = node.attribute("controller").as_string();
        IView *pView = Catalyst::ui::ViewFactory::getViewByTag(tagName);
        AbstractController *pController = nullptr;
        if (controllerAttr != nullptr) {
            pController = Catalyst::ui::ControllerFactory::getControllerByAttr(controllerAttr);
        }
        if (pView != nullptr) {
            bool success = document->addElement(idAttr, pView, parent);
            if (pController != nullptr) {
                pView->setController(pController);
            }
            if (!success) {
                CONSOLE_ERROR("View with same ID already declared", idAttr)
            }
            pView->load(node);
            loadIntoDocument(node, pView);
        }
    }

}