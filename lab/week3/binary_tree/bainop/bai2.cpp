int hR(Node * root) {
    if (root == NULL) {
        return 0;
    }
    return max(hR(root->pLeft), hR(root->pRight)) + 1;
}
int getHeight() {
    // TODO: return height of the binary tree.
    return hR(this->root);
}

string preOrder(Node * root) {
    // TODO: return the sequence of values of nodes in pre-order.
    if (root == NULL) {
        return "";
    }

    stringstream ss;
    ss << root->value << " ";
    ss << preOrder(root->pLeft);
    ss << preOrder(root->pRight);
    return ss.str();
}

string preOrder() {
    // TODO: return the sequence of values of nodes in pre-order.
    return preOrder(this->root);
}

string inOrder(Node * root) {
    // TODO: return the sequence of values of nodes in pre-order.
    if (root == NULL) {
        return "";
    }

    stringstream ss;
    ss << inOrder(root->pLeft);
    ss << root->value << " ";
    ss << inOrder(root->pRight);
    return ss.str();
}

string inOrder() {
    // TODO: return the sequence of values of nodes in in-order.
    return inOrder(this->root);
}

string postOrder(Node * root) {
    // TODO: return the sequence of values of nodes in pre-order.
    if (root == NULL) {
        return "";
    }

    stringstream ss;
    ss << postOrder(root->pLeft);
    ss << postOrder(root->pRight);
    ss << root->value << " ";
    return ss.str();
}

string postOrder() {
    // TODO: return the sequence of values of nodes in post-order.
    return postOrder(this->root);
}