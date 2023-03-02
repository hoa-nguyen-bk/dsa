#include <iostream>
#include <vector>
using namespace std;
void printVector(const vector<int> &vec)
{
  for (int i = 0; i < vec.size(); ++i)
    cout << vec[i] << " ";
  cout << endl;
}
vector<int> updateArrayPerRange(vector<int> &nums, vector<vector<int>> &operations)
{
  int numLength = nums.size();
  int operationsLength = operations.size();
  cout << operationsLength << " - " << numLength << endl;
  vector<int> resultVector(nums);
  for (int i = 0; i < operationsLength; i++)
  {
    int l = operations[i][0];
    int r = operations[i][1];
    int x = operations[i][2];
    cout << "l = " << l << "; r = " << r << "; x = " << x << endl;

    for (int n = 0; n < numLength; n++)
    {
      if (n >= l && n <= r)
      {
        int newValue = resultVector[n] + x;
        cout << "newValue + x = " << newValue << endl;
        resultVector.erase(resultVector.begin() + n);
        resultVector.insert(resultVector.begin() + n, newValue);
      }
      else
      {
        int newValue = resultVector[n];
        cout << "newValue = " << newValue << endl;
        resultVector.erase(resultVector.begin() + n);
        resultVector.insert(resultVector.begin() + n, newValue);
      }
    }
    printVector(resultVector);
  }
  return resultVector;
}

int main()
{
  vector<int> nums{13, 0, 6, 9, 14, 16};
  printVector(nums);
  vector<vector<int>> operations{{5, 5, 16}, {3, 4, 0}, {0, 2, 8}};
  printVector(updateArrayPerRange(nums, operations));
  // [21, 8, 14, 9, 14, 32]

  return 0;
}
