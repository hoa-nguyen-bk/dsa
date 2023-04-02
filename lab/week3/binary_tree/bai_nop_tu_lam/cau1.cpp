int countTwoChildrenNode(Node* node) {
    if (node == nullptr) return 0;
    int count = 0;
    if (node->pLeft != nullptr && node->pRight != nullptr) count++;
    count += countTwoChildrenNode(node->pLeft);
    count += countTwoChildrenNode(node->pRight);
    return count;
}

int countTwoChildrenNode() {
    return countTwoChildrenNode(root);
}