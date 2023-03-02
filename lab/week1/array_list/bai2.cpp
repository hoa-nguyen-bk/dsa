#include <iostream>
#include <vector>
using namespace std;
bool consecutiveOnes(vector<int> &nums)
{
  int numsLength = nums.size();
  if (numsLength == 0)
  {
    return true;
  }
  int count = 0;
  bool isConsecutive = false;
  for (int i = 0; i < numsLength; i++)
  {
    if (nums[i] == 1)
    {
      count++;
      if (!isConsecutive)
      {

        isConsecutive = true;
      }
      else if (nums[i - 1] !=  1)
      {
        return false;
      }
    }
   
  }
  return true;
}
int main()
{
  vector<int> nums{0, 1, 1, 1, 9, 8};
  cout << consecutiveOnes(nums);
  // 1
  return 0;
}
