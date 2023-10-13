#include <catch2/catch_test_macros.hpp>
#include <string>
#include "../util/structures/Map.h"
#include "../ui/core/ElementFactory.h"
#include "../ui/core/Document.h"

void init() {
    Catalyst::ElementFactory::init();
}
//
//TEST_CASE("Should parse xml", "[document-parse]") {
//    init();
//    auto *doc = new Catalyst::Document;
//    Catalyst::DocumentBuilder builder;
//    builder.setDocument(doc);
//    bool result = builder.loadFromXML("sampleUI.xml");
//    REQUIRE(result == true);
//}
//
//TEST_CASE("Should collectAttributes XML", "[document-parse]") {
//    init();
//    auto *doc = new Catalyst::Document;
//    Catalyst::DocumentBuilder builder;
//    builder.setDocument(doc);
//    bool result = builder.loadFromXML("sampleUI.xml");
//
//    REQUIRE(result == true);
//    REQUIRE(doc->getElements().getLength() == 1);
//    REQUIRE(doc->getElements().getFirst()->value->getId() == "SECTION");
//    REQUIRE(doc->getElements().getFirst()->value->getChildren()->getLength() == 1);
//}
