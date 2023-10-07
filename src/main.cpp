#include "ui/core/Window.h"
#include "ui/core/views/IView.h"

int main(int, char **) {
    Catalyst::ui::Window window("MAIN");
    if (!window.init()) {
        return 1;
    }
    window.getBuilder()->loadFromXML("Sample.xml");
    window.start();
    return 0;
}