#include <iostream>
#include <cstdlib> // for std::abort

using namespace std;

#define assert(condition)                                                 \
  if (!(condition))                                                       \
  {                                                                       \
    std::cerr << "Assertion failed: " << #condition << " in " << __FILE__ \
              << " line " << __LINE__ << std::endl;                       \
    std::abort();                                                         \
  }

template <class T>
class SLinkedList
{
public:
  class Iterator; // forward declaration
  class Node;     // Forward declaration
protected:
  Node *head;
  Node *tail;
  int count;

public:
  SLinkedList() : head(nullptr), tail(nullptr), count(0){};
  ~SLinkedList();
  void add(const T &e);
  void add(int index, const T &e);
  int size();
  int *toString();
  bool empty();
  T get(int index);
  void clear();
  void set(int index, const T &e);
  int indexOf(const T &item);
  bool contains(const T &item);
  T removeAt(int index);
  bool removeItem(const T &item);
  SLinkedList(const SLinkedList &list)
  {
    this->count = 0;
    this->head = nullptr;
    this->tail = nullptr;
  }
  Iterator begin()
  {
    return Iterator(this, true);
  }
  Iterator end()
  {
    return Iterator(this, false);
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
    Node(T data, Node *next = nullptr)
    {
      this->data = data;
      this->next = next;
    }
  };

