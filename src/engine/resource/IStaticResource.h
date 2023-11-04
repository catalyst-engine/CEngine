#ifndef CATALYST_ISTATICRESOURCE_H
#define CATALYST_ISTATICRESOURCE_H

#include "IResource.h"
#include "StaticResource.h"

namespace CEngine {

    class IStaticResource : public IResource {
    private:
        std::string id;
    public:
        explicit IStaticResource(StaticResource resourceID);

        bool isDeletable() override {
            return false;
        }

        std::string getId() override;
    };

}

#endif
