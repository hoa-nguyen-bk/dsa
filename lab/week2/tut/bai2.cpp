#include <iostream>
using namespace std;
#include "./queue.h"


int main()
{
  Queue<int> queue;
  cout << (queue.empty()) << endl;
  cout << (queue.size()) << endl;
  return 0;
}
