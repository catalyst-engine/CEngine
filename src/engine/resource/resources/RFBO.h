#ifndef CATALYST_RFBO_H
#define CATALYST_RFBO_H

#include "../IResource.h"

namespace CEngine{

    class RFBO : public IResource {
    public:
        explicit RFBO() : IResource(ResourceType::FBO){}
    };

}

#endif
