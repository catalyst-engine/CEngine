#include "ETreeNode.h"
#include "../event/EventController.h"

namespace Catalyst {
    void ETreeNode::render() {
        ImGui::TreeNodeEx(text.c_str(), flags);
        if (ImGui::IsItemClicked() && !ImGui::IsItemToggledOpen()) {
            EventController::get()->triggerEvent("click", this);
        }
        if (!leaf) {
            ImGui::TreePop();
        }
    }

    IElement *ETreeNode::copy() {
        return new ETreeNode;
    }

    void ETreeNode::loadFlags() {
        flags = ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_OpenOnDoubleClick |
                ImGuiTreeNodeFlags_SpanAvailWidth;
        if (leaf) {
            flags |= ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_NoTreePushOnOpen;
        }
    }

    bool ETreeNode::isLeaf() const {
        return leaf;
    }

    void ETreeNode::setIsLeaf(bool isLeaf) {
        ETreeNode::leaf = isLeaf;
        loadFlags();
    }

}