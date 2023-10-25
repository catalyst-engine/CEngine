#include "ETreeNode.h"
#include "../event/EventController.h"

namespace Catalyst {
    void ETreeNode::render() {
        if(ImGui::TreeNodeEx(text.c_str(), flags)){
            EventController::get()->triggerEvent("click", this);
            ImGui::TreePop();
        }
    }

    IElement *ETreeNode::copy() {
        return new ETreeNode;
    }

    void ETreeNode::loadFlags() {
        flags = 0;
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