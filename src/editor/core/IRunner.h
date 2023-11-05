#ifndef CATALYST_IRUNNER_H
#define CATALYST_IRUNNER_H

#include "GLFW/glfw3.h"
#include "imgui.h"

namespace CEngine {
    class Document;

    class IRunner {
    protected:
        GLFWwindow *window;
        Document &document;
    public:
        explicit IRunner(GLFWwindow *win, Document &doc) : window(win), document(doc) {}

        virtual int getWindowWidth() const {
            return 0;
        }

        virtual void setWindowWidth(int ww) {}

        virtual int getWindowHeight() const {
            return 0;
        }

        virtual void setWindowHeight(int wh) {}

        virtual void run() {}

    };

}

#endif
