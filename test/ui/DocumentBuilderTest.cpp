#include <catch2/catch_test_macros.hpp>
#include "../editor/ui/core/views/IView.h"
#include "../editor/ui/core/controllers/TextController.cpp"
#include "../editor/ui/core/Document.h"
#include "../editor/ui/core/DocumentBuilder.h"

TEST_CASE("Should parse xml", "[document-parse]") {
    auto *doc = new Catalyst::ui::Document;
    Catalyst::ui::DocumentBuilder builder;
    builder.setDocument(doc);
    bool result = builder.loadFromXML("sampleUI.xml");
    REQUIRE(result == true);
}

TEST_CASE("Should load XML", "[document-parse]") {
    auto *doc = new Catalyst::ui::Document;
    Catalyst::ui::DocumentBuilder builder;
    builder.setDocument(doc);
    bool result = builder.loadFromXML("sampleUI.xml");

    REQUIRE(result == true);
    REQUIRE(doc->getElements().getLength() == 1);
    REQUIRE(doc->getElements().getFirst()->value->getId() == "SECTION");
    REQUIRE(doc->getElements().getFirst()->value->getChildren()->getLength() == 1);
}
