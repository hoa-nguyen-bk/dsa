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
  // Helping functions go here
  static void heapify(T *start, T *end, int i)
  {
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    int n = end - start;

    if (left < n && start[left] > start[largest])
      largest = left;

    if (right < n && start[right] > start[largest])
      largest = right;

    // Swap and continue heapifying if root is not largest
    if (largest != i)
    {
      swap(start[i], start[largest]);
      heapify(start, end, largest);
    }
  }

  // Helping functions go here
  static void heapSort(T *start, T *end)
  {
    // TODO
    int n = end - start;

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(start, end, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--)
    {
      // Move current root to end
      swap(start[0], start[i]);

      // call max heapify on the reduced heap
      heapify(start, &start[i], 0);
    }

    // Print array
    Sorting<T>::printArray(start, end);
  }
  //{4, 2, 9, 1} -> 1, 2, 4, 9
};
#endif /* SORTING_H */