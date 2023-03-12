#include <iostream>
#include "stack.h"
using namespace std;

//----------------------------------------
//-----------end bai 1--------------
//----------------------------------------
int main()
{
  // Stack<int> stack;
  // cout << stack.empty() << " " << stack.size();
  // // 1 0
  Stack<int> stack;
  stack.toNodeString();
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