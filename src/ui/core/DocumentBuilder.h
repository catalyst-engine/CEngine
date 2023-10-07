#pragma once
#ifndef CATALYST_DOCUMENTBUILDER_H
#define CATALYST_DOCUMENTBUILDER_H

#include <iostream>
#include "pugixml.hpp"

namespace Catalyst::ui {
    class Document;

    class ViewFactory;

    class ControllerFactory;

    class IView;

    class DocumentBuilder {
    public:
        static bool loadFromXML(const char *xmlFileName, Catalyst::ui::Document *document);

    private:
        static void
        loadIntoDocument(Document *document, pugi::xml_node root, IView *parent);

        static void
        processNode(pugi::xml_node node, Document *document, IView *parent);
    };

}

#endif
