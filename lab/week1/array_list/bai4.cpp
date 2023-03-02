#include <iostream>
#include <vector>
#include <string>
using namespace std;

int longestSublist(vector<string> &words)
{
  if (words.empty())
  {
    return 0;
  }
  vector<pair<char, int>> arrayCount = {};
  for (int i = 0; i < words.size(); i++)
  {
    char firstChar = words[i][0];
    bool found = false;
    if (arrayCount.size() == 0)
    {
      arrayCount.push_back({firstChar, 1});
    }
    else
    {

      for (int j = 0; j < arrayCount.size(); j++)
      {
        char arrayCountFirstChar = arrayCount[j].first;
        if (firstChar == arrayCountFirstChar)
        {
          found = true;
          arrayCount[j].second++;
        }
      }
      if (!found)
      {
        arrayCount.push_back({firstChar, 1});
      }
    }
  }
  int longest = 0;
  for (auto p : arrayCount)
  {
    if (p.second > longest)
      longest = p.second;
  }

  return longest;
}

int main()
{
  vector<string> words{"faction", "fight", "and", "are", "attitude"};
  cout << longestSublist(words);
  // 3
  return 0;
}
