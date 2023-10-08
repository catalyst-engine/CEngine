#include "ControllerFactory.h"
#include "controllers/AbstractController.h"
#include "../../util/structures/Map.cpp"

namespace Catalyst::ui {
    Catalyst::util::Map<std::string, AbstractController *> ControllerFactory::registered;

    AbstractController *ui::ControllerFactory::getControllerByAttr(const char *controller) {
        if (!registered.has(controller)) {
            return nullptr;
        }
        AbstractController *existing = registered.get(controller);
        return existing->copy();
    }

    void ControllerFactory::init() {

    }

    void ControllerFactory::registerControllerInternal(const char *name, AbstractController *controller) {
        registered.set(name, controller);
    }
}