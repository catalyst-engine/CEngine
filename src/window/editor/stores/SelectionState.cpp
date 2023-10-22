#include "SelectionState.h"

namespace Catalyst {
    entt::entity *SelectionState::getSelectedEntity() const {
        return selectedEntity;
    }

    void SelectionState::setSelectedEntity(entt::entity *s) {
        SelectionState::selectedEntity = s;
    }
}