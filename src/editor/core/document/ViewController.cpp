#include "ViewController.h"
#include "../views/IView.h"
#include "../../../engine/util/StringUtils.h"
#include "../../../engine/util/structures/Map.cpp"

namespace CEngine {
    CEngine::Map<std::string, IView *> ViewController::registeredViews;

    List<CEngine::IView> &ViewController::getViews() {
        return views;
    }

    IView *ViewController::addView(const char *tag) {
        if (!ViewController::registeredViews.has(tag)) {
            CONSOLE_ERROR("view with tag {0} was not found", tag)
            return nullptr;
        }
        IView *view = (IView *) ViewController::registeredViews.get(tag)->copy();
        if(view == nullptr){
            CONSOLE_ERROR("view {0} doesn't implement method 'copy'", tag)
            return nullptr;
        }

        views.push(view);
        return view;
    }
}