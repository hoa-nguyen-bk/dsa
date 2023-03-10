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
  cout << "+-------+-------+-------+-------+\n";
  cout << "| Stt   | Prev  | Value | Next  |\n";
  cout << "+-------+-------+-------+-------+\n";

  // Print each node in the linked list
  int i = 0;
  Node *current_node = this->head;
  while (current_node != nullptr)
  {
    cout << "| " << setw(5) << i
         << " | ";
    if (current_node->previous == nullptr)
    {
      cout << setw(5) << "start"
           << " | ";
    }
    else
    {
      cout << setw(5) << current_node->previous->data << " | ";
    }
    cout << setw(5) << current_node->data << " | ";

    if (current_node->next == nullptr)
    {
      cout << setw(5) << "end"
           << " |\n";
    }
    else
    {
      cout << setw(5) << current_node->next->data << " |\n";
    }
    current_node = current_node->next;
    i++;
  }
  cout << "+-------+-------+-------+-------+\n";
  cout << "+ head  = ";
  if (this->head == nullptr)
  {
    cout << "null+ ";
  }
  else
  {
    cout << setw(5) << this->head->data << " + ";
  }
  cout << " tail = ";
  if (this->tail == nullptr)
  {
    cout << " null";
  }
  else
  {

    cout << setw(5) << this->tail->data ;
  }
  cout << " +\n";
  cout << "+-------+-------+-------+-------+\n";
  cout << "+         count = ";
  cout << setw(5) << this->count << "  ";
  cout << "       +\n";

  // Print the table footer
  cout << "+-------+-------+-------+-------+\n";
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
  if (index > this->count)
  {
    return;
  }

  Node *newNode = new Node(e);
  // if there were nothing
  if (this->count == 0)
  {
    this->head = newNode;
    this->tail = newNode;
    this->count++;
    return;
  }

  // case 1: insert at index = 0, beginner of the list
  if (index == 0)
  {
    newNode->next = this->head;
    if (this->head != nullptr)
    {
      this->head->previous = newNode;
    }
    this->head = newNode;
    this->count++;
    return;
  }
  // case 2: insert at the end of the list
  if (index == this->count)
  {
    if (this->tail != nullptr)
    {
      this->tail->next = newNode;
      newNode->previous = tail;
    }
    this->tail = newNode;
    this->count++;
    return;
  }

  // case 3: insert in the middle of the list
  Node *currentNode = this->head;

  // với điểm dừng index - 1 thì cục current node sẽ
  for (int i = 0; i < index - 1; i++)
  {
    currentNode = currentNode->next;
  }
  newNode->next = currentNode->next;
  currentNode->next = newNode;
  newNode->previous = currentNode;
  if (newNode->next != nullptr)
  {
    newNode->next->previous = newNode;
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
  cout << "list.size()-1 = " << list.size() - 1 << endl;
  list.add(list.size() - 1, 99);
  list.toNodeString();

  list.add(list.size(), 77);
  list.toNodeString();
  // [0,1,2,3,4,5,6,7,8,9]
  return 0;
}
