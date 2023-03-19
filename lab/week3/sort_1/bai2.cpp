#include <iostream>
using namespace std;

template <class T>
class Sorting
{
public:
  /* Function to print an array */
  static void printArray(T *start, T *end)
  {
    int size = end - start;
    for (int i = 0; i < size - 1; i++)
      cout << start[i] << ", ";
    cout << start[size - 1];
    cout << endl;
  }

  static void selectionSort(T *start, T *end);
};
//________Start copy________
template <class T>
void Sorting<T>::selectionSort(T *start, T *end)
{
  int size = end - start;
  int *arr = start;

  for (int st = 0; st < size - 1; ++st)
  {
    int min_idx = st;
    for (int i = min_idx + 1; i < size; ++i)
    {
      if (arr[min_idx] > arr[i])
        min_idx = i;
    }
    swap(arr[st], arr[min_idx]);
    printArray(start, end);
  }
}
//________End copy________

int main()
{
  int arr[] = {9, 2, 8, 1, 0, -2};
  Sorting<int>::selectionSort(&arr[0], &arr[6]);
  return 0;
}
