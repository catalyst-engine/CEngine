#ifndef CATALYST_RESOURCESSYSTEM_H
#define CATALYST_RESOURCESSYSTEM_H

#include <glad/glad.h>
#include "StaticResource.h"
#include "core/IResource.h"
#include "../../core/structures/Map.h"
#include "../../core/debug/ILoggable.h"

namespace CEngine {

    class ResourcesSystem : public ILoggable {
    private:
        Map<StaticResource, IResource *> staticResources;
        Map<std::string, IResource *> dynamicResources;

        void registerResource(IResource *resource, StaticResource id);

        void registerResource(IResource *resource, const char *id);

    public:

        static void createTexture(
                unsigned int *target,
                unsigned int width,
                unsigned int height,
                GLint internalFormat,
                GLint border,
                GLint format,
                GLint type,
                GLint minFilter,
                GLint magFilter,
                GLint wrapS,
                GLint wrapT,
                unsigned char *data
        );

        static void createBuffer(
                unsigned int *target,
                unsigned int type,
                std::vector<float> &data,
                unsigned int renderingType
        );

        template<class T>
        IResource *createResource(StaticResource id) {
            T *newResource = new T;
            newResource->setResourceSystem(this);
            registerResource(newResource, id);
            return newResource;
        }

        template<class T>
        IResource *createResource(const char *id) {
            T *newResource = new T;
            newResource->setResourceSystem(this);
            registerResource(newResource, id);
            return newResource;
        }

        template<class T>
        T *getResource(const std::string &id) {
            return (T *) dynamicResources.get(id);
        }

        template<class T>
        T *getResource(StaticResource id) {
            return (T *) staticResources.get(id);
        }

        bool hasResource(const std::string &id);

        bool hasResource(StaticResource id);

        void deleteResource(StaticResource id);

        void deleteResource(const std::string &id);
    };

}

#endif
