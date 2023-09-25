#define CATCH_CONFIG_MAIN

#include <catch.hpp>
#include "../../src/ui/Document.cpp"
#include "../../src/ui/components/UIComponent.cpp"

class Test : public UIComponent {
public:
    void render() override {

    }
};

TEST_CASE("Should add element", "[ui-add]") {
    UI::Document document;
    document.addElement<Test>("c", nullptr);
    REQUIRE(document.getElements().getList()->getLength() == 1);
}

TEST_CASE("Should add child", "[ui-add-child]") {

    UI::Document document;
    Test *pTest = document.addElement<Test>("c", nullptr);
    document.addElement<Test>("2", pTest);
    REQUIRE(pTest->getChildren()->getLength() == 1);
    REQUIRE(document.getElements().getList()->getLength() == 2);
}