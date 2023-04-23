#include <iostream>

using namespace std;
class Node
{
  int data;
  Node *left;
  Node *right;

public:
  Node() : data(0), left(nullptr), right(nullptr) {}

  Node(int data, Node *left, Node *right)
  {
    this->data = data;
    this->left = left;
    this->right = right;
  }

  int getData()
  {
    return this->data;
  }

  void setData(int data)
  {
    this->data = data;
  }

  Node *getLeft()
  {
    return this->left;
  }

  void setLeft(Node *left)
  {
    this->left = left;
  }

  Node *getRight()
  {
    return this->right;
  }

  void setRight(Node *right)
  {
    this->right = right;
  }
};

void countInRangeRec(Node *root, int lowerbound, int upperbound, int &result)
{
  if (root == nullptr)
    return;
  if (root->getData() > lowerbound && root->getData() < upperbound)
  {
    result++;
  }
  cout << "result = " << result << endl;
  countInRangeRec(root->getLeft(), lowerbound, upperbound, result);
  countInRangeRec(root->getRight(), lowerbound, upperbound, result);
}

// Ham phu viet o day
int countInRange(Node *root, int lowerbound, int upperbound)
{
  // TODO
  if (root == nullptr)
    return 0;
  if (root->getData() >= upperbound)
    return 0 + countInRange(root->getLeft(), lowerbound, upperbound);
  if (root->getData() <= lowerbound)
    return 0 + countInRange(root->getRight(), lowerbound, upperbound);
  return 1 + countInRange(root->getLeft(), lowerbound, upperbound) + countInRange(root->getRight(), lowerbound, upperbound);
}
int main()
{
  Node *node1 = new Node(5, nullptr, nullptr);
  Node *node2 = new Node(15, nullptr, nullptr);
  Node *root = new Node(7, node1, node2);
  cout << countInRange(root, 2, 8);

  return 0;
}
