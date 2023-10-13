#include "../src/window/core/AbstractWindow.h"
#include "../src/ui/elements/EText.cpp"
#include "../src/ui/elements/ESection.h"

int main(int, char **) {
    Catalyst::AbstractWindow window("MAIN");

    if (!window.init()) {
        return 1;
    }
    window.getDocument()->addElement<Catalyst::ESection>("SEC", nullptr);
    window.start();
    return 0;
}