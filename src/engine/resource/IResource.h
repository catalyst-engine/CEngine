#ifndef CATALYST_IRESOURCE_H
#define CATALYST_IRESOURCE_H

#include <string>
#include "ResourceType.h"

namespace CEngine {

    class IResource {
    private:
        ResourceType type;
    public:
        explicit IResource (ResourceType type);

        ResourceType getType() const;
    };

}
#endif
