#include <iostream>
#include <vector>
#include <string>
using namespace std;

int equalSumIndex(vector<int> &nums)
{
  int numsLength = (int)nums.size();
  cout << "numsLength = " << numsLength << endl;
  if (numsLength <= 2)
    return -1;
  int index = -1;
  for (int i = 1; i < numsLength; i++)
  {
    int sumLeft = 0;
    int sumRight = 0;
    for (int left = 0; left < i; left++)
    {
      cout << "nums[" << left << "] = " << nums[left] << endl;
      sumLeft += nums[left];
    }
    for (int right = numsLength - 1; right > i; right--)
    {
      cout << "nums[" << right << "] = " << nums[right] << endl;
      sumRight += nums[right];
    }
    cout << "sumLeft = " << sumLeft << "; sumRight = " << sumRight << endl;
    if (sumLeft == sumRight)
    {
      cout << "index = " << index << endl;
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
