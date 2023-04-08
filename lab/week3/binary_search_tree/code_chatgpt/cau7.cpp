int kthSmallest(BSTNode* root, int k) {
    // Create an empty stack and push the root node
    stack<BSTNode*> s;
    BSTNode* curr = root;
    int count = 0;
    
    while (curr != nullptr || !s.empty()) {
        // Traverse the left subtree and push all nodes onto the stack
        while (curr != nullptr) {
            s.push(curr);
            curr = curr->left;
        }
        
        // Pop the top node from the stack and increment the count
        curr = s.top();
        s.pop();
        count++;
        
        // Check if we have found the k-th smallest element
        if (count == k) {
            return curr->val;
        }
        
        // Traverse the right subtree
        curr = curr->right;
    }
    
    // If we reach here, k is greater than the number of nodes in the tree
    return INT_MAX;
}
