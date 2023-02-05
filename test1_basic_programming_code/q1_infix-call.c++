// Write function int infix_cal(const string& input) that
// takes a string in the format "<operand> <operator> <operand>"
// where <operand> is
// an integer
// is one of "+,-,*,/".
// There are just two spaces  in the input string: one to separate the first operand with the operator and one to separate the operator and the second operand. For example, infix_cal("10 + 2") must return 12.

#include <iostream>
// for string must use
#include <string>
using namespace std;

int infix_cal(const string &input)
{
  cout << "input = " << input << endl;

  int space_1 = input.find(" ");
  int space_2 = input.find(" ", space_1 + 1);
  cout << "space_1 = " << space_1 << "; space_2 = " << space_2 << endl;

  string num1_convert = input.substr(0, space_1 - 1);
  string operand_convert = input.substr(space_1 + 1, 1);
  string num2_convert = input.substr(space_2 + 1);

  int num_1 = stoi(num1_convert);
  char operand = operand_convert[0];
  int num_2 = stoi(num2_convert);
  cout << "num_1 = " << num_1 << "; operand = " << operand << "; num_2 = " << num_2 << endl;
  int result;
  switch (operand)
  {
  case '+':
    result = num_1 + num_2;
    break;

  case '-':
    result = num_1 - num_2;
    break;

  case '*':
    result = num_1 * num_2;
    break;

  case '/':
    result = num_1 / num_2;
    break;

  default:
    break;
  }

  return result;
}
int main()
{
  string input;
  // cin >> input;
  cout << infix_cal("12 + 11");
  return 0;
}