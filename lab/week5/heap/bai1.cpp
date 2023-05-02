
#include "heap.h"

int main()
{
  Heap<int> maxHeap;
  for (int i = 0; i < 5; i++)
  {
    maxHeap.push(i);
  }
  cout << maxHeap.peek() << endl; // 4
  maxHeap.printHeap();
  // Max Heap [ 4 3 1 0 2 ]
  cout << maxHeap.pop() << endl;
  maxHeap.printHeap();
  // [3 1 0 2]
  cout << "ket thuc em ai" << endl;
  return 0;
}
