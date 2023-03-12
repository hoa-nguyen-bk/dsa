#include <iostream>
#include <iomanip>
using namespace std;
#ifndef DOUBLY_LINKED_LIST_CPP
#define DOUBLY_LINKED_LIST_CPP
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
  void toString();
  void toNodeString();
  T get(int index);
  void set(int index, const T &e);
  bool empty();
  int indexOf(const T &item);
  bool contains(const T &item);
  T removeAt(int index);
  bool removeItem(const T &item);
  void clear();

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
//----------------------------------------
//-----------start bai 4--------------
//----------------------------------------
template <class T>
T DLinkedList<T>::removeAt(int index)
{
  /* Remove element at index and return removed value */
  if (this->count == 0 || index < 0 || index > this->count)
  {
    throw out_of_range("Index out of range");
  }
  Node *currentNode = this->head;
  // THDB: for list only one element

  if (this->count == 1)
  {
    this->head = nullptr;
    this->tail = nullptr;
    this->count = 0;
    T data = currentNode->data;
    delete currentNode;
    return data;
  }

  Node *previousNode = nullptr;

  for (int i = 0; i < index; ++i)
  {
    previousNode = currentNode;
    currentNode = currentNode->next;
    currentNode->previous = previousNode;
  }
  // if index = 0, chỉ có 1 thằng là tại vị trí đầu
  if (previousNode == nullptr)
  {
    // cho thằng head là node tiếp theo
    this->head = currentNode->next;
    // vị trí đầu thì dĩ nhiên next prev null rồi
    currentNode->next->previous = nullptr;
  }
  // còn nếu là vị trí còn lại
  else
  {
    // cho node trước bằng với node sau của sau luôn, dán liền 2 nốt cách 1 cục current head lại

    Node *nextNode = currentNode->next;
    if (nextNode == nullptr)
    {
      this->tail = previousNode;
      previousNode->next = nullptr;
    }
    else
    {
      previousNode->next = nextNode;
      // còn node sau nối bằng node trước, chỗ này tách node cho dễ hiểu thôi
      nextNode->previous = previousNode;
    }
  }

  T data = currentNode->data;

  delete currentNode;
  this->count--;
  return data;
}

template <class T>
bool DLinkedList<T>::removeItem(const T &item)
{
  /* Remove the first apperance of item in list and return true, otherwise return false */
  if (this->count == 0)
  {
    throw std::out_of_range("Index out of range");
  }

  Node *currentNode = this->head;
  int i = 0;
  while (currentNode != NULL)
  {
    // nếu tìm được node để xóa
    if (currentNode->data == item)
    {
      this->removeAt(i);
      return true;
    }
    i++;
    currentNode = currentNode->next;
  }
  return false;
}

template <class T>
void DLinkedList<T>::clear()
{
  /* Remove all elements in list */
  if(this->count== 0){
    return;
  }
  Node *currentNode = this->head;
  while (currentNode != nullptr)
  {
    Node *temp = currentNode;
    currentNode = currentNode->next;
    delete temp;
  }
  this->head = nullptr;
  this->tail = nullptr;
  this->count = 0;
}

//----------------------------------------
//----------------------end --------------
//----------------------------------------

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
  this->clear();
}

template <class T>
void DLinkedList<T>::toString()
{
  Node *tmp = head;
  cout << "[";
  while (tmp != nullptr)
  {
    cout << tmp->data << ", ";
    tmp = tmp->next;
  }
  cout << "]" << endl;
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
    cout << "null + ";
  }
  else
  {
    cout << setw(5) << this->head->data << " + ";
  }
  cout << "tail  = ";
  if (this->tail == nullptr)
  {
    cout << " null";
  }
  else
  {

    cout << setw(5) << this->tail->data;
  }
  cout << " +\n";
  cout << "+-------+-------+-------+-------+\n";
  cout << "+         count = ";
  cout << setw(5) << this->count << "  ";
  cout << "       +\n";

  // Print the table footer
  cout << "+-------+-------+-------+-------+\n";
  cout << endl;
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

template <class T>
T DLinkedList<T>::get(int index)
{
  /* Give the data of the element at given index in the list. */
  if (index < 0 || index >= this->count)
  {
    throw std::out_of_range("Index out of range");
  }
  Node *currentNode = this->head;
  for (int i = 0; i < index; i++)
  {
    currentNode = currentNode->next;
  }
  return currentNode->data;
}

template <class T>
void DLinkedList<T>::set(int index, const T &e)
{
  /* Assign new value for element at given index in the list */
  if (index < 0 || index >= this->count)
  {
    throw std::out_of_range("Index out of range");
  }
  Node *currentNode = this->head;
  for (int i = 0; i < index; i++)
  {
    currentNode = currentNode->next;
  }
  currentNode->data = e;
}

template <class T>
bool DLinkedList<T>::empty()
{
  /* Check if the list is empty or not. */
  if (this->count == 0)
  {
    return true;
  }
  return false;
}

template <class T>
int DLinkedList<T>::indexOf(const T &item)
{
  /* Return the first index wheter item appears in list, otherwise return -1 */
  Node *tmp = this->head;
  int i = 0;
  while (tmp != nullptr)
  {
    if (tmp->data == item)
    {
      return i;
    }
    i++;
    tmp = tmp->next;
  }
  return -1;
}

template <class T>
bool DLinkedList<T>::contains(const T &item)
{
  /* Check if item appears in the list */
  Node *tmp = this->head;
  int i = 0;
  while (tmp != nullptr)
  {
    if (tmp->data == item)
    {
      return true;
    }
    i++;
    tmp = tmp->next;
  }
  return false;
}
#endif // DOUBLY_LINKED_LIST_CPP