#include <iostream>
using namespace std;
template <class T>
class SLinkedList
{
public:
  class Node; // Forward declaration
protected:
  Node *head;
  Node *tail;
  int count;

public:
  SLinkedList();
  ~SLinkedList();
  void add(const T &e);
  void add(int index, const T &e);
  int size();
  int *toString()
  {
    Node *tmp = head;
    // nếu mà viết tmp->next thế này thì nó còn lâu mới đụng zô được thằng cuối cùng. Nên là phải dùng tmp != null pointer thôi.
    cout << "[";
    while (tmp != nullptr)
    {
      cout << tmp->data << ", ";
      tmp = tmp->next;
    }
    cout << "]" << endl;

    return 0;
  }

public:
  class Node
  {
  private:
    T data;
    Node *next;
    friend class SLinkedList<T>;

  public:
    Node()
    {
      next = 0;
    }
    Node(Node *next)
    {
      this->next = next;
    }
    Node(T data, Node *next)
    {
      this->data = data;
      this->next = next;
    }
  };
};

template <class T>
SLinkedList<T>::SLinkedList()
{
  head = nullptr;
  tail = nullptr;
  count = 0;
}

template <class T>
SLinkedList<T>::~SLinkedList()
{
  Node *current = head;
  while (current != nullptr)
  {
    Node *next = current->next;
    delete current;
    current = next;
  }
  head = nullptr;
  tail = nullptr;
  count = 0;
}

template <class T>
void SLinkedList<T>::add(const T &e)
{
  /* Insert an element into the end of the list */
  Node *newElement = new Node(e, nullptr);
  if (this->head == nullptr)
  {
    this->head = newElement;
    this->tail = newElement;
  }
  else
  {
    this->tail->next = newElement;
    this->tail = newElement;
  }
  this->count++;
}

template <class T>
void SLinkedList<T>::add(int index, const T &e)
{
  /* Insert an element into the list at given index */
  if (index < 0 || index > this->count)
  {
    cout << "Index out of range" << endl;
    return;
  }
  Node *newElement = new Node(e, nullptr);
  if (index == 0)
  {
    newElement->next = this->head;
    this->head = newElement;
  }
  else
  {
    Node *current = this->head;
    for (int i = 0; i < index - 1; i++)
    {
      current = current->next;
    }
    newElement->next = current->next;
    current->next = newElement;
  }
  this->count++;
}

template <class T>
int SLinkedList<T>::size()
{
  /* Return the length (size) of list */
  return this->count;
}

int main()
{
  SLinkedList<int> list;
  int size = 10;

  for (int index = 0; index < size; index++)
  {
    list.add(0, index);
  }

  cout << list.toString();
  // [9,8,7,6,5,4,3,2,1,0]
  return 0;
}
