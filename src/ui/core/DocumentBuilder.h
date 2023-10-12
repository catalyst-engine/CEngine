#pragma once
#ifndef CATALYST_DOCUMENTBUILDER_H
#define CATALYST_DOCUMENTBUILDER_H

#include <iostream>
#include "pugixml.hpp"
#include "../../util/debug/ILoggable.h"

namespace Catalyst::ui {
    class Document;

    class ViewFactory;

    class IElement;

    class DocumentBuilder : public Catalyst::ILoggable {
    private:
        Document *document;

        void
        loadIntoDocument(pugi::xml_node root, IElement *parent);

        void
        processNode(pugi::xml_node node, IElement *parent);

    public:
        bool loadFromXML(const char *xmlFileName);

        void setDocument(Document *doc) {
            this->document = doc;
        }

        explicit DocumentBuilder() : Catalyst::ILoggable("DocumentBuilder") {}
    };

}

#endif
