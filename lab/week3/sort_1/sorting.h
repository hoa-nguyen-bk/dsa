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
    T *i = start - 1;
    T *j = end;
    cout << " i[" << i << "] = " << *i << "; j[" << j << "] = " << *(j - 2) << endl;
    cout << "Gia tri A[i] = "<< start[*i]<<endl;
    while (*i < *j)
    {
      while (*i < p)
      {
        cout << "*i < p = " << *i << endl;
        i++;
      }
      while (*j > p)
      {
        j--;
        cout << "*j = " << *j << " > p = " << p << endl;
      }
      cout << "swap" << endl;
      swap(*i, *j);
    }
    swap(*i, *j);
    swap(*start, *j);
    return j;
  }

  static void QuickSort(T *start, T *end)
  {
    // TODO
    // In this question, you must print out the index of pivot in subarray after everytime calling method Partition.

    if (end <= start)
      return; // Don’t sort 0 or 1 element

    cout << "start = " << start[0] << "; end = " << start[end - start - 1] << endl;
    int *pivot_index = Partition(start, end);
    cout << "pivot index = " << *pivot_index << endl;
    cout << "QuickSort(" << start << " , " << pivot_index << ")" << endl;
    // QuickSort(start, pivot_index);
    // QuickSort(pivot_index + 1, end);
  }
};
#endif /* SORTING_H */