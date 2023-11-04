#ifndef CATALYST_RESOURCESCONTROLLER_H
#define CATALYST_RESOURCESCONTROLLER_H

#include "StaticResource.h"
#include "IResource.h"
#include "structures/Map.h"
#include "debug/ILoggable.h"

namespace CEngine {

    class ResourcesController : public ILoggable{
    private:
        Map<StaticResource, IResource *> staticResources;
        Map<std::string, IResource *> dynamicResources;

        void registerStaticResource(IResource *resource, StaticResource id);

        void registerResource(IResource *resource, const char *id);

    public:
        template<class T>
        void createStaticResource(StaticResource id) {
            registerStaticResource(new T, id);
        }

        template<class T>
        void createResource(const char *id) {
            registerResource(new T, id);
        }

        IResource *getResource(const std::string &id);

        IResource *getStaticResource(StaticResource id);

        bool hasResource(const std::string &id);

        bool hasStaticResource(StaticResource id);

        void deleteStaticResource(StaticResource id);

        void deleteResource(const std::string &id);

    };

}

#endif
