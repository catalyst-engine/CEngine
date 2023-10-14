#pragma once
#ifndef CATALYST_IVIEW_H
#define CATALYST_IVIEW_H

#include <string>
#include "../elements/IElement.h"

namespace Catalyst {

    class IView : public IElement{
    public:
        virtual void update();
    };
}
#endif
