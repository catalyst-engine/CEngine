#include "../src/windows/core/Window.h"
#include "../src/ui/elements/EText.cpp"
#include "../src/ui/elements/ESection.h"

int main(int, char **) {
    Catalyst::ui::Window window("MAIN");

    if (!window.init()) {
        return 1;
    }
    window.getDocument()->addElement<Catalyst::ui::ESection>("SEC", nullptr);
    window.start();
    return 0;
}