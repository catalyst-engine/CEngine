#ifndef CATALYST_EXAMPLE_H
#define CATALYST_EXAMPLE_H


#include "../../../src/editor/core/views/IView.h"

namespace CEngine{
    class Example : public IView{
    public:
        IElement * copy() override;
    };
}


#endif
