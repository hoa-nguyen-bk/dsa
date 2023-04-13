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
  void printScreen(string str)
  {
    if (isTest)
    {
      cout << str << endl;
    }
  }
  void printScreen(string str, T number)
  {
    if (isTest)
    {
      cout << str << " = " << number << endl;
    }
  }

  Node *rotateLeft(Node *&childRoot)
  {
    if (childRoot == nullptr)
    {
      return childRoot;
    }
    Node *tempPtr = childRoot->pRight;
    childRoot->pRight = tempPtr->pLeft;
    tempPtr->pLeft = childRoot;
    return tempPtr;
  }
  Node *rotateRight(Node *&childRoot)
  {
    if (childRoot == nullptr)
      return childRoot;
    Node *tempPtr = childRoot->pLeft;
    childRoot->pLeft = tempPtr->pRight;
    tempPtr->pRight = childRoot;
    return tempPtr;
  }

  Node *rightBalance(Node *&temp, bool &taller)
  {
    Node *rightTree = temp->pRight;
    // Case 1: right of right. Single rotation left
    if (rightTree->balance == RH)
    {
      temp = rotateLeft(temp);
      temp->balance = EH;
      rightTree->balance = EH;
      taller = false;
    }
    else
    {
      Node *leftTree = rightTree->pLeft;
      if (leftTree->balance == RH)
      {
        temp->balance = LH;
        rightTree->balance = EH;
      }
      else if (leftTree->balance == EH)
      {
        rightTree->balance = EH;
      }
      else
      {
        temp->balance = EH;
        rightTree->balance = RH;
      }
      leftTree->balance = EH;
      temp->pRight = rotateRight(rightTree);
      temp = rotateLeft(temp);
      taller = false;
    }
    return temp;
  }
  Node *leftBalance(Node *&temp, bool &taller)
  {
    Node *leftTree = temp->pLeft;
    // case 1: left of left. single rotation right
    if (leftTree->balance == LH)
    {
      temp = rotateRight(temp);
      temp->balance = EH;
      leftTree->balance = EH;
      taller = false;
    }
    // case 2: right of left. Double rotation required
    else
    {
      Node *rightTree = leftTree->pRight;
      if (rightTree->balance == LH)
      {
        temp->balance = RH;
        leftTree->balance = EH;
      }
      else if (rightTree->balance == EH)
      {
        leftTree->balance = EH;
      }
      else
      {
        temp->balance = EH;
        leftTree->balance = LH;
      }
      rightTree->balance = EH;
      temp->pLeft = rotateLeft(leftTree);
      temp = rotateRight(temp);
      taller = false;
    }
    return temp;
  }
  Node *AVLInsert(Node *&childRoot, const T &data, bool &taller)
  {
    // pLeft, pRight, data
    // **return: tree get higher?
    if (childRoot == NULL)
    {
      // printScreen("childRoot == NULL");
      childRoot = new Node(data);
      taller = true;
      return childRoot;
    }
    else if (data < childRoot->data)
    {
      // printScreen("data < childRoot->data");
      childRoot->pLeft = AVLInsert(childRoot->pLeft, data, taller);
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
      // printScreen("data >= childRoot->data");
      childRoot->pRight = AVLInsert(childRoot->pRight, data, taller);
      if (taller)
      {
        if (childRoot->balance == LH)
        {
          childRoot->balance = EH;
          taller = false;
        }
        else if (childRoot->balance == EH)
          childRoot->balance = RH;
        else
          childRoot = rightBalance(childRoot, taller);
      }
    }
    return childRoot;
  }
  void insert(const T &value)
  {
    // TODO
    bool taller = false;
    // printScreen("value", value);
    AVLInsert(this->root, value, taller);
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
  for (int i = 0; i < 9; i++)
  {
    avl.insert(i);
  }
  avl.printTreeStructure();
  //        3
  //    1       5
  //  0   2   4   7
  //             6 8
  return 0;
}
