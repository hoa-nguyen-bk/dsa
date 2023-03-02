#include <iostream>
using namespace std;

// queue với 4 chức năng
// enqueue
// dequeue
// front
// empty

template <class ItemType>
struct Node
{
  ItemType data;
  Node<ItemType> *next;
  Node() : data(), next(nullptr) {}
  Node(ItemType dataIn) : data(dataIn), next(nullptr) {}
};

template <class List_ItemType>
class Queue
{
private:
  int count;
  Node<List_ItemType> *front = nullptr;
  Node<List_ItemType> *rear = nullptr;

public:
  Queue();
  ~Queue();
  void clear();
  void enqueue(List_ItemType dataIn);
  int dequeue(List_ItemType &dataOut);
  void print2console();
  void getFront();
};

template <class Lit>
void Queue<Lit>::getFront()
{
  if (!this->count == 0)
  {
    cout << "front = " << this->front->data << ": " << this->front->next << endl;
  }
}

template <class Lit>
void Queue<Lit>::print2console()
{
  if (!this->count == 0)
  {
    Node<Lit> *tmp = new Node<Lit>();
    int i = 0;
    tmp->next = this->front;
    while (tmp != nullptr)
    {
      cout << "[" << i << "] = " << tmp->data << ": " << tmp->next << endl;
      tmp = tmp->next;
      i++;
    }
  }
}

template <class Lit>
int Queue<Lit>::dequeue(Lit &dataOut)
{
  if (this->count == 0)
  {
    return 0;
  }
  Node<Lit> *delelePointer = new Node<Lit>();
  delelePointer = this->front;
  dataOut = delelePointer->data;
  if (this->count == 1)
  {
    this->rear = nullptr;
    this->front = nullptr;
  }
  else
  {
    this->front = this->front->next;
  }
  this->count--;
  delete delelePointer;
  return 1;
}

template <class Lit>
void Queue<Lit>::enqueue(Lit dataIn)
{
  Node<Lit> *newPointer = new Node<Lit>();
  newPointer->data = dataIn;
  if (this->count == 0)
  {
    this->front = newPointer;
  }
  else
  {
    this->rear->next = newPointer;
  }
  this->rear = newPointer;
  this->count++;
}

template <class Lit>
Queue<Lit>::Queue()
{
  this->count = 0;
  this->front = nullptr;
  this->rear = nullptr;
}

template <class Lit>
Queue<Lit>::~Queue()
{
  this->clear();
}

template <class Lit>
void Queue<Lit>::clear()
{
}

int main()
{
  Queue<int> *a = new Queue<int>();
  int val;
  a->enqueue(1);
  a->enqueue(2);
  a->enqueue(3);
  a->enqueue(4);
  a->print2console();
  a->dequeue(val);
  a->print2console();
  a->getFront();
  return 0;
}