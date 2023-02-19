#include <iostream>
#include <string.h>
using namespace std;

// Implement function
// bool isPalindrome(string str){}
// to check if the given non empty string is palindrome, else not palindrome using recursion.
// In test case, for extra point, we will have some palindrome sentences (All remaining test cases are words).

void printChar(string str)
{
  for (unsigned int i = 0; i < str.size(); i++)
  {
    cout << str[i] << " ";
  }
  cout << endl;
}

bool isPalindrome(string str)
{
  int length = str.size();
  string str_convert = str;
  if (str[0] == ' ')
  {
    str_convert = str.substr(1, length);
    length--;
    cout <<"cut head = ";
    printChar(str_convert);
  }
  if (str_convert[length - 1] == ' ')
  {
    str_convert = str_convert.substr(0, length - 1);
    length--;
    cout <<"cut tail = ";
    printChar(str_convert);
  }
  if (length <= 1)
  {
    return true;
  }
  else if (str_convert[0] == str_convert[length - 1])
  {
    string new_string = str_convert.substr(1, length - 2);
    cout << "del head tail = ";
    printChar(new_string);
    return isPalindrome(new_string);
  }
  return false;
}

int main()
{
  cout << isPalindrome(" mom ") << endl;
  cout << isPalindrome("momo") << endl;
  cout << isPalindrome("do geese see god");
  return 0;
}