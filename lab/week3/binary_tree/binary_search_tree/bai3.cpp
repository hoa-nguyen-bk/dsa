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
    cout << "(" << root->value << ")" << endl;

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

  T getMin()
  {
    if (root == nullptr)
    {
      throw runtime_error("Tree is empty");
    }
    Node *current = root;
    T min = root->value;
    while (current->pLeft != nullptr)
    {
      current = current->pLeft;
      if (min > current->value)
      {
        min = current->value;
      }
    }
    return current->value;
  }

  T getMax()
  {
    if (root == nullptr)
    {
      throw runtime_error("Tree is empty");
    }
    Node *current = root;
    T max = root->value;
    while (current->pRight != nullptr)
    {
      current = current->pRight;
      if (max < current->value)
      {
        max = current->value;
      }
    }
    return max;
  }

  // STUDENT ANSWER BEGIN
  // You can define other functions here to help you.
  bool recursiveFind(Node *temp, T i)
  {
    if (temp == nullptr)
      return false;
    else if (i < temp->value)
      recursiveFind(temp->pLeft, i);
    else if (i > temp->value)
      recursiveFind(temp->pRight, i);
    else
      return true;
  }
  bool find(T i)
  {
    // TODO: return true if value i is in the tree; otherwise, return false.
    Node *temp = this->root;
    return recursiveFind(temp, i);
  }

  T sum(T l, T r)
  {
    return sumRec(root, l, r);
  }

  T sumRec(Node *node, T l, T r)
  {
    if (node == nullptr)
    {
      return 0;
    }

    T result = 0;

    if (node->value >= l && node->value <= r)
    {
      result += node->value;
    }

    if (node->value > l)
    {
      result += sumRec(node->pLeft, l, r);
    }

    if (node->value < r)
    {
      result += sumRec(node->pRight, l, r);
    }

    return result;
  }

  // STUDENT ANSWER END
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
  for (int i = 0; i < 10; ++i)
  {
    bst.add(i);
  }
  cout << bst.find(7) << endl;
  cout << bst.sum(0, 4) << endl;
  // 1
  // 10
  return 0;
}
