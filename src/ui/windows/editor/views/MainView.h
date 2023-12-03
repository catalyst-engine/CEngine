#ifndef CATALYST_MAINVIEW_H
#define CATALYST_MAINVIEW_H

#include "../../../core/views/IView.h"

namespace CEngine {

    class MainView : public IView{

    public:
        IElement * copy() override;
    };

}

#endif