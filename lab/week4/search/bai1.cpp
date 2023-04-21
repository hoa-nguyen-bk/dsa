#include <iostream>

using namespace std;
int binarySearch(int arr[], int left, int right, int x)
{
  if (right >= left)
  {
    int mid = left + (right - left) / 2;
    cout << "We traverse on index: " << mid << endl;
    if (arr[mid] == x)
    {
      return mid;
    }
    if (arr[mid] > x)
      return binarySearch(arr, left, mid - 1, x);
    return binarySearch(arr, mid + 1, right, x);
  }
  return -1;
}
int main()
{
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int x = 10;
  int n = sizeof(arr) / sizeof(arr[0]);
  int result = binarySearch(arr, 0, n - 1, x);
  (result == -1) ? cout << "Element is not present in array"
                 : cout << "Element is present at index " << result;
  return 0;
}
