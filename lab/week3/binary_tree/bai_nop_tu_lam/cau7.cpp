int lowestAncestor(BTNode* root, int a, int b) {
if (root == NULL) {
return -1;
}// If either of the two nodes is the root node, return the root node.
if (root->val == a || root->val == b) {
    return root->val;
}

// Recursively search for the two nodes in the left and right subtrees of the root node.
int left = lowestAncestor(root->left, a, b);
int right = lowestAncestor(root->right, a, b);

// If both nodes are found in different subtrees of the root node, return the root node as the lowest common ancestor.
if (left != -1 && right != -1) {
    return root->val;
}

// If both nodes are found in the same subtree of the root node, recursively search for the lowest common ancestor in that subtree.
if (left != -1) {
    return left;
} else {
    return right;
}

}