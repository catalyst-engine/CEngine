#include "DocumentBuilder.h"

#include "views/IView.h"
#include "views/TextView.h"
#include "controllers/AbstractController.h"
#include "Document.h"
#include "ViewFactory.h"
#include "ControllerFactory.h"
#include "../../DEFINITIONS.h"

using namespace std;
namespace Catalyst::ui {
    bool DocumentBuilder::loadFromXML(const char *xmlFileName, Catalyst::ui::Document *document) {
        pugi::xml_document doc;
        pugi::xml_parse_result result = doc.load_file(xmlFileName);
        if (!result)
            return false;
        pugi::xml_node root = doc.root();

        for (pugi::xml_node node: root.children()) {
            loadIntoDocument(document, node, nullptr);
        }

        return true;
    }

    void DocumentBuilder::loadIntoDocument(Document *document, pugi::xml_node root, IView *parent) {
        for (pugi::xml_node node: root.children()) {
            processNode(node, document, parent);
        }
    }

    void DocumentBuilder::processNode(pugi::xml_node node, Document *document, IView *parent) {
        const char *tagName = node.name();
        std::cout << node.name() << std::endl;

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
                cout << "View with same ID already declared \n";
            }
            pView->load(node);
            loadIntoDocument(document, node, pView);
        }
    }

}