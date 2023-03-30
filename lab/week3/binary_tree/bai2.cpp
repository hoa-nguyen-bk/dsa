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
  // STUDENT ANSWER BEGIN
  // You can define other functions here to help you

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
  string recursivePreOrder(Node *temp)
  {
    if (temp == nullptr)
      return "";

    stringstream ss;
    ss << temp->value << " ";
    ss << recursivePreOrder(temp->pLeft);
    ss << recursivePreOrder(temp->pRight);
    return ss.str();
  }
  string preOrder()
  {
    // TODO: return the sequence of values of nodes in pre-order.
    return recursivePreOrder(this->root);
  }
  string recursiveInOrder(Node *temp)
  {
    if (temp == nullptr)
      return "";

    stringstream ss;
    ss << recursiveInOrder(temp->pLeft);
    ss << temp->value << " ";
    ss << recursiveInOrder(temp->pRight);
    return ss.str();
  }
  string inOrder()
  {
    // TODO: return the sequence of values of nodes in in-order.
    return recursiveInOrder(this->root);
  }
  string recursivePostOrder(Node *temp)
  {
    if (temp == nullptr)
      return "";

    stringstream ss;
    ss << recursivePostOrder(temp->pLeft);
    ss << recursivePostOrder(temp->pRight);
    ss << temp->value << " ";
    return ss.str();
  }
  string postOrder()
  {
    // TODO: return the sequence of values of nodes in post-order.
    return recursivePostOrder(this->root);
  }

  // STUDENT ANSWER END
};

int main()
{
  BinaryTree<int, int> binaryTree;
  binaryTree.addNode("", 2, 4);  // Add to root
  binaryTree.addNode("L", 3, 6); // Add to root's left node
  binaryTree.addNode("R", 5, 9); // Add to root's right node

  cout << binaryTree.getHeight() << endl;
  cout << binaryTree.preOrder() << endl;
  cout << binaryTree.inOrder() << endl;
  cout << binaryTree.postOrder() << endl;
  // output:
  // 2
  // 4 6 9 là preOrder
  // 6 4 9
  // 6 9 4
  return 0;
}
