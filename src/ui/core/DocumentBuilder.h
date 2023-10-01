#pragma once
#ifndef CATALYST_DOCUMENTBUILDER_H
#define CATALYST_DOCUMENTBUILDER_H

#include <iostream>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/sax/HandlerBase.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/util/PlatformUtils.hpp>


namespace Catalyst::ui {
    class Document;
    class ViewFactory;
    class ControllerFactory;

    class DocumentBuilder {
    public:
        static bool
        parseAndValidateXML(const char *xmlFileName, const char *xsdFileName, Catalyst::ui::Document *document);

    private:
        static void
        loadIntoDocument(Document *document, xercesc_3_2::DOMDocument *dom);
    };

}

#endif
