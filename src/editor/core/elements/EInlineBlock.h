#ifndef CATALYST_EINLINEBLOCK_H
#define CATALYST_EINLINEBLOCK_H

#include "IElement.h"

namespace Catalyst {

    class EInlineBlock : public IElement{
    public:
        void render() override;
        IElement * copy() override;
    };

}

#endif
