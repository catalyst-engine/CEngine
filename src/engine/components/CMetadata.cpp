#include "CMetadata.h"

#include <utility>


namespace Catalyst::engine {

    ImVec4 CMetadata::getColor() {
        return color;
    }

    std::string CMetadata::getName() {
        return name;
    }

    std::string CMetadata::getEntityUUID() {
        return entityUUID;
    }

    void CMetadata::setName(std::string newName){
        this->name = std::move(newName);
    }

    void CMetadata::setColor(float r, float g, float b){
        color.x = r;
        color.y = g;
        color.z = b;
    }
}