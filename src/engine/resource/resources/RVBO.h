#ifndef CATALYST_RVBO_H
#define CATALYST_RVBO_H

#include "../IResource.h"

namespace CEngine {

    class RVBO : public IResource {
    public:
        explicit RVBO() : IResource(ResourceType::VBO){}
    };

}

#endif
