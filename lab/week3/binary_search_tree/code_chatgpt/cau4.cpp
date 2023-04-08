vector<int> levelAlterTraverse(BSTNode* root) {
    vector<int> result;
    if (root == nullptr) {
        return result;
    }
    queue<BSTNode*> q;
    q.push(root);
    bool leftToRight = true;
    while (!q.empty()) {
        int levelSize = q.size();
        stack<int> s;
        for (int i = 0; i < levelSize; i++) {
            BSTNode* node = q.front();
            q.pop();
            if (leftToRight) {
                result.push_back(node->val);
            } else {
                s.push(node->val);
            }
            if (node->left != nullptr) {
                q.push(node->left);
            }
            if (node->right != nullptr) {
                q.push(node->right);
            }
        }
        leftToRight = !leftToRight;
        while (!s.empty()) {
            result.push_back(s.top());
            s.pop();
        }
    }
    return result;
}
