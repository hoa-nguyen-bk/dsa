//Helping functions
int getHeight(Node* node) {
    if (node == nullptr) return 0;
    return 1 + max(getHeight(node->pLeft), getHeight(node->pRight));
}

int getHeight() {
    return getHeight(root);
}

void preOrder(Node* node, stringstream& ss) {
    if (node == nullptr) return;
    ss << node->value << " ";
    preOrder(node->pLeft, ss);
    preOrder(node->pRight, ss);
}

string preOrder() {
    stringstream ss;
    preOrder(root, ss);
    return ss.str();
}

void inOrder(Node* node, stringstream& ss) {
    if (node == nullptr) return;
    inOrder(node->pLeft, ss);
    ss << node->value << " ";
    inOrder(node->pRight, ss);
}

string inOrder() {
    stringstream ss;
    inOrder(root, ss);
    return ss.str();
}

void postOrder(Node* node, stringstream& ss) {
    if (node == nullptr) return;
    postOrder(node->pLeft, ss);
    postOrder(node->pRight, ss);
    ss << node->value << " ";
}

string postOrder() {
    stringstream ss;
    postOrder(root, ss);
    return ss.str();
}
int sumOfLeafs(Node* node) {
    if (node == nullptr) return 0;
    if (node->pLeft == nullptr && node->pRight == nullptr) return node->value;
    return sumOfLeafs(node->pLeft) + sumOfLeafs(node->pRight);
}

int sumOfLeafs() {
    return sumOfLeafs(root);
}