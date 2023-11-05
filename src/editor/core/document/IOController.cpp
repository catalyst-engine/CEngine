#include "IOController.h"

namespace CEngine {
    ImGuiIO *IOController::getIo() const {
        return io;
    }

    void IOController::setIo(ImGuiIO *pIo) {
        IOController::io = pIo;
    }
}