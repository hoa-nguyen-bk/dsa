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
};

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
  if (index < 0 || index >= count)
  {
    throw std::out_of_range("Index out of range");
  }
  Node *current = head;
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
  return count == 0;
}

template <class T>
int SLinkedList<T>::indexOf(const T &item)
{
  /* Return the first index wheter item appears in list, otherwise return -1 */
  int index = 0;
  for (Node *current = head; current != NULL; current = current->next)
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
  if (index < 0 || index >= count)
  {
    throw out_of_range("Index is out of range.");
  }
  Node *nodeToDelete;
  if (index == 0)
  {
    nodeToDelete = head;
    head = nodeToDelete->next;
  }
  else
  {
    Node *prevNode = new Node(index - 1);
    nodeToDelete = prevNode->next;
    prevNode->next = nodeToDelete->next;
    if (nodeToDelete == tail)
    {
      tail = prevNode;
    }
  }
  T data = nodeToDelete->data;
  delete nodeToDelete;
  count--;
  return data;
}

template <class T>
bool SLinkedList<T>::removeItem(const T &item)
{
  /* Remove the first apperance of item in list and return true, otherwise return false */
  Node *curr = head;
  Node *prev = NULL;

  while (curr != NULL)
  {
    if (curr->data == item)
    {
      if (prev == NULL)
      {
        // Removing the first node in the list
        head = curr->next;
        if (tail == curr)
        {
          // If the removed node was also the last node in the list
          tail = NULL;
        }
      }
      else
      {
        prev->next = curr->next;
        if (tail == curr)
        {
          // If the removed node was the last node in the list
          tail = prev;
        }
      }
      delete curr;
      count--;
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
  Node *curr = head;
  while (curr != NULL)
  {
    Node *temp = curr;
    curr = curr->next;
    delete temp;
  }
  head = NULL;
  tail = NULL;
  count = 0;
}

int main()
{
  SLinkedList<int> list;
  int values[] = {10, 15, 2, 6, 4, 7, 40, 8};
  int index[] = {0, 0, 1, 3, 2, 3, 5, 0};
  int expvalues[] = {8, 15, 2, 4, 7, 10, 40, 6};

  for (int idx = 0; idx < 8; idx++)
  {
    list.add(index[idx], values[idx]);
  }

  cout << "(list.size() == 8)" << (list.size() == 8) << endl;

  for (int idx = 0; idx < 8; idx++)
  {
    cout << idx << " compare: " << list.get(idx) << " == " << expvalues[idx] << endl;
  }

  cout << list.toString();
  // [ 8, 15, 2, 4, 7, 10, 40, 6 ]
  return 0;
}
