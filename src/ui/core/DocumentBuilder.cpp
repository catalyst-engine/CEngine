#include "DocumentBuilder.h"

#include "views/AbstractView.h"
#include "controllers/AbstractController.h"
#include "Document.h"
#include "ViewFactory.h"
#include "ControllerFactory.h"

using namespace std;
using namespace xercesc;
namespace Catalyst::ui {
    bool DocumentBuilder::parseAndValidateXML(const char *xmlFileName, const char *xsdFileName,
                                              Catalyst::ui::Document *document) {

        try {
            XMLPlatformUtils::Initialize();
        } catch (const XMLException &toCatch) {
            char *message = XMLString::transcode(toCatch.getMessage());
            cout << "Error during initialization! :\n" << message << "\n";
            XMLString::release(&message);
            return false;
        }

        auto *parser = new XercesDOMParser();
        parser->setValidationScheme(XercesDOMParser::Val_Always);
        parser->setDoNamespaces(true);

        auto *errHandler = (ErrorHandler *)
                new HandlerBase();
        parser->setErrorHandler(errHandler);
        parser->setExternalNoNamespaceSchemaLocation(xsdFileName);

        try {
            parser->parse(xmlFileName);
        } catch (const XMLException &toCatch) {
            char *message = XMLString::transcode(toCatch.getMessage());
            cout << "Exception message is: \n" << message << "\n";
            XMLString::release(&message);
            return false;
        } catch (const DOMException &toCatch) {
            char *message = XMLString::transcode(toCatch.msg);
            cout << "Exception message is: \n" << message << "\n";
            XMLString::release(&message);
            return false;
        } catch (...) {
            cout << "Unexpected Exception \n";
            return false;
        }

        cout << xmlFileName << ": parse OK" << endl;

        if (document != nullptr) {
            loadIntoDocument(document, parser->getDocument());
        }

        delete parser;
        delete errHandler;
        return true;
    }

    void DocumentBuilder::loadIntoDocument(Document *document, xercesc_3_2::DOMDocument *dom) {
        DOMNode *body = dom->getElementsByTagName(XMLString::transcode("Body"))->item(0);
        DOMNodeList *nodeList = body->getChildNodes();

        for (XMLSize_t i = 0; i < nodeList->getLength(); i++) {
            auto *element = dynamic_cast<DOMElement *>(nodeList->item(i));
            if (element) {
                const XMLCh *idAttr = element->getAttribute(XMLString::transcode("id"));
                const XMLCh *controllerAttr = element->getAttribute(XMLString::transcode("controller"));
                const XMLCh *tagName = element->getNodeName();
                AbstractView *pView = Catalyst::ui::ViewFactory::getViewByTag(XMLString::transcode(tagName));
                AbstractController *pController = nullptr;
                if (controllerAttr != nullptr) {
                    pController = Catalyst::ui::ControllerFactory::getControllerByAttr(XMLString::transcode(controllerAttr));
                }
                if (pView != nullptr) {
                    bool success = document->addElement(XMLString::transcode(idAttr), pView, nullptr);
                    if (pController != nullptr) {
                        pView->setController(pController);
                    }
                    if (!success) {
                        cout << "AbstractView with same ID already declared \n";
                    }
                }
            }
        }
    }
}