
void sumDigitPathHelper(BTNode *node, int currentSum, int &totalSum)
{
  if (node == nullptr)
    return;
  currentSum = (currentSum * 10 + node->val) % 27022001;
  if (node->left == nullptr && node->right == nullptr)
  {
    totalSum = (totalSum + currentSum) % 27022001;
    return;
  }
  sumDigitPathHelper(node->left, currentSum, totalSum);
  sumDigitPathHelper(node->right, currentSum, totalSum);
}

int sumDigitPath(BTNode *root)
{
  int totalSum = 0;
  sumDigitPathHelper(root, 0, totalSum);
  return totalSum;
}