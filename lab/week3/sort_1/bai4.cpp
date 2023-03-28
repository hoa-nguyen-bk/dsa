#include <iostream>
#include "sorting.h"
using namespace std;

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