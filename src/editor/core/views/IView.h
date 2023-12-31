#pragma once
#ifndef CATALYST_IVIEW_H
#define CATALYST_IVIEW_H

#include <string>
#include "../elements/IElement.h"

namespace CEngine {

    class IView : public IElement {
    public:

        /**
         * Executed before removal, useful for unloading resources
         */
        virtual void onDestroy();

        /**
         * Executed every frame
         */
        virtual void update();

    };
}
#endif
