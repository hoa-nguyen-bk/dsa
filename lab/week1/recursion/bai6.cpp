#include <iostream>
#include <string>
#include <stack>

using namespace std;

string expand(string s) {
  int length = s.length();
    if (length == 0) {
        return "";
    } else if (length == 1) {
        return s;
    } else if (isdigit(s[0])) {
        int num = stoi(s[0]);//chuyển thành số cho cái số đầu tiên
        if(num == 1){
          //nếu số đầu là số 1 thì cắt số 1 và dấu ()
          return s.substr(2, length-2);
        }
        string str = "";
        int i = 2; // Skip the opening bracket
        while (s[i] != ')') {
            str += s[i];
            i++;
        }
        string rest = s.substr(i + 1);
        return string(num, expand(str)) + expand(rest);
    } else {
        return s[0] + expand(s.substr(1));
    }
}


// chat gpt ver
string expandwhile(string s)
{
  int i = 0;
  string res = "";

  while (i < s.length())
  {
    if (isdigit(s[i]))
    {
      int n = s[i] - '0';
      i += 2; // skip the digit and the '('
      int j = i, cnt = 1;
      while (cnt > 0)
      {
        if (s[j] == '(')
          cnt++;
        else if (s[j] == ')')
          cnt--;
        j++;
      }
      string p = s.substr(i, j - i - 1);
      for (int k = 0; k < n; k++)
      {
        res += expand(p);
      }
      i = j;
    }
    else if (islower(s[i]))
    {
      res += s[i];
      i++;
    }
    else
    {
      i++;
    }
  }

  return res;
}

// my ver
string myexpand(string s)
{
}

int main()
{
  int a, b;
  cout << string(3, "he") <<endl;
  // cout << expand("2(ab3(cde)x)") << endl; // output: abcdecdecdexabcdecdecdex
  // cout << expand("2(x0(y))3(z)") << endl; // output: xxzzz
  return 0;
}