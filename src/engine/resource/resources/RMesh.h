#ifndef CATALYST_RMESH_H
#define CATALYST_RMESH_H

#include "../IResource.h"

namespace CEngine {

    class RMesh : public IResource {
    public:
        explicit RMesh() : IResource(ResourceType::MESH){}
    };

}


#endif
