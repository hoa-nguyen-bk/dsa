#include <iostream>
#include <string>

using namespace std;
int mininumBracketAdd(string s)
{
  cout << "1 vong"<<endl;
  // STUDENT ANSWER
  if (s == "")
  {
    return 0;
  }
  char firstChar = s[0];
  if (firstChar == '(')
  {
    int nextClosedBracket = s.find(')');
    cout << "firstChar = " << firstChar << "; next cloase = " << nextClosedBracket << endl;
    if (nextClosedBracket != -1)
    {
      string newCutString = s.substr(1, nextClosedBracket - 2);
      if (nextClosedBracket == s.length() - 1)
      {
        string rest = s.substr(nextClosedBracket);
        string finalString = newCutString + rest;
        cout << "finalString = " << finalString << endl;
        return mininumBracketAdd(finalString);
      }
      cout << "newCutString = " << newCutString << endl;
      return mininumBracketAdd(newCutString);
    }
    cout << "them 1 cai" << endl;
  }
  return 3;
}
int main()
{
  // cout << mininumBracketAdd("(((") << endl;   // 5
  // cout << mininumBracketAdd("(()") << endl;   // 5
  cout << mininumBracketAdd("(()(") << endl;  // 5
  // cout << mininumBracketAdd(")))((") << endl; // 5
  return 0;
}
