#include <iostream>
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
    do
    {
      do
      {
        *i = *i + 1;
      } while (start[*i] < p);

      do
      {
        *j = *j - 1;

      } while (start[*j] > p);

      T temp = start[*i]; // swap(A[i],A[j])
      start[*i] = start[*j];
      start[*j] = temp;
    } while (*i < *j);

    T temp1 = start[*i]; // swap(A[i],A[j])
    start[*i] = start[*j];
    start[*j] = temp1;

    T temp2 = *start; //  swap(A[l],A[j])
    *start = start[*j];
    start[*j] = temp2;
    return j;
  }

  static void QuickSort(T *start, T *end)
  {
    // TODO
    // In this question, you must print out the index of pivot in subarray after everytime calling method Partition.

    if (*(start - 1) < *(end - 1))
    {
      T *pivot_position = Partition(start, end);
      cout << *pivot_position << " ";
      QuickSort(start, pivot_position - 1);
      QuickSort(pivot_position + 1, end);
    }
  }
};
int main()
{
  int array[] = {3, 5, 7, 10, 12, 14, 15, 13, 1, 2, 9, 6, 4, 8, 11, 16, 17, 18, 20, 19};
  cout << "Index of pivots: ";
  Sorting<int>::QuickSort(&array[0], &array[20]);
  cout << "\n";
  cout << "Array after sorting: ";
  for (int i : array)
    cout << i << " ";

  // Index of pivots: 2 0 0 6 1 0 2 1 0 0 2 1 0 0 0 0 0 0 1 0
  // Array after sorting: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
  cout << endl
       << "happy ending" << endl;

  return 0;
}