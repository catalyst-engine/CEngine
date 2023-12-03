#ifndef CATALYST_IOCONTROLLER_H
#define CATALYST_IOCONTROLLER_H

#include "../../../../engine/external/IIOController.h"
#include "imgui.h"

namespace CEngine {

    class IOController : public IIOController {
    private:
        ImGuiIO &io;
        const int MAX_SIZE_MOUSE = IM_ARRAYSIZE(io.MouseDown);
        static Map<int, bool> pressedKeys;
    public:
        explicit IOController() : io(ImGui::GetIO()) {}

        float getMouseDeltaX() override;

        float getMouseDeltaY() override;

        float getMouseX() override;

        float getMouseY() override;

        bool isMouseButtonDown(int index) override;

        bool isMousePosValid() override;

        float getMouseButtonDuration(int index) override;

        float getMouseWheelAcceleration() override;

        Map<int, bool> *getPressedKeys() override;

        bool isAlt() override;

        bool isCTRL() override;

        bool isShift() override;

        bool isSuper() override;
    };

}

#endif
