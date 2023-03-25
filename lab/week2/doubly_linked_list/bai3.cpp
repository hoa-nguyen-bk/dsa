#include <iostream>
#include <iomanip>
using namespace std;
template <class T>
class DLinkedList
{
public:
  class Iterator; // forward declaration
  class Node;     // Forward declaration
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
  Iterator begin()
  {
    cout << "go to begin" << endl;
    return Iterator(this, true);
  }
  Iterator end()
  {
    cout << "go to end" << endl;

    return Iterator(this, false);
  }

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
  class Iterator
  {
  private:
    DLinkedList<T> *pList;
    Node *current;
    int index; // is the index of current in pList
  public:
    Iterator(DLinkedList<T> *pList, bool begin);
    Iterator &operator=(const Iterator &iterator);
    void set(const T &e);
    T &operator*();
    bool operator!=(const Iterator &iterator);
    void remove();

    // Prefix ++ overload
    Iterator &operator++();

    // Postfix ++ overload
    Iterator operator++(int);
  };
};
//----------------------------------------
//-----------start interator--------------
//----------------------------------------
template<class T>
DLinkedList<T>::Iterator::Iterator(DLinkedList<T> *pList, bool begin) 
{
    this->pList = pList;
    if (begin) {
        this->current = pList->head;
        this->index = 0;
    }
    else {
        this->current = NULL;
        this->index = pList->count;
    }
}

template<class T>
typename DLinkedList<T>::Iterator& DLinkedList<T>::Iterator::operator=(const DLinkedList<T>::Iterator &iterator)
{
    this->pList = iterator.pList;
    this->current = iterator.current;
    this->index = iterator.index;
    return *this;
}

template<class T> 
void DLinkedList<T>::Iterator::set(const T &e)
{
    this->current->data = e;
}

template<class T>
T& DLinkedList<T>::Iterator::operator*() 
{
    return this->current->data;
}

template<class T>
void DLinkedList<T>::Iterator::remove() 
{
    if (this->current == NULL) return;

    Node *temp = this->current;
    if (this->current == this->pList->head) {
        this->pList->head = this->current->next;
        if (this->pList->head != NULL) {
            this->pList->head->previous = NULL;
        }
        this->current = NULL;
        this->index = -1;
    }
    else if (this->current == this->pList->tail) {
        this->pList->tail = this->current->previous;
        this->pList->tail->next = NULL;
        this->current = NULL;
        this->index = -1;
    }
    else {
        this->current->previous->next = this->current->next;
        this->current->next->previous = this->current->previous;
        this->current = this->current->previous;
        this->index--;
    }
    delete temp;
    this->pList->count--;
}

template<class T>
bool DLinkedList<T>::Iterator::operator!=(const DLinkedList::Iterator &iterator) 
{
    return this->current != iterator.current;
}

template<class T>
typename DLinkedList<T>::Iterator& DLinkedList<T>::Iterator::operator++() 
{
    if (this->current == NULL) {
        this->current = this->pList->head;
        this->index = 0;
    }
    else {
        this->current = this->current->next;
        this->index++;
    }
    return *this;
}

template<class T>
typename DLinkedList<T>::Iterator DLinkedList<T>::Iterator::operator++(int) 
{
    Iterator iterator = *this;
    ++(*this);
    return iterator;
}


//----------------------------------------
//-----------end interator--------------
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

    cout << setw(5) << this->tail->data;
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

int main()
{
  DLinkedList<int> list;
  int size = 10;
  for (int idx = 0; idx < size; idx++)
  {
    list.add(idx);
  }
  list.toNodeString();
  DLinkedList<int>::Iterator it = list.begin();
  for (; it != list.end(); it++)
  {
    cout << *it << " |";
  }
  list.toNodeString();
  cout << "end with no error" << endl;
  return 0;
}
