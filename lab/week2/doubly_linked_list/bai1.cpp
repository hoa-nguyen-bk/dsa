#include <iostream>
#include <iomanip>
using namespace std;
template <class T>
class DLinkedList
{
public:
  class Node; // Forward declaration
protected:
  Node *head;
  Node *tail;
  int count;

public:
  DLinkedList();
  ~DLinkedList();
  void add(const T &e);
  void add(int index, const T &e);
  int size();
  int *toString();
  void toNodeString();

public:
  class Node
  {
  private:
    T data;
    Node *next;
    Node *previous;
    friend class DLinkedList<T>;

  public:
    Node()
    {
      this->previous = NULL;
      this->next = NULL;
    }

    Node(const T &data)
    {
      this->data = data;
      this->previous = NULL;
      this->next = NULL;
    }
  };
};

template <class T>
DLinkedList<T>::DLinkedList()
{
  this->head = nullptr;
  this->tail = nullptr;
  this->count = 0;
}

template <class T>
DLinkedList<T>::~DLinkedList()
{
}

template <class T>
int *DLinkedList<T>::toString()
{
  Node *tmp = head;
  cout << "[";
  while (tmp != nullptr)
  {
    cout << tmp->data << ", ";
    tmp = tmp->next;
  }
  cout << "]" << endl;

  return 0;
}

template <class T>
void DLinkedList<T>::toNodeString()
{
  // Print the table header
  std::cout << "+-------+-------+-------+-------+\n";
  std::cout << "| Stt   | Prev  | Value | Next  |\n";
  std::cout << "+-------+-------+-------+-------+\n";

  // Print each node in the linked list
  int i = 0;
  Node *current_node = this->head;
  while (current_node != nullptr)
  {
    std::cout << "| " << std::setw(5) << i
              << " | ";
    if (current_node->previous == nullptr)
    {
      std::cout << std::setw(5) << "start"
                << " | ";
    }
    else
    {
      std::cout << std::setw(5) << current_node->previous->data << " | ";
    }
    std::cout << std::setw(5) << current_node->data << " | ";

    if (current_node->next == nullptr)
    {
      std::cout << std::setw(5) << "end"
                << " |\n";
    }
    else
    {
      std::cout << std::setw(5) << current_node->next->data << " |\n";
    }
    current_node = current_node->next;
    i++;
  }

  // Print the table footer
  std::cout << "+-------+-------+-------+-------+\n";
}

template <class T>
void DLinkedList<T>::add(const T &e)
{
  /* Insert an element into the end of the list. */
  Node *newNode = new Node(e);
  if (this->count != 0)
  {
    this->tail->next = newNode;
    newNode->previous = this->tail;
  }
  else
  {
    this->head = newNode;
  }
  // cout<<"this->tail = "<<this->tail<<"; this->he = " << this->head << " ->" <<this->count<<endl;
  this->tail = newNode;
  this->count++;
}

template <class T>
void DLinkedList<T>::add(int index, const T &e)
{
  /* Insert an element into the list at given index. */
  Node *newNode = new Node(e);
  // lần đầu khi mảng chưa có gì thì zô đây
  if (this->count == 0)
  {
    this->head = newNode;
    this->tail = newNode;
  }
  // lần 2 sẽ là zô đít
  else if (this->count == index)
  {
    this->tail->next = newNode;
    newNode->previous = this->tail;
  }
  // lần 3 zô khi mảng đã có hàng họ đủ rồi
  else
  {
    int i = 0;

    Node *tmp = this->head;
    while (tmp != nullptr)
    {
      // cout << "; tmp->next->next = " << tmp->next << endl;

      if (i == index)
      {
        newNode->next = tmp->next;
        if (tmp->next != nullptr)
        {
          tmp->next->previous = newNode;
        }
        tmp->next = newNode;
        newNode->previous = tmp;
        cout << "newNode->next = " << newNode->next << "; tmp->next->next = " << tmp->next->next << endl;
        break;
      }
      i++;
      tmp = tmp->next;
    }
  }
  this->count++;
}

template <class T>
int DLinkedList<T>::size()
{
  /* Return the length (size) of list */
  return this->count;
}

int main()
{
  DLinkedList<int> list;
  int size = 10;
  for (int idx = 0; idx < size; idx++)
  {
    // list.add(idx);
    list.add(0, idx);
  }
  cout << list.toString() << endl;
  list.toNodeString();
  // [0,1,2,3,4,5,6,7,8,9]
  return 0;
}
