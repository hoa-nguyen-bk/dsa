#include <iostream>
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
  void add(T e);
  void add(int index, T e);
  int size();

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
void SLinkedList<T>::add(const T &e)
{
  /* Insert an element into the end of the list. */
  
}

template <class T>
void SLinkedList<T>::add(int index, const T &e)
{
  /* Insert an element into the list at given index. */
}

template <class T>
int SLinkedList<T>::size()
{
  /* Return the length (size) of list */
  return 0;
}

using namespace std;

int main()
{
  SLinkedList<int> list;
  int size = 10;

  for (int index = 0; index < size; index++)
  {
    list.add(index);
  }

  cout << list.toString();
  // [0,1,2,3,4,5,6,7,8,9]
  return 0;
}
