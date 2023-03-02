#include <iostream>
#include <vector>
#include <string>
using namespace std;

int equalSumIndex(vector<int> &nums)
{
  int numsLength = (int)nums.size();
  if (numsLength == 0)
    return -1;
  if (numsLength == 1)
    return 0;
  if (numsLength == 2)
    return -1;
  int index = -1;
  for (int i = 1; i < numsLength; i++)
  {
    int sumLeft = 0;
    int sumRight = 0;
    for (int left = 0; left < i; left++)
    {
      sumLeft += nums[left];
    }
    for (int right = numsLength - 1; right > i; right--)
    {
      sumRight += nums[right];
    }
    if (sumLeft == sumRight)
    {
      index = i;
    }
  }
  return index;
}

int main()
{
  vector<int> nums{3, 5, 2, 7, 6, 4};
  cout << equalSumIndex(nums) << endl;
  // 3
  return 0;
}
