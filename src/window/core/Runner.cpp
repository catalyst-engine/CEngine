#include "Runner.h"
#include "../../ui/elements/IElement.h"
#include "../../ui/core/Document.h"
#include "imgui.h"
#include "GLFW/glfw3.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

namespace Catalyst {
    void Runner::updateUI() {
        auto list = *document->getViewsState()->getViews();
        list.iterate();
        while (list.hasNext()) {
            auto *next = list.next();
            next->update();
        }
    }

    void Runner::renderUI() {
        auto list = *document->getElementsState()->getElements();
        list.iterate();
        while (list.hasNext()) {
            auto *next = list.next();
            next->render();
        }
    }

    Runner::Runner(GLFWwindow *window, ImGuiIO *io, Document *document) {
        this->io = io;
        this->window = window;
        this->document = document;
    }

    void Runner::updateViewports() const {
        if (io->ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
            GLFWwindow *backup_current_context = glfwGetCurrentContext();
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            glfwMakeContextCurrent(backup_current_context);
        }
    }

    void Runner::startNewFrame() {
        glfwPollEvents();
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
    }

    void Runner::drawNewFrame() {
        ImGui::Render();
        glfwGetFramebufferSize(window, &windowWidth, &windowHeight);
        glViewport(0, 0, windowWidth, windowHeight);
    }

    void Runner::clearWindow() {
        glClearColor(BACKGROUND_R, BACKGROUND_G, BACKGROUND_B, BACKGROUND_A);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    void Runner::run() {
        if (isRunning) {
            return;
        }
        isRunning = true;
        while (!glfwWindowShouldClose(window)) {
            updateUI();
            startNewFrame();
            renderUI();
            drawNewFrame();
            clearWindow();
            updateViewports();
            glfwSwapBuffers(window);
        }
    }

    int Runner::getWindowWidth() const {
        return windowWidth;
    }

    void Runner::setWindowWidth(int ww) {
        Runner::windowWidth = ww;
    }

    int Runner::getWindowHeight() const {
        return windowHeight;
    }

    void Runner::setWindowHeight(int wh) {
        Runner::windowHeight = wh;
    }

}
