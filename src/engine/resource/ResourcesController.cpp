#include "ResourcesController.h"
#include "../util/structures/Map.cpp"
#include "resources/RMesh.h"
#include "resources/RFBO.h"
#include "resources/RShader.h"
#include "resources/RVBO.h"
#include "resources/RTexture.h"

namespace CEngine {
    void ResourcesController::registerResource(IResource *resource, StaticResource id) {
        CONSOLE_WARN("Creating {0}", std::to_string(id))
        if (staticResources.has(id)) {
            CONSOLE_ERROR("Static resources already exists {0}", std::to_string(id))
            return;
        }
        staticResources.set(id, resource);
    }

    IResource *ResourcesController::getResource(const std::string &id) {
        return dynamicResources.get(id);
    }

    IResource *ResourcesController::getResource(StaticResource id) {
        return staticResources.get(id);
    }

    bool ResourcesController::hasResource(const std::string &id) {
        return dynamicResources.has(id);
    }

    bool ResourcesController::hasResource(StaticResource id) {
        return staticResources.has(id);
    }

    void ResourcesController::registerResource(IResource *resource, const char *id) {
        CONSOLE_WARN("Creating {0}", id)
        if (dynamicResources.has(id)) {
            CONSOLE_ERROR("Dynamic resources already exists {0}", id)
            return;
        }
        dynamicResources.set(id, resource);
    }

    void ResourcesController::deleteResource(const std::string &id) {
        CONSOLE_WARN("Deleting {0}", id)
        if (!dynamicResources.has(id)) {
            CONSOLE_ERROR("Dynamic resources doesn't exists {0}", id)
            return;
        }
        IResource *pResource = dynamicResources.get(id);
        delete pResource;
        dynamicResources.deleteKey(id);
    }

    void ResourcesController::deleteResource(StaticResource id) {
        CONSOLE_WARN("Deleting {0}", std::to_string(id))
        if (!staticResources.has(id)) {
            CONSOLE_ERROR("Static resources doesn't exists {0}", std::to_string(id))
            return;
        }
        IResource *pResource = staticResources.get(id);
        delete pResource;
        staticResources.deleteKey(id);
    }

    IResource *ResourcesController::createTexture(StaticResource id) {
        if (staticResources.has(id)) {
            return nullptr;
        }
        IResource *pResource = createTexture();
        registerResource(pResource, id);
        return pResource;
    }

    IResource *ResourcesController::createShader(const char *id) {
        if (dynamicResources.has(id)) {
            return nullptr;
        }
        IResource *pResource = createShader();
        registerResource(pResource, id);
        return pResource;
    }

    IResource *ResourcesController::createShader(StaticResource id) {
        if (staticResources.has(id)) {
            return nullptr;
        }
        IResource *pResource = createShader();
        registerResource(pResource, id);
        return pResource;
    }

    IResource *ResourcesController::createFBO(const char *id) {
        if (dynamicResources.has(id)) {
            return nullptr;
        }
        IResource *pResource = createFBO();
        registerResource(pResource, id);
        return pResource;
    }

    IResource *ResourcesController::createFBO(StaticResource id) {
        if (staticResources.has(id)) {
            return nullptr;
        }
        IResource *pResource = createFBO();
        registerResource(pResource, id);
        return pResource;
    }

    IResource *ResourcesController::createVBO(const char *id) {
        if (dynamicResources.has(id)) {
            return nullptr;
        }
        IResource *pResource = createVBO();
        registerResource(pResource, id);
        return pResource;
    }

    IResource *ResourcesController::createVBO(StaticResource id) {
        if (staticResources.has(id)) {
            return nullptr;
        }
        IResource *pResource = createVBO();
        registerResource(pResource, id);
        return pResource;
    }

    IResource *ResourcesController::createMesh(const char *id) {
        if (dynamicResources.has(id)) {
            return nullptr;
        }
        IResource *pResource = createMesh();
        registerResource(pResource, id);
        return pResource;
    }

    IResource *ResourcesController::createMesh(StaticResource id) {
        if (staticResources.has(id)) {
            return nullptr;
        }
        IResource *pResource = createMesh();
        registerResource(pResource, id);
        return pResource;
    }

    IResource *ResourcesController::createTexture(const char *id) {
        if (dynamicResources.has(id)) {
            return nullptr;
        }
        IResource *pResource = createTexture();
        registerResource(pResource, id);
        return pResource;
    }

    IResource *ResourcesController::createMesh() {
        // TODO - ACTUAL IMPLEMENTATION OF RESOURCE INITIALIZATION
        return new RMesh;
    }

    IResource *ResourcesController::createFBO() {
        // TODO - ACTUAL IMPLEMENTATION OF RESOURCE INITIALIZATION
        return new RFBO;
    }

    IResource *ResourcesController::createVBO() {
        // TODO - ACTUAL IMPLEMENTATION OF RESOURCE INITIALIZATION
        return new RVBO;
    }

    IResource *ResourcesController::createShader() {
        // TODO - ACTUAL IMPLEMENTATION OF RESOURCE INITIALIZATION
        return new RShader;
    }

    IResource *ResourcesController::createTexture() {
        // TODO - ACTUAL IMPLEMENTATION OF RESOURCE INITIALIZATION
        return new RTexture;
    }
}