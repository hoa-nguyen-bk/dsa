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
    cout << "leaf dk1 = " << (pos >= count / 2) << endl;
    cout << "leaf dk2 = " << (pos < count) << endl;
    return (pos >= count / 2) && (pos < count);
  }
  static void reheapDown(T *start, int count, int index)
  {
    cout << "reheap down " << start << "; count = " << count << "; index = " << index << endl;
    if (!isLeaf(index, count))
    {
      cout << "not leaf" << endl;
      int leftChild = index * 2 + 1;
      int rightChild = index * 2 + 2;
      int lastPosition = count - 1;
      int smallChild = leftChild;
      if (rightChild <= lastPosition && start[rightChild] < start[leftChild])
      {
        cout << "dk 1" << endl;
        smallChild = rightChild;
      }

      if (start[smallChild] < start[index])
      {
        cout << "dk 2" << endl;

        int temp = start[index];
        start[index] = start[smallChild];
        start[smallChild] = temp;
        reheapDown(start, count, smallChild);
      }
      return;
    }
    return;
  }
  // Helping functions go here
  static void heapSort(T *start, T *end)
  {
    // TODO
    long count = end - start;
    int position = count / 2 - 1;
    while (position >= 0)
    {
      reheapDown(start, count - 1, position);
      position--;
    }
    Sorting<T>::printArray(start, end);

    int last = count - 1;
    while (last > 0)
    {
      // swap(0, last)
      T temp = start[0];
      start[0] = start[last];
      start[last] = temp;
      Sorting<T>::printArray(start, end);

      cout << "last = " << last << endl;
      last--;

      reheapDown(start, last - 1, 0);
    }
    Sorting<T>::printArray(start, end);
  }
  //{4, 2, 9, 1} -> 1, 2, 4, 9
};
#endif /* SORTING_H */