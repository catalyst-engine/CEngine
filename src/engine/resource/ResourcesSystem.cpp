#include <glad/glad.h>
#include "ResourcesSystem.h"
#include "../../core/structures/Map.cpp"
#include "resources/RMesh.h"

namespace CEngine {
    void ResourcesSystem::registerResource(IResource *resource, StaticResource id) {
        CONSOLE_WARN("Creating {0}", std::to_string(id))
        if (staticResources.has(id)) {
            CONSOLE_ERROR("Static resources already exists {0}", std::to_string(id))
            return;
        }
        staticResources.set(id, resource);
    }

    bool ResourcesSystem::hasResource(const std::string &id) {
        return dynamicResources.has(id);
    }

    bool ResourcesSystem::hasResource(StaticResource id) {
        return staticResources.has(id);
    }

    void ResourcesSystem::registerResource(IResource *resource, const char *id) {
        CONSOLE_WARN("Creating {0}", id)
        if (dynamicResources.has(id)) {
            CONSOLE_ERROR("Dynamic resources already exists {0}", id)
            return;
        }
        dynamicResources.set(id, resource);
    }

    void ResourcesSystem::deleteResource(const std::string &id) {
        CONSOLE_WARN("Deleting {0}", id)
        if (!dynamicResources.has(id)) {
            CONSOLE_ERROR("Dynamic resources doesn't exists {0}", id)
            return;
        }
        IResource *pResource = dynamicResources.get(id);
        delete pResource;
        dynamicResources.deleteKey(id);
    }

    void ResourcesSystem::deleteResource(StaticResource id) {
        CONSOLE_WARN("Deleting {0}", std::to_string(id))
        if (!staticResources.has(id)) {
            CONSOLE_ERROR("Static resources doesn't exists {0}", std::to_string(id))
            return;
        }
        IResource *pResource = staticResources.get(id);
        delete pResource;
        staticResources.deleteKey(id);
    }

    void ResourcesSystem::createTexture(
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
            GLint wrapT
    ) {
        glGenTextures(1, target);
        glBindTexture(GL_TEXTURE_2D, *target);
        glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, border, format, type, data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magFilter);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFilter);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapS);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapT);
        glBindTexture(GL_TEXTURE_2D, 0);
    }

    void ResourcesSystem::createBuffer(
            unsigned int *target,
            unsigned int type,
            std::vector<float> &data,
            unsigned int renderingType
    ) {
        glGenBuffers(1, target);
        glBindBuffer(type, *target);
        glBufferData(type, data.size() * sizeof(float), &data[0], renderingType);
    }

}