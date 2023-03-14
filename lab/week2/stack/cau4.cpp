#include <iostream>
#include <stack>

using namespace std;
bool isValidParentheses(string s)
{
  stack<char> parentheses;
  for (char c : s)
  {
    cout << "outside if"<<endl;
    if (c == '(' || c == '[' || c == '{')
    {
      cout << "first par " << c << "." << endl;
      parentheses.push(c);
    }
    else if (c == ')' || c == ']' || c == '}')
    {
      cout << "closed par " << c << "." << endl;
      if (parentheses.empty())
      {
        return false;
      }
      char top = parentheses.top();
      cout << "Top = " << top << ";" << endl;
      if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '}'))
      {
        return false;
      } else if ((c == ')' && top == '(') || (c == ']' && top == '[') || (c == '}' && top == '}')){

      parentheses.pop();
       }
    }
    
  }
  return parentheses.empty();
}
int main()
{
  // cout << isValidParentheses("[]");
  // 1
  // cout << isValidParentheses("[]()");
  // 1
  // cout << isValidParentheses("[)");
  // 0
  cout << isValidParentheses("[)]");
  return 0;
}
