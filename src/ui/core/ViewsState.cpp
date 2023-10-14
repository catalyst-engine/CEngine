#include "ViewsState.h"

namespace Catalyst {
    List<Catalyst::IView> *ViewsState::getViews() {
        return &views;
    }
}