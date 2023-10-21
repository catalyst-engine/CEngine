#ifndef CATALYST_IOCONTROLLER_H
#define CATALYST_IOCONTROLLER_H

#include "imgui.h"

namespace Catalyst {

    class IOController {
    private:
        ImGuiIO *io;
    public:
        void setIo(ImGuiIO *pIo);

        ImGuiIO *getIo() const;

        void
    };

}

#endif
