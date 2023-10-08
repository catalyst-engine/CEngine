#ifndef CATALYST_CMETADATA_H
#define CATALYST_CMETADATA_H

#include "IComponent.h"

namespace Catalyst::engine {

    class CMetadata : public IComponent {

    public:
        explicit CMetadata(entt::entity ent) : IComponent(ent){}
    };
}

#endif //CATALYST_CMETADATA_H
