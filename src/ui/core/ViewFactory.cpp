#include "ViewFactory.h"
#include <string>
#include "../elements/IElement.h"
#include "../elements/EText.h"
#include "../elements/ESection.h"
#include "../../util/structures/Map.cpp"

namespace Catalyst::ui {
    Catalyst::util::Map<std::string, IElement *> ViewFactory::registered;

    IElement *ViewFactory::getViewByTag(const char *tag) {
        if (!registered.has(tag)) {
            return nullptr;
        }
        IElement *existing = registered.get(tag);
        return existing->copy();
    }

    void ViewFactory::init() {
        registerView<ESection>("ESection");
        registerView<EText>("EText");
    }

    void ViewFactory::registerViewInternal(const char *name, IElement *view) {
        registered.set(name, view);
    }
}