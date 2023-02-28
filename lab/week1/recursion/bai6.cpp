#include <iostream>
#include <string>
#include <stack>

using namespace std;

// cần thêm hàm repeat đệ quy phụ cho
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

string expand(string s)
{
  if (s.length() == 0)
  {
    return "";
  }
  else if (s.length() == 1)
  {
    return s;
  }
  else if (isdigit(s[0]))
  {
    int num = s[0] - '0';
    string str = "";
    int i = 2; // Skip the opening bracket
    int count = 1;
    while (count != 0)
    {
      if (s[i] == '(')
      {
        count++;
      }
      else if (s[i] == ')')
      {
        count--;
      }
      str += s[i];
      i++;
    }
    string rest = s.substr(i);
    return repeat(expand(str.substr(1, str.length() - 2)), num) + expand(rest);
  }
  else
  {
    return s[0] + expand(s.substr(1));
  }
}

int main()
{

  cout << expand("2(ab3(cde)x)") << endl; // output: abcdecdecdexabcdecdecdex
  cout << expand("2(x0(y))3(z)") << endl; // output: xxzzz
  return 0;
}