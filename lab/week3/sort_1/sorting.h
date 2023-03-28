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

      T temp = start[*i]; // swap(A[i],A[j])
      cout << "temp = " << temp << endl;
      cout << "before swap: start[*i] = " << start[*i] << endl;
      start[*i] = start[*j];
      cout << "after swap: start[*i] = " << start[*i] << endl;
      start[*j] = temp;
    } while (*i < *j);

    cout << "swap" << endl;
    T temp1 = start[*i]; // swap(A[i],A[j])
    cout << "temp1 = " << temp1 << endl;
    cout << "before swap: start[*i] = " << start[*i] << endl;
    start[*i] = start[*j];
    cout << "after swap: start[*i] = " << start[*i] << endl;
    start[*j] = temp1;
    // swap(*i, *j);

    cout << "swap" << endl;

    T temp2 = *start; //  swap(A[l],A[j])
    cout << "temp2 = " << temp2 << endl;
    cout << "before swap: *start = " << *start << endl;
    *start = start[*j];
    cout << "after swap: *start = " << *start << endl;
    start[*j] = temp2;
    // swap(*start, *j);
    return j;
  }

  static void QuickSort(T *start, T *end)
  {
    // TODO
    // In this question, you must print out the index of pivot in subarray after everytime calling method Partition.
    cout << "start - 1 = " << *(start - 1) << "; end - 1 = " << *(end - 1) << endl;

    if (*(start - 1) < *(end - 1))
    {
      T *pivot_index = Partition(start, end);
      cout << "pivot index = " << *pivot_index << endl;
      QuickSort(start, pivot_index);
      QuickSort(pivot_index + 1, end);
    }
  }
};
#endif /* SORTING_H */