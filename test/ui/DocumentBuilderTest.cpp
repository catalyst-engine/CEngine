#include <catch2/catch_test_macros.hpp>
#include <string>
#include "../util/structures/Map.h"
#include "../ui/elements/IView.h"
#include "../ui/controllers/AbstractController.h"
#include "../ui/core/ViewFactory.h"
#include "../ui/core/ControllerFactory.h"
#include "../ui/core/Document.h"
#include "../ui/core/DocumentBuilder.h"

void init() {
    Catalyst::ui::ViewFactory::init();
    Catalyst::ui::ControllerFactory::init();
}

TEST_CASE("Should parse xml", "[document-parse]") {
    init();
    auto *doc = new Catalyst::ui::Document;
    Catalyst::ui::DocumentBuilder builder;
    builder.setDocument(doc);
    bool result = builder.loadFromXML("sampleUI.xml");
    REQUIRE(result == true);
}

TEST_CASE("Should collectAttributes XML", "[document-parse]") {
    init();
    auto *doc = new Catalyst::ui::Document;
    Catalyst::ui::DocumentBuilder builder;
    builder.setDocument(doc);
    bool result = builder.loadFromXML("sampleUI.xml");

    REQUIRE(result == true);
    REQUIRE(doc->getElements().getLength() == 1);
    REQUIRE(doc->getElements().getFirst()->value->getId() == "SECTION");
    REQUIRE(doc->getElements().getFirst()->value->getChildren()->getLength() == 1);
}
