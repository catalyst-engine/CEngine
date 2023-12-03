#ifndef CATALYST_RSHADER_H
#define CATALYST_RSHADER_H

#include "IResource.h"

namespace CEngine{

    class RShader : public IResource {
    public:
        explicit RShader() : IResource(ResourceType::SHADER){}
    };

}

#endif
