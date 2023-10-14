#ifndef CATALYST_VIEWSSTATE_H
#define CATALYST_VIEWSSTATE_H


#include "../../util/structures/List.h"
#include "../views/IView.h"

namespace Catalyst {
    class ViewsState {
    private:
        List<IView> views;
    public:
        List<IView>* getViews();
    };
}


#endif
