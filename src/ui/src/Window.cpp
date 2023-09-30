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
        window = glfwCreateWindow(1280, 720, "Dear ImGui GLFW+OpenGL3 example", nullptr, nullptr);
        if (window == nullptr) {
            return false;
        }
        return true;
    }

    void Window::startNewFrame() {
        glfwPollEvents();

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        document.render();
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

    void Window::render() {
        startNewFrame();
        drawNewFrame();
        clearWindow();
        updateViewports();
        glfwSwapBuffers(window);
    }

    void Window::onShutdown() {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();

        glfwDestroyWindow(window);
        glfwTerminate();
    }


    bool Window::init() {
        glfwSetErrorCallback(onError);
        if (!glfwInit()) {
            return false;
        }

        document = Document();

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

        bool isWindowCreated = createWindow();
        if (!isWindowCreated) {
            return false;
        }

        glfwMakeContextCurrent(window);
        glfwSwapInterval(vsync ? 1 : 0);

        createWindowIO();

        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init(GLSL_VERSION);
        return true;
    }

    Document* Window::getDocument() {
        return &document;
    }

    GLFWwindow* Window::getWindow() {
        return window;
    }

    void Window::start() {
        if (isRunning) {
            return;
        }
        isRunning = true;
        while (!glfwWindowShouldClose(window)) {
            render();
        }
        onShutdown();
    }
}