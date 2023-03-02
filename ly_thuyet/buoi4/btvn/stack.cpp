#include <iostream>
using namespace std;

// stack với 4 chức năng
// pop
// push
// empty
// pop

template <class ItemType>
// struct thì struct vẫn dựa trên một cái node
struct Node
{
  ItemType data;
  Node<ItemType> *next;
  Node() : data(), next(nullptr) {} // default constructor
  Node(ItemType data) : data(data), next(nullptr) {}
};

template <class List_ItemType>
class Stack
{
private:
  // nhớ cho chỗ này head = null pointer
  Node<List_ItemType> *top;
  // biến đếm, phải có chứ
  int count;

public:
  Stack();
  ~Stack();
  // thêm 1 ptu mới vào mảng, giá trị user quyết định dĩ nhiên òi, nên là T data
  void push(List_ItemType dataIn);
  int pop(List_ItemType &dataOut);
  void print2console();
  bool isEmpty();
  int getSize();
  int getStackTop();
  void clear();
};

template <class List_ItemType>
void Stack<List_ItemType>::clear()
{
  Node<List_ItemType> *tmp;
  while (this->top->next != nullptr)
  {
    this->getStackTop();
    tmp = this->top;
    this->top = this->top->next;
    delete tmp;
  }
  this->count = 0;
}

template <class List_ItemType>
Stack<List_ItemType>::~Stack()
{
  this->clear();
}

template <class List_ItemType>
int Stack<List_ItemType>::getStackTop()
{
  if (this->isEmpty())
    return 0;
  cout << "this->top: " << this->top->data << " - " << this->top->next << endl;
  return 1;
}

template <class List_ItemType>
Stack<List_ItemType>::Stack()
{
  this->top = nullptr;
  this->count = 0;
}

template <class List_ItemType>
void Stack<List_ItemType>::push(List_ItemType dataIn)
{
  Node<List_ItemType> *newNode = new Node<List_ItemType>();
  newNode->data = dataIn;
  newNode->next = this->top;
  this->top = newNode;
  this->count++;
}

template <class List_ItemType>
bool Stack<List_ItemType>::isEmpty()
{
  return (count == 0);
}

template <class List_ItemType>
int Stack<List_ItemType>::getSize()
{
  return count;
}

template <class List_ItemType>
int Stack<List_ItemType>::pop(List_ItemType &dataOut)
{
  if (this->isEmpty())
  {
    return 0;
  }
  Node<List_ItemType> *deletePointer = this->top;
  dataOut = deletePointer->data;
  this->top = deletePointer->next;
  this->count--;
  delete deletePointer;
  return 1;
}

template <class List_ItemType>
void Stack<List_ItemType>::print2console()
{
  if (!this->isEmpty())
  {
    Node<List_ItemType> *tmp = new Node<List_ItemType>();
    tmp->next = this->top;
    while (tmp != nullptr)
    {
      cout << tmp->data << ": " << tmp->next << " -> ";
      tmp = tmp->next;
    }
    cout << endl;
  }
  else
  {
    cout << "empty stack" << endl;
  }
}

int main()
{
  Stack<int> *A = new Stack<int>();
  int val;
  A->isEmpty();
  A->push(5);
  A->push(5);
  A->push(5);
  A->push(5);
  A->push(2);
  A->print2console();
  A->pop(val);
  A->pop(val);
  A->pop(val);
  A->pop(val);
  A->push(3);
  A->getSize();
  A->print2console();
  A->getStackTop();
  delete A;
  A->print2console();
  return 0;
}