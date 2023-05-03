#include <iostream>
#include "sorting.h"
using namespace std;
// Helping functions go here

int main()
{
  int arr[4] = {4, 2, 9, 1};
  Sorting<int>::heapSort(&arr[0], &arr[4]);
  // 1, 2, 4, 9
  // int arr[4] = {-1, 0, 2, 3};
  // Sorting<int>::heapSort(&arr[0], &arr[4]);
  // -1, 0, 2, 3
  return 0;
}
