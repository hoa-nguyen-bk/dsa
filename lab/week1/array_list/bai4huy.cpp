#include <iostream>
#include <vector>
#include <string>
using namespace std;

int longestSublist(vector<string> &words)
{
  int wordLength = (int)words.size();
  if (words.empty())
    return 0;
  if (wordLength == 1)
    return 1;
  int c, res;
  c = res = 1;
  for (int i = 1; i < wordLength; i++)
  {
    if (words[i][0] == words[i - 1][0])
    {
      c++;
      if (c > res)
        res = c;
    }
    else
      c = 1;
  }
  return res;
}

int main()
{
  vector<string> words{"faction", "fight", "and", "are", "attitude"};
  cout << longestSublist(words);
  // 3
  return 0;
}
