#include <iostream>
#include <math.h>
#include <queue>
using namespace std;
#define isTest true
#define SEPARATOR "#<ab@17943918#@>#"

enum BalanceValue
{
  LH = -1,
  EH = 0,
  RH = 1
};

void printNSpace(int n)
{
  for (int i = 0; i < n - 1; i++)
    cout << " ";
}

void printInteger(int &n)
{
  cout << n << " ";
}

template <class T>
class AVLTree
{
public:
  class Node;

private:
  Node *root;

protected:
  int getHeightRec(Node *node)
  {
    if (node == NULL)
      return 0;
    int lh = this->getHeightRec(node->pLeft);
    int rh = this->getHeightRec(node->pRight);
    return (lh > rh ? lh : rh) + 1;
  }

public:
  AVLTree() : root(nullptr) {}
  ~AVLTree() {}
  int getHeight()
  {
    return this->getHeightRec(this->root);
  }
  void printTreeStructure()
  {
    int height = this->getHeight();
    if (this->root == NULL)
    {
      cout << "NULL\n";
      return;
    }
    queue<Node *> q;
    q.push(root);
    Node *temp;
    int count = 0;
    int maxNode = 1;
    int level = 0;
    int space = pow(2, height);
    printNSpace(space / 2);
    while (!q.empty())
    {
      temp = q.front();
      q.pop();
      if (temp == NULL)
      {
        cout << " ";
        q.push(NULL);
        q.push(NULL);
      }
      else
      {
        cout << temp->data;
        q.push(temp->pLeft);
        q.push(temp->pRight);
      }
      printNSpace(space);
      count++;
      if (count == maxNode)
      {
        cout << endl;
        count = 0;
        maxNode *= 2;
        level++;
        space /= 2;
        printNSpace(space / 2);
      }
      if (level == height)
        return;
    }
  }

  // Helping functions
  void print(string str)
  {
    if (isTest)
      cout << str << endl;
  }
  void print(string str, T number)
  {
    if (isTest)
      cout << str << " = " << number << endl;
  }
  void print(T number2, string str, T number)
  {
    if (isTest)
      cout << number2 << " = " << str << " = " << number << endl;
  }

  Node *rotateLeft(Node *&childRoot)
  {
    print("rotate Left");

    if (childRoot == nullptr)
      return childRoot;
    Node *tempPtr = childRoot->pRight;
    childRoot->pRight = tempPtr->pLeft;
    tempPtr->pLeft = childRoot;
    return tempPtr;
  }
  Node *rotateRight(Node *&childRoot)
  {
    print("rotate Right");
    if (childRoot == nullptr)
      return childRoot;
    Node *tempPtr = childRoot->pLeft;
    childRoot->pLeft = tempPtr->pRight;
    tempPtr->pRight = childRoot;
    return tempPtr;
  }

  Node *rightBalance(Node *&childRoot, bool &taller)
  {
    print("rightBalance");
    Node *rightTree = childRoot->pRight;
    // Case 1: right of right. Single rotation left
    if (rightTree->balance == RH)
    {
      print("rightTree->balance == RH, case 1: RoR. Single rotation left");
      childRoot = rotateLeft(childRoot);
      childRoot->balance = EH;
      rightTree->balance = EH;
      taller = false;
    }
    else
    {
      print("rightTree->balance != RH, case 2: LoR");
      this->printTreeStructure();
      if (rightTree->pLeft == nullptr)
      {
        return childRoot;
      }
      Node *leftTree = rightTree->pLeft;
      if (leftTree->balance == RH)
      {
        childRoot->balance = LH;
        rightTree->balance = EH;
      }
      else if (leftTree->balance == EH)
        rightTree->balance = EH;
      else
      {
        childRoot->balance = EH;
        rightTree->balance = RH;
      }
      leftTree->balance = EH;
      print("leftTree->balance", leftTree->balance);
      childRoot->pRight = rotateRight(rightTree);
      childRoot = rotateLeft(childRoot);
      taller = false;
    }
    return childRoot;
  }
  Node *leftBalance(Node *&childRoot, bool &taller)
  {
    print("left Balance");
    Node *leftTree = childRoot->pLeft;
    // case 1: left of left. single rotation right
    if (leftTree->balance == LH)
    {
      childRoot = rotateRight(childRoot);
      childRoot->balance = EH;
      leftTree->balance = EH;
      taller = false;
    }
    // case 2: right of left. Double rotation required
    else
    {
      if (leftTree->pRight == nullptr)
      {
        return childRoot;
      }
      Node *rightTree = leftTree->pRight;
      if (rightTree->balance == LH)
      {
        childRoot->balance = RH;
        leftTree->balance = EH;
      }
      else if (rightTree->balance == EH)
        leftTree->balance = EH;
      else
      {
        childRoot->balance = EH;
        leftTree->balance = LH;
      }
      rightTree->balance = EH;
      childRoot->pLeft = rotateLeft(leftTree);
      childRoot = rotateRight(childRoot);
      taller = false;
    }
    return childRoot;
  }
  Node *AVLInsert(Node *&childRoot, const T &data, bool &taller)
  {
    // pLeft, pRight, data
    // **return: tree get higher?
    if (childRoot == NULL)
    {
      print("childRoot == NULL");
      Node *newNode = new Node(data);
      childRoot = newNode;
      taller = true;
      return childRoot;
    }
    else if (data < childRoot->data)
    {
      print("data < childRoot->data", childRoot->data);
      childRoot->pLeft = AVLInsert(childRoot->pLeft, data, taller);
      print("after call AVLInsert childRoot->pLeft");
      if (data == 32)
      {
        print("childRoot->pLeft->data", childRoot->data);
      }
      // left subtree is taller
      if (taller)
      {
        if (childRoot->balance == LH)
          childRoot = leftBalance(childRoot, taller);
        else if (childRoot->balance == EH)
          childRoot->balance = LH;
        else
        {
          childRoot->balance = EH;
          taller = false;
        }
      }
    }
    else
    {
      print("data >= childRoot->data", childRoot->data);
      childRoot->pRight = AVLInsert(childRoot->pRight, data, taller);
      print("after call AVLInsert childRoot->pRight");
      if (taller)
      {
        if (childRoot->balance == LH)
        {
          print("childRoot->balance == LH");
          childRoot->balance = EH;
          taller = false;
        }
        else if (childRoot->balance == EH)
        {
          print("childRoot->balance == EH");
          childRoot->balance = RH;
        }
        else
        {
          print("childRoot->balance == RH");
          childRoot = rightBalance(childRoot, taller);
        }
      }
    }
    return childRoot;
  }
  void insert(const T &value)
  {
    // TODO
    bool taller = false;
    print("value", value);
    AVLInsert(this->root, value, taller);
    print("------------ print tree --------taller", taller);
    this->printTreeStructure();
    print("------------ print tree -------------");
  }
  // XONG bài 1

