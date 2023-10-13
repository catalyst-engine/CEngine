#ifndef CATALYST_RUNNER_H
#define CATALYST_RUNNER_H

#include "GLFW/glfw3.h"
#include "imgui.h"

#define BACKGROUND_R .5
#define BACKGROUND_G .5
#define BACKGROUND_B .5
#define BACKGROUND_A 1

namespace Catalyst {
    class Document;

    class Runner {
    private:
        GLFWwindow *window = nullptr;
        ImGuiIO *io = nullptr;
        Document *document = nullptr;
        bool isRunning = false;
        int windowWidth = 0;
        int windowHeight = 0;

        void renderUI();

        void updateViewports() const;

        void drawNewFrame();

        static void startNewFrame();

        static void clearWindow();

    public:
        explicit Runner(GLFWwindow *window, ImGuiIO *io, Document *document);

        int getWindowWidth() const;

        void setWindowWidth(int ww);

        int getWindowHeight() const;

        void setWindowHeight(int wh);

        void run();
    };

}

#endif
