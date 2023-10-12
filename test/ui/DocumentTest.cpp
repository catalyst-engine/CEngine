#include <catch2/catch_test_macros.hpp>
#include "../ui/elements/IElement.h"
#include "../ui/core/Document.h"

class Test : public Catalyst::ui::IElement {
public:
    void render() override {

    }
};

TEST_CASE("Should add element", "[document-add]") {
    Catalyst::ui::Document document;
    document.addElement<Test>("c", nullptr);
    REQUIRE(document.getElements().getLength() == 1);
}

TEST_CASE("Should add child", "[document-add-child]") {
    Catalyst::ui::Document document;
    Test *created = document.addElement<Test>("c", nullptr);
    document.addElement<Test>("2", created);
    Catalyst::ui::IElement *found = document.getElementById("c");
    REQUIRE(created->getChildren()->getLength() == 1);
    REQUIRE(document.quantityOfElements() == 2);
    REQUIRE(found == created);
}

TEST_CASE("Should find deep child", "[document-getbyid]") {
    Catalyst::ui::Document document;
    Test *created1 = document.addElement<Test>("1", nullptr);
    Test *created2 = document.addElement<Test>("2", created1);
    Test *created3 = document.addElement<Test>("3", created2);
    Test *created4 = document.addElement<Test>("4", created3);
    Test *created5 = document.addElement<Test>("5", created4);

    Catalyst::ui::IElement *found5 = document.getElementById("5");
    Catalyst::ui::IElement *found4 = document.getElementById("4");
    Catalyst::ui::IElement *found3 = document.getElementById("3");
    Catalyst::ui::IElement *found2 = document.getElementById("2");
    Catalyst::ui::IElement *found1 = document.getElementById("1");

    REQUIRE(found5 == created5);
    REQUIRE(found4 == created4);
    REQUIRE(found3 == created3);
    REQUIRE(found2 == created2);
    REQUIRE(found1 == created1);
}