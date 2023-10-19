#include "ViewsState.h"
#include "../views/IView.h"
#include "../../util/StringUtils.h"
#include "../../util/structures/Map.cpp"

namespace Catalyst {
    Catalyst::Map<std::string, IView *> ViewsState::registeredViews;

    List<Catalyst::IView> *ViewsState::getViews() {
        return &views;
    }

    IView *ViewsState::addView(const char *tag) {
        if (!ViewsState::registeredViews.has(tag)) {
            CONSOLE_ERROR("view with tag {0} was not found", tag)
            return nullptr;
        }
        IView *view = (IView *) ViewsState::registeredViews.get(tag)->copy();
        if(view == nullptr){
            CONSOLE_ERROR("view {0} doesn't implement method 'copy'", tag)
            return nullptr;
        }

        views.push(view);
        return view;
    }
}