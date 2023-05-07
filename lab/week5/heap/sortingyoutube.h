#define SEPARATOR "#<ab@17943918#@>#"
#ifndef SORTINGYOUTUBE_H
#define SORTINGYOUTUBE_H
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

  static void heapify(T *a, int count, int i)
  {
    cout << "count = " << count << "; i = " << i << endl;
    int left = i * 2 + 1;
    int right = i * 2 + 2;
    int min = i;
    if (left < count && a[left] < a[min])
    {
      min = left;
    }
    else if (right < count && a[right] < a[min])
    {
      min = right;
    }
    if (min != i)
    {
      T temp = a[i];
      a[i] = a[min];
      a[min] = temp;
      heapify(a, count, min);
    }
  }
  // Helping functions go here
  static void heapSort(T *start, T *end)
  {
    // TODO
    // xay dung min heap
    int size = end - start;
    for (int i = size / 2 - 1; i >= 0; i--)
    {
      heapify(start, size, i);
    }
      Sorting<T>::printArray(start, end);

    cout << "-------" << endl;
    for (int i = size - 1; i >= 0; i--)
    {
      T temp = start[i];
      start[i] = start[0];
      start[0] = temp;
      Sorting<T>::printArray(start, end);
      heapify(start, i, 0);
    }
    T arrayRes[size];

    for (int i = 0; i < size; i++)
    {
      arrayRes[i] = start[size - i - 1];
    }
    Sorting<T>::printArray(&arrayRes[0], &arrayRes[size]);
  }
  //{4, 2, 9, 1} -> 1, 2, 4, 9
};
#endif /* SORTINGYOUTUBE_H */