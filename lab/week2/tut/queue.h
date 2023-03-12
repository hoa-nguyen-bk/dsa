using namespace std;
#include "../doubly_linked_list.cpp"
#ifndef QUEUE_H
#define QUEUE_H
template <class T>
class Queue
{
protected:
  DLinkedList<T> list;

public:
  Queue() {}
  void toNodeString(){
    this->list.toNodeString();
  }
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
    T front()
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