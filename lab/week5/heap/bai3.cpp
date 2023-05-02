#include <iostream>
using namespace std;

bool isLeaf(int pos, int count) // True if pos is a leaf
{
  return (pos >= count / 2) && (pos < count);
}

void reheapDown(int maxHeap[], int numberOfElements, int index)
{
  if (!isLeaf(index, numberOfElements))
  {
    int leftChild = index * 2 + 1;
    int rightChild = index * 2 + 2;
    int lastPosition = numberOfElements - 1;
    int largeChild = leftChild;
    if (rightChild <= lastPosition && maxHeap[rightChild] > maxHeap[leftChild])
      largeChild = rightChild;

    if (maxHeap[largeChild] > maxHeap[index])
    {
      int temp = maxHeap[index];
      maxHeap[index] = maxHeap[largeChild];
      maxHeap[largeChild] = temp;
      reheapDown(maxHeap, numberOfElements, largeChild);
    }
    else
      return;
  }
  return;
}

void reheapUp(int maxHeap[], int numberOfElements, int index)
{
  if (index > 0)
  {
    int parent = (index - 1) / 2;
    if (maxHeap[index] > maxHeap[parent])
    {
      int temp = maxHeap[index];
      maxHeap[index] = maxHeap[parent];
      maxHeap[parent] = temp;
      reheapUp(maxHeap, numberOfElements, parent);
    }
  }
}
int main()
{
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
  int size = sizeof(arr) / sizeof(arr[0]);
  reheapDown(arr, size, 0);
  cout << "[ ";
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << "]" << endl;
  cout << "Happy ending :)" <<endl;
  // [ 3 2 7 4 5 6 1 8 ]

  return 0;
}