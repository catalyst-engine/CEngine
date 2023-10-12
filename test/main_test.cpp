#include "../src/ui/core/Window.h"
#include "../src/ui/elements/TextView.cpp"
#include "../src/ui/elements/SectionView.h"

int main(int, char **) {
    Catalyst::ui::Window window("MAIN");

    if (!window.init()) {
        return 1;
    }
    window.getDocument()->addElement<Catalyst::ui::SectionView>("SEC", nullptr);
    window.start();
    return 0;
}