  // Helping functions
  Node *deleteRightBalance(Node *&root, bool shorter)
  {
    if (root->balance == LH)
    {
      root->balance = EH;
    }
    else if (root->balance == EH)
    {
      root->balance = RH;
      shorter = false;
    }
    else
    {
      Node *rightTree = root->pRight;
      if (rightTree->balance == LH)
      {
        Node *leftTree = rightTree->pLeft;
        if (leftTree->balance == LH)
        {
          rightTree->balance = RH;
          root->balance = EH;
        }
        else if (leftTree->balance == EH)
        {
          root->balance = LH;
          rightTree->balance = EH;
        }
        else
        {
          root->balance = LH;
          rightTree->balance = EH;
        }
        leftTree->balance = EH;
        root->pRight = rotateRight(rightTree);
        root = rotateLeft(root);
      }
      else
      {
        if (rightTree->balance != EH)
        {
          root->balance = EH;
          rightTree->balance = EH;
          shorter = false;
        }
        root = rotateLeft(root);
      }
    }
    return root;
  }
  Node *deleteLeftBalance(Node *&root, bool &shorter)
  {
    if (root->balance == RH)
    {
      root->balance = EH;
    }
    else if (root->balance == EH)
    {
      root->balance = LH;
      shorter = false;
    }
    else
    {
      Node *leftTree = root->pLeft;
      if (leftTree->balance == RH)
      {
        Node *rightTree = leftTree->pRight;
        if (rightTree->balance == RH)
        {
          leftTree->balance = LH;
          root->balance = EH;
        }
        else if (rightTree->balance == EH)
        {
          root->balance = RH;
          leftTree->balance = EH;
        }
        else
        {
          root->balance = RH;
          leftTree->balance = EH;
        }
        rightTree->balance = EH;
        root->pLeft = rotateLeft(leftTree);
        root = rotateRight(root);
      }
      else
      {
        if (leftTree->balance != EH)
        {
          root->balance = EH;
          leftTree->balance = EH;
        }
        else
        {
          root->balance = LH;
          leftTree->balance = RH;
          shorter = false;
        }
        root = rotateRight(root);
      }
    }
    return root;
  }
  Node *AVLDelete(Node *&root, const T &deleteKey, bool &shorter, bool &success)
  {
    if (root == nullptr)
    {
      shorter = false;
      success = false;
      return nullptr;
    }
    else if (deleteKey < root->data)
    {
      root->pLeft = AVLDelete(root->pLeft, deleteKey, shorter, success);
      if (shorter)
        root = deleteRightBalance(root, shorter);
    }
    else if (deleteKey > root->data)
    {
      root->pRight = AVLDelete(root->pRight, deleteKey, shorter, success);
      if (shorter)
      {
        root = deleteLeftBalance(root, shorter);
      }
    }
    else
    {
      Node *deleteNode = root;
      if (root->pRight == nullptr)
      {
        Node *newRoot = root->pLeft;
        success = true;
        shorter = true;
        delete deleteNode;
        return newRoot;
      }
      else if (root->pLeft == nullptr)
      {
        Node *newRoot = root->pRight;
        success = true;
        shorter = true;
        delete deleteNode;
        return newRoot;
      }
      // if delete node has two subtrees
      else
      {
        Node *exchPtr = root->pLeft;
        while (exchPtr->pRight != nullptr)
        {
          exchPtr = exchPtr->pRight;
        }
        root->data = exchPtr->data;
        root->pLeft = AVLDelete(root->pLeft, exchPtr->data, shorter, success);
        if (shorter)
        {
          root = deleteRightBalance(root, shorter);
        }
      }
    }
    return root;
  }
  void remove(const T &value)
  {
    // TODO
    // shorter is true if subtree is shorter
    bool shorter = false;
    // success is true if deleted, false if not found
    bool success = false;
    AVLDelete(this->root, value, shorter, success);
  }

  class Node
  {
  private:
    T data;
    Node *pLeft, *pRight;
    BalanceValue balance;
    friend class AVLTree<T>;

  public:
    Node(T value) : data(value), pLeft(NULL), pRight(NULL), balance(EH) {}
    ~Node() {}
  };
};
int main()
{
  AVLTree<int> avl;
  int arr[] = {10, 52, 98, 32, 68, 92, 40, 13, 42, 63};
  for (int i = 0; i < 10; i++)
  {
    avl.insert(arr[i]);
  }

  avl.remove(10);
  avl.printTreeStructure();
  //        52
  //    32       92
  //  13   40   68   98
  //       42 63
  avl.print("success");
  return 0;
}
