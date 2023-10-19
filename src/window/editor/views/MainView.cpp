#include "MainView.h"

namespace Catalyst {
    IElement *MainView::copy() {
        return new MainView;
    }
}