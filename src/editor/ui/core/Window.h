#pragma once
#ifndef CATALYST_WINDOW_H
#define CATALYST_WINDOW_H

#include "imgui.h"
#include "GLFW/glfw3.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "Document.h"
#include "DocumentBuilder.h"
#include "debug/ILoggable.h"

#define BACKGROUND_R .5
#define BACKGROUND_G .5
#define BACKGROUND_B .5
#define BACKGROUND_A 1

#define GLSL_VERSION "#version 130"

namespace Catalyst::ui {
    class Window : public Catalyst::ILoggable {
    private:
        const char *name;
        GLFWwindow *window = nullptr;
        ImGuiIO io;
        bool vsync = false;
        bool isRunning = false;
        Document document;
        DocumentBuilder documentBuilder;
        int display_w = 0, display_h = 0;

        static void onError(int error, const char *description) {
            fprintf(stderr, "GLFW Error %d: %s\n", error, description);
        }

        static void clearWindow() {
            glClearColor(BACKGROUND_R, BACKGROUND_G, BACKGROUND_B, BACKGROUND_A);
            glClear(GL_COLOR_BUFFER_BIT);
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        }

        bool createWindow();

        void createWindowIO();

        void startNewFrame();

        void drawNewFrame();

        void updateViewports() const;

        void render();

        void onShutdown();

    public:
        explicit Window(const char *name) : Catalyst::ILoggable("Window") {
            this->name = name;
        }

        bool init();

        Document *getDocument();

        GLFWwindow *getWindow();

        void start();

        DocumentBuilder *getBuilder();
    };
}
#endif //CATALYST_WINDOW_H
