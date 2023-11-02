#pragma once
#ifndef CATALYST_ABSTRACTWINDOW_H
#define CATALYST_ABSTRACTWINDOW_H

#include "imgui.h"
#include "GLFW/glfw3.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "../../engine/util/debug/ILoggable.h"

#define GLSL_VERSION "#version 130"

namespace Catalyst {
    class Runner;

    class Document;

    class AbstractWindow : public ILoggable {
    protected:
        GLFWwindow *window = nullptr;
        Runner *runner = nullptr;
        Document *document = nullptr;
        ImGuiIO io;
        bool ready = false;
        bool vsyncEnabled = false;

        static void onError(int error, const char *description) {
            fprintf(stderr, "GLFW Error %d: %s\n", error, description);
        }

        void createWindowIO();

    public:
        virtual void init();

        bool isVsyncEnabled() const;

        void setVsyncEnabled(bool vsyncEnabled);

        void start();

        explicit AbstractWindow();

        Document *getDocument();

    };
}
#endif //CATALYST_ABSTRACTWINDOW_H
