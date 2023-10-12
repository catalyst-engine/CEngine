#include "Window.h"

namespace Catalyst::ui {
    void Window::createWindowIO() {
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

    bool Window::createWindow() {
        CONSOLE_LOG("CREATING WINDOW: {0}", name)
        window = glfwCreateWindow(1280, 720, name, nullptr, nullptr);
        if (window == nullptr) {
            return false;
        }
        return true;
    }

    void Window::startNewFrame() {
        glfwPollEvents();
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
    }

    void Window::drawNewFrame() {
        ImGui::Render();
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
    }

    void Window::updateViewports() const {
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
            GLFWwindow *backup_current_context = glfwGetCurrentContext();
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            glfwMakeContextCurrent(backup_current_context);
        }
    }

    void Window::onShutdown() {
        CONSOLE_LOG("SHUTTING DOWN")
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();

        glfwDestroyWindow(window);
        glfwTerminate();
    }

    bool Window::init() {
        CONSOLE_LOG("INITIALIZING...")
        glfwSetErrorCallback(onError);
        if (!glfwInit()) {
            CONSOLE_ERROR("ERROR INITIALIZING GLFW")
            return false;
        }
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

        bool isWindowCreated = createWindow();
        if (!isWindowCreated) {
            CONSOLE_ERROR("ERROR CREATING WINDOW")
            return false;
        }

        glfwMakeContextCurrent(window);
        glfwSwapInterval(vsync ? 1 : 0);

        createWindowIO();

        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init(GLSL_VERSION);
        CONSOLE_LOG("WINDOW CREATED")
        return true;
    }

    Document *Window::getDocument() {
        return &document;
    }

    GLFWwindow *Window::getWindow() {
        return window;
    }

    void Window::start() {
        if (isRunning) {
            return;
        }
        isRunning = true;
        while (!glfwWindowShouldClose(window)) {
            document.update();

            startNewFrame();
            document.render();
            drawNewFrame();
            clearWindow();
            updateViewports();
            glfwSwapBuffers(window);
        }
        onShutdown();
    }

    DocumentBuilder *Window::getBuilder() {
        documentBuilder.setDocument(&document);
        return &documentBuilder;
    }
}