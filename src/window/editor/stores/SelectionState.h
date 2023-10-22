#ifndef CATALYST_SELECTIONSTATE_H
#define CATALYST_SELECTIONSTATE_H

#include "entt/entity/entity.hpp"

namespace Catalyst {

    class SelectionState {
    private:
        entt::entity *selectedEntity = nullptr;
    public:
        entt::entity *getSelectedEntity() const;

        void setSelectedEntity(entt::entity *selectedEntity);
    };

}

#endif
