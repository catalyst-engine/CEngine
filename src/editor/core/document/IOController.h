#ifndef CATALYST_IOCONTROLLER_H
#define CATALYST_IOCONTROLLER_H

#include "imgui.h"

namespace CEngine {

    class IOController {
    private:
        ImGuiIO *io;
    public:
        void setIo(ImGuiIO *pIo);

        ImGuiIO *getIo() const;

    };

}

#endif
