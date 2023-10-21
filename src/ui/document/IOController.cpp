#include "IOController.h"

namespace Catalyst {
    ImGuiIO *IOController::getIo() const {
        return io;
    }

    void IOController::setIo(ImGuiIO *pIo) {
        IOController::io = pIo;
    }
}