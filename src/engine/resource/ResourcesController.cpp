#include "ResourcesController.h"
#include "../util/structures/Map.cpp"

namespace CEngine {
    void ResourcesController::registerStaticResource(IResource *resource, StaticResource id) {
        CONSOLE_WARN("Creating {0}", std::to_string(id))
        if (staticResources.has(id)) {
            CONSOLE_ERROR("Static resource already exists {0}", std::to_string(id))
            return;
        }
        staticResources.set(id, resource);
    }

    IResource *ResourcesController::getResource(const std::string &id) {
        return dynamicResources.get(id);
    }

    IResource *ResourcesController::getStaticResource(StaticResource id) {
        return staticResources.get(id);
    }

    bool ResourcesController::hasResource(const std::string &id) {
        return dynamicResources.has(id);
    }

    bool ResourcesController::hasStaticResource(StaticResource id) {
        return staticResources.has(id);
    }

    void ResourcesController::registerResource(IResource *resource, const char *id) {
        CONSOLE_WARN("Creating {0}", id)
        if (dynamicResources.has(id)) {
            CONSOLE_ERROR("Dynamic resource already exists {0}", id)
            return;
        }
        dynamicResources.set(id, resource);
    }

    void ResourcesController::deleteResource(const std::string &id) {
        CONSOLE_WARN("Deleting {0}", id)
        if (!dynamicResources.has(id)) {
            CONSOLE_ERROR("Dynamic resource doesn't exists {0}", id)
            return;
        }
        IResource *pResource = dynamicResources.get(id);
        delete pResource;
        dynamicResources.deleteKey(id);
    }

    void ResourcesController::deleteStaticResource(StaticResource id) {
        CONSOLE_WARN("Deleting {0}", std::to_string(id))
        if (!staticResources.has(id)) {
            CONSOLE_ERROR("Static resource doesn't exists {0}", std::to_string(id))
            return;
        }
        IResource *pResource = staticResources.get(id);
        delete pResource;
        staticResources.deleteKey(id);
    }
}