#include "controllers/AbstractController.h"
#include "controllers/TextController.h"
#include "ControllerFactory.h"

namespace Catalyst::ui {
    AbstractController *ui::ControllerFactory::getControllerByAttr(const char *controller) {
        if (std::strcmp(controller, "TextController") == 0) {
            return (AbstractController *) new TextController;
        }
        if (std::strcmp(controller, "SectionController") == 0) {
//            return (IView *) new SectionView;
        }
        return nullptr;
    }
}