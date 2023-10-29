#include "AbstractWindow.h"
#include "../../ui/document/Document.h"
#include "Runner.h"

namespace Catalyst {
    void AbstractWindow::createWindowIO() {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        io = ImGui::GetIO();
        (void) io;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // Enable Docking
        io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;       // Enable Multi-Viewport / Platform Windows

        ImGui::StyleColorsDark();
        ImGuiStyle &style = ImGui::GetStyle();
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
            style.WindowRounding = 0.0f;
            style.Colors[ImGuiCol_WindowBg].w = 1.0f;
        }
    }

    AbstractWindow::AbstractWindow() {
        CONSOLE_LOG("INITIALIZING...")
        glfwSetErrorCallback(onError);
        if (!glfwInit()) {
            CONSOLE_ERROR("ERROR INITIALIZING GLFW")
            return;
        }
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

        window = glfwCreateWindow(1280, 720, "Window", nullptr, nullptr);
        if (window == nullptr) {
            CONSOLE_ERROR("ERROR CREATING WINDOW")
            return;
        }

        glfwMakeContextCurrent(window);
        setVsyncEnabled(true);
        createWindowIO();

        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init(GLSL_VERSION);
        CONSOLE_LOG("WINDOW CREATED")

        document = new Document(&io);
        runner = new Runner(window, &io, document);
        ready = true;
    }

    void AbstractWindow::start() {
        if (!ready || runner == nullptr || document == nullptr) {
            return;
        }
        runner->run();
        CONSOLE_LOG("SHUTTING DOWN")
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();

        glfwDestroyWindow(window);
        glfwTerminate();
    }

    Document *AbstractWindow::getDocument() {
        return document;
    }

    bool AbstractWindow::isVsyncEnabled() const {
        return vsyncEnabled;
    }

    void AbstractWindow::setVsyncEnabled(bool v) {
        glfwSwapInterval(v ? 1 : 0);
        AbstractWindow::vsyncEnabled = v;
    }

    void AbstractWindow::init() {

    }
}