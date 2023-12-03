#include "ResourcesSystem.h"
#include "../../core/structures/Map.cpp"
#include "resources/RMesh.h"
#include "resources/RFBO.h"
#include "resources/RShader.h"
#include "resources/RVBO.h"
#include "resources/RTexture.h"

namespace CEngine {
    void ResourcesSystem::registerResource(IResource *resource, StaticResource id) {
        CONSOLE_WARN("Creating {0}", std::to_string(id))
        if (staticResources.has(id)) {
            CONSOLE_ERROR("Static resources already exists {0}", std::to_string(id))
            return;
        }
        staticResources.set(id, resource);
    }

    IResource *ResourcesSystem::getResource(const std::string &id) {
        return dynamicResources.get(id);
    }

    IResource *ResourcesSystem::getResource(StaticResource id) {
        return staticResources.get(id);
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

    IResource *ResourcesSystem::createTexture(StaticResource id) {
        if (staticResources.has(id)) {
            return nullptr;
        }
        IResource *pResource = createTexture();
        registerResource(pResource, id);
        return pResource;
    }

    IResource *ResourcesSystem::createShader(const char *id) {
        if (dynamicResources.has(id)) {
            return nullptr;
        }
        IResource *pResource = createShader();
        registerResource(pResource, id);
        return pResource;
    }

    IResource *ResourcesSystem::createShader(StaticResource id) {
        if (staticResources.has(id)) {
            return nullptr;
        }
        IResource *pResource = createShader();
        registerResource(pResource, id);
        return pResource;
    }

    IResource *ResourcesSystem::createFBO(const char *id) {
        if (dynamicResources.has(id)) {
            return nullptr;
        }
        IResource *pResource = createFBO();
        registerResource(pResource, id);
        return pResource;
    }

    IResource *ResourcesSystem::createFBO(StaticResource id) {
        if (staticResources.has(id)) {
            return nullptr;
        }
        IResource *pResource = createFBO();
        registerResource(pResource, id);
        return pResource;
    }

    IResource *ResourcesSystem::createVBO(const char *id) {
        if (dynamicResources.has(id)) {
            return nullptr;
        }
        IResource *pResource = createVBO();
        registerResource(pResource, id);
        return pResource;
    }

    IResource *ResourcesSystem::createVBO(StaticResource id) {
        if (staticResources.has(id)) {
            return nullptr;
        }
        IResource *pResource = createVBO();
        registerResource(pResource, id);
        return pResource;
    }

    IResource *ResourcesSystem::createMesh(const char *id) {
        if (dynamicResources.has(id)) {
            return nullptr;
        }
        IResource *pResource = createMesh();
        registerResource(pResource, id);
        return pResource;
    }

    IResource *ResourcesSystem::createMesh(StaticResource id) {
        if (staticResources.has(id)) {
            return nullptr;
        }
        IResource *pResource = createMesh();
        registerResource(pResource, id);
        return pResource;
    }

    IResource *ResourcesSystem::createTexture(const char *id) {
        if (dynamicResources.has(id)) {
            return nullptr;
        }
        IResource *pResource = createTexture();
        registerResource(pResource, id);
        return pResource;
    }

    IResource *ResourcesSystem::createMesh() {
        // TODO - ACTUAL IMPLEMENTATION OF RESOURCE INITIALIZATION
        return new RMesh;
    }

    IResource *ResourcesSystem::createFBO() {
        // TODO - ACTUAL IMPLEMENTATION OF RESOURCE INITIALIZATION
        return new RFBO;
    }

    IResource *ResourcesSystem::createVBO() {
        // TODO - ACTUAL IMPLEMENTATION OF RESOURCE INITIALIZATION
        return new RVBO;
    }

    IResource *ResourcesSystem::createShader() {
        // TODO - ACTUAL IMPLEMENTATION OF RESOURCE INITIALIZATION
        return new RShader;
    }

    IResource *ResourcesSystem::createTexture() {
        // TODO - ACTUAL IMPLEMENTATION OF RESOURCE INITIALIZATION
        return new RTexture;
    }
}