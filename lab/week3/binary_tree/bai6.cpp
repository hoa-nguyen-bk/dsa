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
};
int main()
{
  return 0;
}
