#include "ui/elements/IElement.h"
#include "EditorWindow.h"

int main(int, char **) {
    Catalyst::EditorWindow window;
    window.init();
    window.start();
    return 0;
}