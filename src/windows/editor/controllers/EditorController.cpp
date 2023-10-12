
#include "EditorController.h"
#include "../../../util/debug/ILoggable.h"

namespace Catalyst::editor {
    EditorController::EditorController() {
        logger = ILoggable::getNewLogger("EditorController");
    }

    void EditorController::update() {
        logger->info("HERE");
    }
}
