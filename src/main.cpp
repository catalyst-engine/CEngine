#include "windows/core/Window.h"
#include "ui/elements/IElement.h"
#include "Editor.h"

int main(int, char **) {
    Catalyst::ui::Window window("MAIN");
    if (!window.init()) {
        return 1;
    }
    Catalyst::editor::init(window);
    window.start();
    return 0;
}