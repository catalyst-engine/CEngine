#define CATCH_CONFIG_MAIN

#include "../../libs/catch2/catch.h"
#include "../../src/ui/AbstractUIComponent.h"

class Test : public AbstractUIComponent {
public:
    void render() override {

    }
};

TEST_CASE("Should add element", "[ui-add]") {
    UI::Document::addElement<Test>("c");
    REQUIRE(UI::elements.getList()->getLength() == 1);
}

TEST_CASE("Should add child", "[ui-add-child]") {
    Test *pTest = UI::Document::addElement<Test>("c");
    pTest->addChild<Test>("2");
    REQUIRE(pTest->getChildren()->getLength() == 1);
    REQUIRE(UI::elements.getList()->getLength() == 2);
}