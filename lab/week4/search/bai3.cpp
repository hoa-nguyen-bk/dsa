#include <iostream>
#include <cmath>

using namespace std;

int jumpSearch(int arr[], int x, int n)
{
  int step = sqrt(n);
  int prev = 0;
  cout << prev << " ";

  while (arr[step - 1] < x && step < n)
  {
    prev = step;
    cout << prev << " ";
    step += sqrt(n);
  }
  cout << "step = " << step << "; n = " << n << endl;
  cout << "prev = " << prev << endl;
  if (arr[prev] != x && arr[step] < x && step < n - 1)
  {
    cout << step << " ";
  }
  cout << arr[prev] << endl;
  // If we reached next block or end of
  // array, element is not present.
  while (arr[prev] < x)
  {
    cout << "arr[prev] < x)" << endl;
    prev++;
    cout << prev << " ";
    // If we reached next block or end of
    // array, element is not present.
    if (prev == min(step, n))
      return -1;
  }
  // If element is found
  if (arr[prev] == x)
    return prev;
  return -1;
}

int main()
{
  int arr[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 611, 612, 613, 1000, 1002, 2000, 2003, 2004, 2005, 2006};
  int x = 36;
  int n = sizeof(arr) / sizeof(arr[0]);
  int index = jumpSearch(arr, x, n);

  if (index != -1)
  {
    cout << "\nNumber " << x << " is at index " << index;
  }
  else
  {
    cout << "\n"
         << x << " is not in array!";
  }

  return 0;
}
