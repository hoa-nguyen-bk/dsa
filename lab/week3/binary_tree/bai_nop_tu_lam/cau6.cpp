void longestPathSum(BTNode* root, int & sum, int len) {
    if (root == NULL) {
        sum = len = 0;
    }
    else {
        int sumL, lenL, sumR, lenR;
        longestPathSum(root->left, sumL, lenL);
        longestPathSum(root->right, sumR, lenR);

        if (lenL > lenR) {
            sum = sumL + root->val;
            len = lenL + 1;
        }
        else if (lenL < lenR) {
            sum = sumR + root->val;
            len = lenR + 1;
        }
        else {
            sum = max(sumL, sumR) + root->val;
            len = lenL + 1;
        }
    }
} 

int longestPathSum(BTNode* root) {
    int sum, len;
    longestPathSum(root, sum, len);
    return sum;
}