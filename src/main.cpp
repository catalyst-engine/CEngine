#include "ui/core/Window.h"
#include "ui/core/views/IView.h"
#include "ui/core/Document.h"
#include "ui/core/DocumentBuilder.h"
#include "ui/core/views/SectionView.h"

int main(int, char **) {
    Catalyst::ui::Window window{};
    if (!window.init()) {
        return 1;
    }
    Catalyst::ui::DocumentBuilder::loadFromXML("Footer.xml", window.getDocument());
    window.start();
    return 0;
}