#include <catch2/catch_test_macros.hpp>
#include "../../src/ui/core/views/IView.h"
#include "../../src/ui/core/controllers/TextController.cpp"
#include "../../src/ui/core/Document.h"
#include "../../src/ui/core/DocumentBuilder.h"

TEST_CASE("Should parse xml", "[document-parse]") {
    bool result = Catalyst::ui::DocumentBuilder::parseAndValidateXML("sampleUI.xml", "Schema.xsd", nullptr);
    REQUIRE(result == true);
}

TEST_CASE("Should load XML", "[document-parse]") {
    auto *doc = new Catalyst::ui::Document;
    bool result = Catalyst::ui::DocumentBuilder::parseAndValidateXML("sampleUI.xml", "Schema.xsd", doc);

    REQUIRE(result == true);
    REQUIRE(doc->getElements().getLength() == 1);
    REQUIRE(doc->getElements().getFirst()->value->getId() == "SECTION");
}
