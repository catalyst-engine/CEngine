#include "EditorWindow.h"

int main(int, char **) {
    CEngine::EditorWindow window;
    window.onInitialize();
    window.start();
    return 0;
}