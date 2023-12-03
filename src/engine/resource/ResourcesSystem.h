#ifndef CATALYST_RESOURCESSYSTEM_H
#define CATALYST_RESOURCESSYSTEM_H

#include "StaticResource.h"
#include "resources/IResource.h"
#include "../../core/structures/Map.h"
#include "../../core/debug/ILoggable.h"

namespace CEngine {

    class ResourcesSystem : public ILoggable {
    private:
        Map<StaticResource, IResource *> staticResources;
        Map<std::string, IResource *> dynamicResources;

        void registerResource(IResource *resource, StaticResource id);

        void registerResource(IResource *resource, const char *id);

        IResource *createShader();

        IResource *createFBO();

        IResource *createVBO();

        IResource *createMesh();

        IResource *createTexture();

    public:
        template<class T>
        void createStaticResource(StaticResource id) {
            registerResource(new T, id);
        }

        template<class T>
        void createResource(const char *id) {
            registerResource(new T, id);
        }

        IResource *getResource(const std::string &id);

        IResource *getResource(StaticResource id);

        bool hasResource(const std::string &id);

        bool hasResource(StaticResource id);

        void deleteResource(StaticResource id);

        void deleteResource(const std::string &id);


        IResource *createShader(const char *id);

        IResource *createShader(StaticResource id);

        IResource *createFBO(const char *id);

        IResource *createFBO(StaticResource id);

        IResource *createVBO(const char *id);

        IResource *createVBO(StaticResource id);

        IResource *createMesh(const char *id);

        IResource *createMesh(StaticResource id);

        IResource *createTexture(const char *id);

        IResource *createTexture(StaticResource id);
    };

}

#endif
