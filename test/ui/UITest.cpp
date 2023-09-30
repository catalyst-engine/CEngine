#include <catch2/catch_test_macros.hpp>
#include "../../src/ui/Document.cpp"
#include "../../src/ui/components/Component.cpp"

class Test : public Catalyst::ui::Component {
public:
    void render() override {

    }
};

TEST_CASE("Should add element", "[ui-add]") {
    Catalyst::ui::Document document;
    document.addElement<Test>("c", nullptr);
    REQUIRE(document.getElements().getList()->getLength() == 1);
}

TEST_CASE("Should add child", "[ui-add-child]") {

    Catalyst::ui::Document document;
    Test *pTest = document.addElement<Test>("c", nullptr);
    document.addElement<Test>("2", pTest);
    REQUIRE(pTest->getChildren()->getLength() == 1);
    REQUIRE(document.getElements().getList()->getLength() == 2);
}