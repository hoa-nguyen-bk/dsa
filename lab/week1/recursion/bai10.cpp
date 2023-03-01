#include <iostream>
#include <string>

using namespace std;
int mininumBracketAdd(string s)
{
  // Base case: empty string
  if (s == "") {
    return 0;
  }
  // Recursive case: first character is closing bracket
  if (s[0] == ')') {
    return 1 + mininumBracketAdd(s.substr(1));
  }
  // Recursive case: find the next closing bracket
  size_t nextClosedBracket = s.find(')');
  if (nextClosedBracket != string::npos) {
    // Remove the opening and closing brackets
    string newCutString = s.substr(1, nextClosedBracket - 1) + s.substr(nextClosedBracket + 1);
    // Recursive call with the modified string
    return mininumBracketAdd(newCutString);
  }
  // Recursive case: no closing bracket found
  return 1 + mininumBracketAdd(s.substr(1));
}

int main()
{
  cout << mininumBracketAdd("))()))()()") << endl;
  cout << mininumBracketAdd(")()))()))())())))))(") << endl;
  return 0;
}
