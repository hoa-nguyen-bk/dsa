BSTNode* subtreeWithRange(BSTNode* root, int lo, int hi) {
    if (root == nullptr) {
        return nullptr;
    }
    if (root->val < lo) {
        return subtreeWithRange(root->right, lo, hi);
    }
    if (root->val > hi) {
        return subtreeWithRange(root->left, lo, hi);
    }
    root->left = subtreeWithRange(root->left, lo, hi);
    root->right = subtreeWithRange(root->right, lo, hi);
    return root;
}
