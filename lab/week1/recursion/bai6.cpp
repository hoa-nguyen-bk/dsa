#include <iostream>
#include <string>

using namespace std;

string repeat(string s, int n)
{
  if (n == 1)
  {
    return s;
  }
  else
  {
    return s + repeat(s, n - 1);
  }
}

string extractSubstring(string s, int i, int countBracket)
{
  if (countBracket == 0)
  {
    return "";
  }
  else
  {
    string str = "";
    str += s[i];
    if (s[i] == ')')
    {
      return str + extractSubstring(s, i + 1, countBracket - 1);
    }
    else if (s[i] == '(')
    {
      return str + extractSubstring(s, i + 1, countBracket + 1);
    }
    return str + extractSubstring(s, i + 1, countBracket);
  }
}

string expand(string s)
{
  int length = s.length();
  if (length == 0)
  {
    return "";
  }
  else if (length == 1)
  {
    return s;
  }
  else if (isdigit(s[0]))
  {
    int num = s[0] - '0'; // chuyển thành số cho cái số đầu tiên
    int i = 2;
    int countBracket = 1;

    string str = extractSubstring(s, i, countBracket);

    string rest = s.substr(str.length() + 2);
    string newString = str.substr(0, str.length() - 1);
    if (num == 0)
    {
      // nếu số đầu là số 0 thì cắt số 1 và dấu () của số 1 -> chưa đúng
      return expand(rest);
    }
    return repeat(expand(newString), num) + expand(rest);
  }
  else
  {
    return s[0] + expand(s.substr(1));
  }
}

int main()
{
  // cout << expand("2(ab3(cde)x)") << "\n"; // output: abcdecdecdexabcdecdecdex
  // bug here
  cout << "------------- " << endl;
  cout << "second string: " << endl;
  cout << expand("2(x0(y))3(z)") << "\n"; // output: xxzzz
  return 0;
}
