#include <iostream>
#include "EditorWindow.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

int main(int, char **) {
    CEngine::EditorWindow window;
    window.onInitialize();
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    window.start();
    return 0;
}