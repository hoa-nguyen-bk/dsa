#include <iostream>
#include "../doubly_linked_list.h"
using namespace std;

#ifndef STACK_H
#define STACK_H
template <class T>
class Stack
{
protected:
  DLinkedList<T> list;

public:
  Stack() {}
  void push(T item);
  T pop();
  T top();
  bool empty();
  int size();
  void clear();
};
#endif
//----------------------------------------
//-----------start bai 1--------------
//----------------------------------------
template <class T>
void Stack<T>::push(T item)
{
  // TODO: Push new element into the top of the stack
  this->list.add(0, item);
}

template <class T>
T Stack<T>::pop()
{
  // TODO: Remove an element on top of the stack
  return this->list.removeAt(0);
}

template <class T>
T Stack<T>::top()
{
  // TODO: Get value of the element on top of the stack
  return this->list.get(0);
}

template <class T>
bool Stack<T>::empty()
{
  // TODO: Determine if the stack is empty
  return this->list.empty();
}

template <class T>
int Stack<T>::size()
{
  // TODO: Get the size of the stack
  return this->list.size();
}

template <class T>
void Stack<T>::clear()
{
  // TODO: Clear all elements of the stack
  this->list.clear();
}


//----------------------------------------
//-----------end bai 1--------------
//----------------------------------------
int main()
{
  // Stack<int> stack;
  // cout << stack.empty() << " " << stack.size();
  // // 1 0
  Stack<int> stack;

  int item[] = {3, 1, 4, 5, 2, 8, 10, 12};
  for (int idx = 0; idx < 8; idx++)
  {
    stack.push(item[idx]);
  }

  cout << " assert(stack.top() == 12)" << stack.top() << endl;

  stack.pop();
  stack.pop();

  cout << stack.top();
  // output: 8
  return 0;
}