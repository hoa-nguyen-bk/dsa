#ifndef SORTING_H
#define SORTING_H

#include <sstream>
#include <iostream>
#include <type_traits>
using namespace std;

template <class T>
class Sorting
{
private:
  static void printArray(T *start, T *end)
  {
    int size = end - start;
    for (int i = 0; i < size; i++)
      cout << start[i] << " ";
    cout << endl;
  }

  // TODO: Write your code here

public:
  static T *Partition(T *start, T *end)
  {
    // TODO: return the pointer which points to the pivot after rearrange the array.
    T p = *start;
    cout << "pivot = " << p << endl;
    cout << "start = " << start << endl;
    T *i = start - 1; // -1 để ra được vị trí đang đứng chính là 0
    T *j = end - 1;
    cout << " i[" << i << "] = " << *i << "; j[" << j << "] = " << *(j - 1) << endl;
    cout << "Gia tri A[i] = " << start[*i] << endl;
    do
    {
      do
      {
        cout << "*i [" << *i << "] = " << start[*i] << endl;
        *i = *i + 1;
        cout << "*i [" << *i << "] = " << start[*i] << " < p = " << p << endl;
      } while (start[*i] < p);

      do
      {
        cout << "j [" << *j << "] =" << start[*j] << endl;
        *j = *j - 1;
        cout << "j [" << *j << "] =" << start[*j] << " > p = " << p << endl;

      } while (start[*j] > p);

      cout << "swap" << endl;

      T temp = start[*i]; // swap(*i, *j);
      cout << "temp = " << temp << endl;
      start[*i] = start[*j];
      start[*j] = temp;
    } while (*i < *j);
    // swap(*i, *j);
    // swap(*start, *j);
    return j;
  }

  static void QuickSort(T *start, T *end)
  {
    // TODO
    // In this question, you must print out the index of pivot in subarray after everytime calling method Partition.

    if (start >= end)
      return; // Don’t sort 0 or 1 element

    cout << "start = " << start[0] << "; end = " << start[end - start - 1] << endl;
    T *pivot_index = Partition(start, end);
    cout << "pivot index = " << *pivot_index << endl;
    // QuickSort(start, pivot_index);
    // QuickSort(pivot_index + 1, end);
  }
};
#endif /* SORTING_H */