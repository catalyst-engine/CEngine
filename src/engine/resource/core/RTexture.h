#ifndef CATALYST_RTEXTURE_H
#define CATALYST_RTEXTURE_H

#include "IResource.h"

namespace CEngine{

    class RTexture : public IResource {
    public:
        explicit RTexture() : IResource(ResourceType::TEXTURE){}
    };
}

#endif
