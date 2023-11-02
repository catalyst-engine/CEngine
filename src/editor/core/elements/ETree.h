#ifndef CATALYST_ETREE_H
#define CATALYST_ETREE_H

#include "AbstractSimpleElement.h"

namespace Catalyst {

    class ETree : public AbstractSimpleElement  {
    public:
        void render() override;

        IElement * copy() override;
    };

}

#endif
