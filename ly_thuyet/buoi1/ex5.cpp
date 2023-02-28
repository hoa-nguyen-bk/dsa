// làm cacsch nào để thu hồi vùng nhớ đc cấp phát động

#include <iostream>
using namespace std;

int copyArray(int list[], int size)
{
  int *p2 = new int[7];
  for (int i = 0; i < 7; i++)
  {
    p2[i] = list[i];
  }
  return *p2;
}

int main()
{
  int list[7] = {3, 9, 2, 99, 35, 11, 7};
  int arr[7] = copyArray(list, 7);
  for (int i = 0; i < 7; i++)
  {
    cout << "p = " << arr[i];
  }
  return 0;
}
