#ifndef CATALYST_SELECTIONSTATE_H
#define CATALYST_SELECTIONSTATE_H

#include "entt/entity/entity.hpp"
#include <string>

namespace CEngine {

    class SelectionState {
    private:
        std::string selectedEntity;
    public:
        std::string getSelectedEntity() const;

        void setSelectedEntity(std::string selectedEntity);
    };

}

#endif
