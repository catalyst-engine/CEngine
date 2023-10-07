#include "../src/editor/ui/core/Window.h"
#include "../src/editor/ui/core/views/TextView.cpp"
#include "../src/editor/ui/core/controllers/TextController.cpp"
#include "../src/editor/ui/core/views/SectionView.h"

int main(int, char **) {
    Catalyst::ui::Window window("MAIN");

    if (!window.init()) {
        return 1;
    }
    window.getDocument()->addElement<Catalyst::ui::SectionView>("SEC", nullptr);
    window.start();
    return 0;
}