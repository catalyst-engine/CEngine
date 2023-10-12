#include "ViewFactory.h"
#include <string>
#include "../elements/IView.h"
#include "../elements/TextView.h"
#include "../elements/SectionView.h"
#include "../../util/structures/Map.cpp"

namespace Catalyst::ui {
    Catalyst::util::Map<std::string, IView *> ViewFactory::registered;

    IView *ViewFactory::getViewByTag(const char *tag) {
        if (!registered.has(tag)) {
            return nullptr;
        }
        IView *existing = registered.get(tag);
        return existing->copy();
    }

    void ViewFactory::init() {
        registerView<SectionView>("SectionView");
        registerView<TextView>("TextView");
    }

    void ViewFactory::registerViewInternal(const char *name, IView *view) {
        registered.set(name, view);
    }
}