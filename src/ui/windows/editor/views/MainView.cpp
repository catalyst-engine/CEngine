#include "MainView.h"

namespace CEngine {
    IElement *MainView::copy() {
        return new MainView;
    }
}