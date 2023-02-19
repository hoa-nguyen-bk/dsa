#include <iostream>
using namespace std;
// Implement function
// int findMax(int* arr, int length){}
// to find the largest element using recursion (with length is the number of elements in integer array arr).

int printArr(int *arr, int length)
{
  cout << "[ ";
  for (int i = 0; i < length; i++)
  {
    cout << arr[i] << ", ";
  }
  cout << "]" << endl;
}

int findMax(int *arr, int length)
{
  /*
   * STUDENT ANSWER
   */
  if (length == 1)
  {
    return arr[0];
  }
  else if (arr[0] >= arr[length - 1])
  {
    printArr(arr, length);
    return findMax(arr, length - 1);
  }
  printArr(arr, length);
  cout << " arr[length] = " << arr[length] << endl;
  arr[0] = arr[length - 1];
  return findMax(arr, length - 1);
}
//[10,11,8,12],4
//[11,8,12],3
//[8,12],2
//[12],1
// 12

int main()
{
  int arr[] = {10, 5, 7, 9, 15, 6, 11, 8, 12, 2};
  int n = sizeof(arr) / sizeof(arr[0]);
  printArr(arr, n);
  cout << "n = " << n << "; findMax = " << findMax(arr, n) << endl;
  return 0;
}
