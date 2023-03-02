#include <iostream>
#include <algorithm>
using namespace std;

int buyCar(int *nums, int length, int k)
{
  sort(nums, nums + length);
  cout << "sortArr = " << endl;
  for (int i = 0; i < length; i++)
  {
    cout << "arr[" << i << "]" << nums[i] << endl;
  }
  int i = 0, things = 0;
  while (k > 0)
  {
    things++;
    k = k - nums[i];
    i++;
  }
  return things;
}

int main()
{
  int nums[] = {90, 30, 40, 90, 20};
  int length = sizeof(nums) / sizeof(nums[0]);
  cout << buyCar(nums, length, 90) << "\n";
  // 3

  return 0;
}
