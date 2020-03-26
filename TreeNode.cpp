#include "TreeNode.h"
#include "PlayField.h"

TreeNode::TreeNode(PlayField newState, TreeNode* parent): state(newState), parent(parent){}

TreeNode& TreeNode::operator[](int index) {
    return *children[index];
}

const PlayField& TreeNode::value() const {
    return state;
}

bool TreeNode::isTerminal() const {
    return state.checkFieldStatus() != PlayField::fsNormal;
}

void TreeNode::addChild(TreeNode* child) {
    child->parent = this;
    children.push_back(child);
}

int TreeNode::childCount() const{
    return children.size();
}