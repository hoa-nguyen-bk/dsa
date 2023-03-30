#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

template <class K, class V>
class BinaryTree
{
public:
  class Node;

private:
  Node *root;

public:
  BinaryTree() : root(nullptr) {}
  ~BinaryTree()
  {
    // You have to delete all Nodes in BinaryTree. However in this task, you can ignore it.
  }

  class Node
  {
  private:
    K key;
    V value;
    Node *pLeft, *pRight;
    friend class BinaryTree<K, V>;

  public:
    Node(K key, V value) : key(key), value(value), pLeft(NULL), pRight(NULL) {}
    ~Node() {}
  };

  void addNode(string posFromRoot, K key, V value)
  {
    if (posFromRoot == "")
    {
      this->root = new Node(key, value);
      return;
    }

    Node *walker = this->root;
    int l = posFromRoot.length();
    for (int i = 0; i < l - 1; i++)
    {
      if (!walker)
        return;
      if (posFromRoot[i] == 'L')
        walker = walker->pLeft;
      if (posFromRoot[i] == 'R')
        walker = walker->pRight;
    }
    if (posFromRoot[l - 1] == 'L')
      walker->pLeft = new Node(key, value);
    if (posFromRoot[l - 1] == 'R')
      walker->pRight = new Node(key, value);
  }

  int countTwoChildrenNode(Node *node)
  {
    if (node == nullptr)
      return 0;
    int count = 0;
    if (node->pLeft != nullptr && node->pRight != nullptr)
      count++;
    count += countTwoChildrenNode(node->pLeft);
    count += countTwoChildrenNode(node->pRight);
    return count;
  }
  int countTwoChildrenNode()
  {
    return countTwoChildrenNode(this->root);
  }

  int recursiveHeight(Node *temp)
  {
    if (temp == nullptr)
      return 0;
    return max(recursiveHeight(temp->pLeft), recursiveHeight(temp->pRight)) + 1;
  }
  int getHeight()
  {
    // TODO: return height of the binary tree.
    return recursiveHeight(this->root);
  }

  // STUDENT ANSWER BEGIN
  // You can define other functions here to help you
  // Helping functions
  int recursiveSumOfLeafs(Node *node)
  {
    if (node == nullptr)
      return 0;
    if (node->pLeft == nullptr && node->pRight == nullptr)
      return node->value;
    return recursiveSumOfLeafs(node->pLeft) + recursiveSumOfLeafs(node->pRight);
  }
  int sumOfLeafs()
  {
    // TODO
    return recursiveSumOfLeafs(this->root);
  }

  // STUDENT ANSWER END
};

int main()
{
  BinaryTree<int, int> binaryTree;
  binaryTree.addNode("", 2, 4);
  cout << binaryTree.sumOfLeafs();
  // output:
  // 4
  BinaryTree<int, int> binaryTree2;
  binaryTree2.addNode("", 2, 4);
  binaryTree2.addNode("L", 3, 6);
  binaryTree2.addNode("R", 5, 9);
  cout << binaryTree2.sumOfLeafs();
  // output: 15
  return 0;
}
