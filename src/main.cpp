#include "ui/src/Window.h"
#include "ui/src/components/Section.h"

int main(int, char **) {
    Catalyst::ui::Window window{};
    if (!window.init()) {
        return 1;
    }
    window.getDocument()->addElement<Catalyst::ui::Section>("SEC", nullptr);
    window.start();
    return 0;
}