  class Iterator
  {
  private:
    SLinkedList<T> *pList;
    Node *current;
    int index; // corresponding with current node
  public:
    Iterator(SLinkedList<T> *pList, bool begin);
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

// Start interator

template <class T>
SLinkedList<T>::Iterator::Iterator(SLinkedList<T> *pList, bool begin)
{
  /*
      Constructor of iterator
      * Set pList to pList
      * begin = true:
      * * Set current (index = 0) to pList's head if pList is not NULL
      * * Otherwise set to NULL (index = -1)
      * begin = false:
      * * Always set current to NULL
      * * Set index to pList's size if pList is not NULL, otherwise 0
  */
  this->pList = pList;
  if (begin)
  {
    if (this->pList)
    {
      current = pList->head;
      index = 0;
    }
    else
    {
      current = NULL;
      index = -1;
    }
  }
  else
  {
    current = NULL;
    if (this->pList)
      index = pList->size();
    else
      index = 0;
  }
}

template <class T>
typename SLinkedList<T>::Iterator &SLinkedList<T>::Iterator::operator=(const Iterator &iterator)
{
  /*
      Assignment operator
      * Set this current, index, pList to iterator corresponding elements.
  */
  current = iterator.current;
  index = iterator.index;
  pList = iterator.pList;
  return *this;
}

template <class T>
void SLinkedList<T>::Iterator::remove()
{
  /*
      Remove a node which is pointed by current
      * After remove current points to the previous node of this position (or node with index - 1)
      * If remove at front, current points to previous "node" of head (current = NULL, index = -1)
      * Exception: throw std::out_of_range("Segmentation fault!") if remove when current is NULL
  */
  if (current == NULL)
    throw std::out_of_range("Segmentation fault!");
  else if (index != 0)
  {
    current = pList->head;
    for (int i = 0; i < index - 1; i++)
    {
      current = current->next;
    }
    Node *del = current->next;
    current->next = current->next->next;
    delete del;
    index--;
    pList->count--;
  }
  else
  {
    Node *temp = pList->head;
    pList->head = pList->head->next;
    delete temp;
    index = -1;
    current = NULL;
    pList->count--;
  }
}

template <class T>
void SLinkedList<T>::Iterator::set(const T &e)
{
  /*
      Set the new value for current node
      * Exception: throw std::out_of_range("Segmentation fault!") if current is NULL
  */
  if (current == NULL)
    throw std::out_of_range("Segmentation fault!");
  current->data = e;
}

template <class T>
T &SLinkedList<T>::Iterator::operator*()
{
  /*
      Get data stored in current node
      * Exception: throw std::out_of_range("Segmentation fault!") if current is NULL
  */
  if (current == NULL)
    throw std::out_of_range("Segmentation fault!");
  return current->data;
}

template <class T>
bool SLinkedList<T>::Iterator::operator!=(const Iterator &iterator)
{
  /*
      Operator not equals
      * Returns false if two iterators points the same node and index
  */
  if (current == NULL)
    throw std::out_of_range("Segmentation fault!");
  if (this->current == iterator.current && this->index == iterator.index)
    return false;
  return true;
}
// Prefix ++ overload
template <class T>
typename SLinkedList<T>::Iterator &SLinkedList<T>::Iterator::operator++()
{
  /*
      Prefix ++ overload
      * Set current to the next node
      * If iterator corresponds to the previous "node" of head, set it to head
      * Exception: throw std::out_of_range("Segmentation fault!") if iterator corresponds to the end
  */
  if (current == NULL)
    throw std::out_of_range("Segmentation fault!");
  current = current->next;
  index++;
  return *this;
}
// Postfix ++ overload
template <class T>
typename SLinkedList<T>::Iterator SLinkedList<T>::Iterator::operator++(int)
{
  /*
      Postfix ++ overload
      * Set current to the next node
      * If iterator corresponds to the previous "node" of head, set it to head
      * Exception: throw std::out_of_range("Segmentation fault!") if iterator corresponds to the end
  */
  Iterator *temp = this;
  ++(*this);
  return *temp;
}

// end of iterator
template <class T>
int *SLinkedList<T>::toString()
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
SLinkedList<T>::~SLinkedList()
{
  Node *current = this->head;
  while (current != nullptr)
  {
    Node *next = current->next;
    delete current;
    current = next;
  }
  this->head = nullptr;
  this->tail = nullptr;
  this->count = 0;
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
    if (this->head == nullptr)
    {
      this->head = newElement;
      this->tail = newElement;
    }
    else
    {
      newElement->next = this->head;
      this->head = newElement;
    }
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
    if (index == this->count)
    {
      this->tail = newElement;
    }
  }
  this->count++;
}

template <class T>
int SLinkedList<T>::size()
{
  /* Return the length (size) of list */
  return this->count;
}

template <class T>
T SLinkedList<T>::get(int index)
{
  /* Give the data of the element at given index in the list. */
  if (index < 0 || index >= this->count)
  {
    throw std::out_of_range("Index out of range");
  }
  Node *current = this->head;
  for (int i = 0; i < index; i++)
  {
    current = current->next;
  }
  return current->data;
}

template <class T>
void SLinkedList<T>::set(int index, const T &e)
{
  /* Assign new value for element at given index in the list */
  if (index < 0 || index >= count)
  {
    throw std::out_of_range("Index out of range");
  }
  Node *current = head;
  for (int i = 0; i < index; i++)
  {
    current = current->next;
  }
  current->data = e;
}

template <class T>
bool SLinkedList<T>::empty()
{
  /* Check if the list is empty or not. */
  return this->count == 0;
}

template <class T>
int SLinkedList<T>::indexOf(const T &item)
{
  /* Return the first index wheter item appears in list, otherwise return -1 */
  int index = 0;
  for (Node *current = head; current != nullptr; current = current->next)
  {
    if (current->data == item)
    {
      return index;
    }
    index++;
  }
  return -1;
}

template <class T>
bool SLinkedList<T>::contains(const T &item)
{
  /* Check if item appears in the list */
  return indexOf(item) >= 0;
}

template <class T>
T SLinkedList<T>::removeAt(int index)
{
  /* Remove element at index and return removed value */
  if (index < 0 || index >= this->count)
  {
    throw out_of_range("Index is out of range.");
  }
  Node *nodeToDelete = new Node();
  if (index == 0)
  {
    nodeToDelete = this->head;
    this->head = nodeToDelete->next;
  }
  else
  {
    Node *prevNode = new Node(index - 1);
    nodeToDelete = prevNode->next;
    prevNode->next = nodeToDelete->next;
    if (nodeToDelete == this->tail)
    {
      this->tail = prevNode;
    }
  }
  T data = nodeToDelete->data;
  delete nodeToDelete;
  this->count--;
  return data;
}

template <class T>
bool SLinkedList<T>::removeItem(const T &item)
{
  /* Remove the first apperance of item in list and return true, otherwise return false */
  Node *curr = new Node();
  curr = this->head;
  Node *prev = new Node();

  while (curr != nullptr)
  {
    if (curr->data == item)
    {
      if (prev == nullptr)
      {
        // Removing the first node in the list
        this->head = curr->next;
        if (this->tail == curr)
        {
          // If the removed node was also the last node in the list
          this->tail = nullptr;
        }
      }
      else
      {
        prev->next = curr->next;
        if (this->tail == curr)
        {
          // If the removed node was the last node in the list
          this->tail = prev;
        }
      }
      delete curr;
      this->count--;
      return true;
    }
    prev = curr;
    curr = curr->next;
  }

  return false;
}

template <class T>
void SLinkedList<T>::clear()
{
  /* Remove all elements in list */
  Node *curr = this->head;
  while (curr != nullptr)
  {
    Node *temp = curr;
    curr = curr->next;
    delete temp;
  }
  this->head = nullptr;
  this->tail = nullptr;
  this->count = 0;
}

int main()
{
  SLinkedList<int> list;

  int size = 10;
  for (int idx = 0; idx < size; idx++)
  {
    list.add(idx);
  }
  list.toString();

  SLinkedList<int>::Iterator it = list.begin();
  int expvalue = 0;
  for (it = list.begin(); it != list.end(); it++)
  {
    assert(*it == expvalue);
    cout << "(*it == expvalue)" << (*it == expvalue) << endl;
    expvalue += 1;
  }
  return 0;
}
