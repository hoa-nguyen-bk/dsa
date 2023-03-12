#include <iostream>
#include "queue.h"
#include "stack.h"
using namespace std;

void reverseQueue(Queue<int> &q)
{
  // TODO
  Stack<int> *s = new Stack<int>();
  while (!q.empty())
  {
    s->push(q.top());
    q.pop();
  }

  while (!s->empty())
  {
    q.push(s->top());
    s->pop();
  }
}

int main()
{
  int arr[] = {1, 2, 3};
  int size = sizeof(arr) / sizeof(arr[0]);
  Queue<int> q;
  for (int i = 0; i < size; ++i)
  {
    q.push(arr[i]);
  }
  q.toNodeString();
  reverseQueue(q);
  q.toNodeString();
  // FRONT| 1 2 3 |REAR
  // FRONT| 3 2 1 |REAR
  return 0;
}
