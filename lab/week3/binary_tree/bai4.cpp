#include <iostream>

using namespace std;
class BTNode
{
public:
  int val;
  BTNode *left;
  BTNode *right;
  BTNode()
  {
    this->left = this->right = NULL;
  }
  BTNode(int val)
  {
    this->val = val;
    this->left = this->right = NULL;
  }
  BTNode(int val, BTNode *&left, BTNode *&right)
  {
    this->val = val;
    this->left = left;
    this->right = right;
  };
};
void recursiveSumDigitPath(BTNode *node, int currentSum, int &totalSum)
{
  if (node == nullptr)
    return;
  currentSum = (currentSum * 10 + node->val) % 27022001;
  cout << "currentSum = " << currentSum << endl;
  if (node->left == nullptr && node->right == nullptr)
  {
    totalSum = (totalSum + currentSum) % 27022001;
    return;
  }
  recursiveSumDigitPath(node->left, currentSum, totalSum);
  recursiveSumDigitPath(node->right, currentSum, totalSum);
}
int sumDigitPath(BTNode *root)
{
  int totalSum = 0;
  recursiveSumDigitPath(root, 0, totalSum);
  return totalSum;
}
int main()
{
  int arr[] = {-1, 0, 0, 2, 2};
  int value[] = {3, 5, 2, 1, 4};
  BTNode *root = BTNode::createTree(arr, arr + sizeof(arr) / sizeof(int), value);
  cout << sumDigitPath(root);
  // output: 680
  return 0;
}
