#pragma once
#ifndef CATALYST_IVIEW_H
#define CATALYST_IVIEW_H

#include <string>
#include "../elements/IElement.h"

namespace Catalyst {

    class IView : public IElement {
    public:
        /**
         * Executed after loaded into document
         */
        virtual void onInitialize();

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
