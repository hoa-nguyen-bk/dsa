int singleChild(BSTNode* root) {
    if (!root) {
        return 0;
    }
    int count = 0;
    if (root->left && !root->right) {
        count++;
    }
    if (root->right && !root->left) {
        count++;
    }
    return count + singleChild(root->left) + singleChild(root->right);
}
