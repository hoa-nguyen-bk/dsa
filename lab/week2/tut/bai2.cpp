#include <iostream>
#include "../doubly_linked_list.h"
using namespace std;
#ifndef QUEUE_H
#define QUEUE_H
#include "DLinkedList.h"
template <class T>
class Queue
{
protected:
  DLinkedList<T> list;

public:
  Queue() {}
  void push(T item)
  {
    // TODO: Push new element into the end of the queue
    this->list.add(item);
  }

  T pop()
  {
    // TODO: Remove an element in the head of the queue
    return this->list.removeAt(0);
  }

  T top()
  {
    // TODO: Get value of the element in the head of the queue
    return this->list.get(0);
  }

  bool empty()
  {
    // TODO: Determine if the queue is empty
    return this->list.empty();
  }

  int size()
  {
    // TODO: Get the size of the queue
    return this->list.size();
  }

  void clear()
  {
    // TODO: Clear all elements of the queue
    return this->list.clear();
  }
};

#endif /* QUEUE_H */

int main()
{
  Queue<int> queue;
  cout << (queue.empty()) << endl;
  cout << (queue.size()) << endl;
  return 0;
}
