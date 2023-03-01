#include <iostream>
#include <string>

using namespace std;
int mininumBracketAdd(string s)
{
  if (s == "")
    return 0;
  if (s[0] == ')')
    return 1 + mininumBracketAdd(s.substr(1));
  unsigned int nextClosedBracket = s.find(')');
  if (nextClosedBracket != string::npos)
  {
    string newCutString = s.substr(1);
    newCutString.erase(1, nextClosedBracket);
    if (nextClosedBracket != s.length() - 1)
    {
      string rest = s.substr(nextClosedBracket + 1);
      string finalString = newCutString + rest;
      return mininumBracketAdd(finalString);
    }
    return mininumBracketAdd(newCutString);
  }
  return 1 + mininumBracketAdd(s.substr(1));
}
int main()
{
  cout << mininumBracketAdd("))()))()()") << endl;
  cout << mininumBracketAdd(")()))()))())())))))(") << endl;
  return 0;
}
