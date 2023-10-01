#include "../src/ui/core/Window.h"
#include "../src/ui/core/views/TextView.cpp"
#include "../src/ui/core/controllers/TextController.cpp"
#include "../src/ui/core/views/SectionView.h"

int main(int, char **) {
    Catalyst::ui::Window window{};
    if (!window.init()) {
        return 1;
    }
    window.getDocument()->addElement<Catalyst::ui::SectionView>("SEC", nullptr);
    window.start();
    return 0;
}