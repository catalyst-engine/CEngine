#ifndef CATALYST_RUBO_H
#define CATALYST_RUBO_H

#include "IResource.h"

namespace CEngine {

    class RUBO : public IResource {
    public:
        explicit RUBO() : IResource(ResourceType::UBO){}
    };

}

#endif
