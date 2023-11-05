#pragma once
#ifndef CATALYST_IWINDOW_H
#define CATALYST_IWINDOW_H

#include "imgui.h"
#include "GLFW/glfw3.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "../../engine/util/debug/ILoggable.h"
#include "document/Document.h"

#define GLSL_VERSION "#version 130"

namespace CEngine {
    class IRunner;

    class IWindow : public ILoggable {
    protected:
        GLFWwindow *window = nullptr;
        Document document;
        IRunner *runner = nullptr;

        bool ready = false;
        bool vsyncEnabled = false;

        static void onError(int error, const char *description) {
            fprintf(stderr, "GLFW Error %d: %s\n", error, description);
        }

        void createWindowIO();

    public:
        explicit IWindow();

        virtual void onInitialize();

        bool isVsyncEnabled() const;

        void setVsyncEnabled(bool vsyncEnabled);

        void start();

        Document &getDocument();

    };
}
#endif //CATALYST_IWINDOW_H
