#ifndef CATALYST_RUNNER_H
#define CATALYST_RUNNER_H

#include "GLFW/glfw3.h"
#include "imgui.h"
#include "../../../core/IRunner.h"

#define BACKGROUND_R .5
#define BACKGROUND_G .5
#define BACKGROUND_B .5
#define BACKGROUND_A 1

namespace CEngine {
    class Document;

    class Runner : public IRunner {
    private:
        bool isRunning = false;
        int windowWidth = 0;
        int windowHeight = 0;

        void render();

        void updateViewports() const;

        void drawNewFrame();

        static void startNewFrame();

        static void clearWindow();

        void update();

    public:
        explicit Runner(GLFWwindow *win, Document &doc) : IRunner(win, doc) {}

        int getWindowWidth() const override;

        void setWindowWidth(int ww) override;

        int getWindowHeight() const override;

        void setWindowHeight(int wh) override;

        void run() override;


    };

}

#endif
