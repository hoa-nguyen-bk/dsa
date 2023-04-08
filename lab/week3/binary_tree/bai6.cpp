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
  }
  static BTNode *createTreeHelper(int arr[], int n, int value[], int &i)
  {
    if (i >= n || arr[i] == -1)
    {
      i++;
      return nullptr;
    }

    BTNode *node = new BTNode(value[i]);
    i++;

    node->left = createTreeHelper(arr, n, value, i);
    node->right = createTreeHelper(arr, n, value, i);

    return node;
  }

  static BTNode *createTree(int *arr, int *end, int *values)
  {
    if (arr == end)
    {
      return NULL;
    }
    int *mid = arr + (end - arr) / 2;
    BTNode *root = new BTNode(*values);
    root->left = createTree(arr, mid, values + 1);
    root->right = createTree(mid + 1, end, values + 1 + (mid - arr));
    return root;
  }
};
void longestPathSum(BTNode *root, int &sum, int len)
{
  if (root == NULL)
  {
    sum = len = 0;
  }
  else
  {
    int sumL, lenL, sumR, lenR;
    longestPathSum(root->left, sumL, lenL);
    longestPathSum(root->right, sumR, lenR);

    if (lenL > lenR)
    {
      sum = sumL + root->val;
      len = lenL + 1;
    }
    else if (lenL < lenR)
    {
      sum = sumR + root->val;
      len = lenR + 1;
    }
    else
    {
      sum = max(sumL, sumR) + root->val;
      len = lenL + 1;
    }
  }
}

int longestPathSum(BTNode *root)
{
  int sum, len;
  longestPathSum(root, sum, len);
  return sum;
}
int main()
{
  int arr[] = {-1, 0, 0, 2, 2, 3, 3, 5};
  int value[] = {1, 5, 4, 7, 12, 4, 8, 2};
  BTNode *root = BTNode::createTree(arr, arr + sizeof(arr) / sizeof(int), value);
  cout << longestPathSum(root);
  //18
  return 0;
}
