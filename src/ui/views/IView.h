#pragma once
#ifndef CATALYST_IVIEW_H
#define CATALYST_IVIEW_H

#include <string>

namespace Catalyst {
    class IElement;

    class IView {
    public:
        virtual void update();
    };
}
#endif
