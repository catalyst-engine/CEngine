#ifndef CATALYST_IOCONTROLLER_H
#define CATALYST_IOCONTROLLER_H

#include "../../../../engine/external/IIOController.h"
#include "imgui.h"

namespace CEngine {

    class IOController : public IIOController {
    private:
        ImGuiIO &io;
    public:
        explicit IOController() : io(ImGui::GetIO()) {}

    };

}

#endif
