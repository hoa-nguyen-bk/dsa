#define SEPARATOR "#<ab@17943918#@>#"
#ifndef SORTING_H
#define SORTING_H
#include <iostream>
#include <queue>
using namespace std;
template <class T>
class Sorting
{
public:
  /* Function to print an array */
  static void printArray(T *start, T *end)
  {
    long size = end - start;
    for (int i = 0; i < size - 1; i++)
      cout << start[i] << ", ";
    cout << start[size - 1];
    cout << endl;
  }
  static bool isLeaf(int pos, int count) // True if pos is a leaf
  {
    return (pos >= count / 2) && (pos < count);
  }
  static void reheapDown(T *start, int count, int index)
  {
    int leftChild = index * 2 + 1;
    int rightChild = index * 2 + 2;
    int smallChild = index;
    if (rightChild < count && start[rightChild] < start[smallChild])
    {
      smallChild = rightChild;
    }
    else if (leftChild < count && start[leftChild] < start[smallChild])
    {
      smallChild = leftChild;
    }
    if (start[smallChild] != start[index])
    {
      int temp = start[index];
      start[index] = start[smallChild];
      start[smallChild] = temp;
      reheapDown(start, count, smallChild);
    }
  }
  // Helping functions go here
  static void heapSort(T *start, T *end)
  {
    // TODO
    long count = end - start;
    int position = count / 2 - 1;
    while (position >= 0)
    {
      reheapDown(start, count, position);
      position--;
    }

    int last = count - 1;
    while (last >= 0)
    {
      // swap(0, last)
      T temp = start[0];
      start[0] = start[last];
      start[last] = temp;

      reheapDown(start, last, 0);
      last--;
    }
    T arrayRes[count];
    for(int i = 0; i < count; i++){
      arrayRes[i] = start[count-i-1];
    }
    Sorting<T>::printArray(&arrayRes[0], &arrayRes[count]);
  }
  //{4, 2, 9, 1} -> 1, 2, 4, 9
};
#endif /* SORTING_H */