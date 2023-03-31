#include <iostream>
#include <string>
#include <sstream>

using namespace std;

#define SEPARATOR "#<ab@17943918#@>#"

template <class T>
class BinarySearchTree
{
public:
  class Node;

private:
  Node *root;

public:
  BinarySearchTree() : root(nullptr) {}
  ~BinarySearchTree()
  {
    // You have to delete all Nodes in BinaryTree. However in this task, you can ignore it.
  }

  // Helping function
  void add(T value)
  {
    root = addRec(root, value);
  }

  Node *addRec(Node *node, T value)
  {
    if (node == nullptr)
    {
      node = new Node(value);
    }
    else if (value <= node->value)
    {
      node->pLeft = addRec(node->pLeft, value);
    }
    else
    {
      node->pRight = addRec(node->pRight, value);
    }
    return node;
  }

  void deleteNode(T value)
  {
    root = deleteRec(root, value);
  }

  Node *deleteRec(Node *node, T value)
  {
    if (node == nullptr)
    {
      return nullptr;
    }
    if (value < node->value)
    {
      node->pLeft = deleteRec(node->pLeft, value);
    }
    else if (value > node->value)
    {
      node->pRight = deleteRec(node->pRight, value);
    }
    else
    {
      // Case 1: No child or one child
      if (node->pLeft == nullptr)
      {
        Node *temp = node->pRight;
        delete node;
        return temp;
      }
      else if (node->pRight == nullptr)
      {
        Node *temp = node->pLeft;
        delete node;
        return temp;
      }

      // Case 2: Two children
      Node *temp = minValueNode(node->pRight);
      node->value = temp->value;
      node->pRight = deleteRec(node->pRight, temp->value);
    }
    return node;
  }

  Node *minValueNode(Node *node)
  {
    Node *current = node;
    while (current->pLeft != nullptr)
    {
      current = current->pLeft;
    }
    return current;
  }

  string inOrder()
  {
    stringstream ss;
    inOrderRec(root, ss);
    return ss.str();
  }

  void inOrderRec(Node *node, stringstream &ss)
  {
    if (node != nullptr)
    {
      inOrderRec(node->pLeft, ss);
      ss << node->value << " ";
      inOrderRec(node->pRight, ss);
    }
  }

public:
  class Node
  {
  private:
    T value;
    Node *pLeft, *pRight;
    friend class BinarySearchTree<T>;

  public:
    Node(T value) : value(value), pLeft(nullptr), pRight(nullptr) {}
    ~Node() {}
  };
};

int main()
{
  BinarySearchTree<int> bst;
  bst.add(9);
  bst.add(2);
  bst.add(10);
  bst.deleteNode(9);
  cout << bst.inOrder();
  return 0;
}
