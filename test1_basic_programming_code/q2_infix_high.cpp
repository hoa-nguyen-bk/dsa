// In the previous implementation of function infix_cal, a nested if would be used to compare the input operator with expected operators like "+", "-",... This approach requires changing the nested if when there are more operators. 

// In this exercise, the function must not use such a nested if but it must use a loop over an array that contains a struct of an operator string and a function pointer.

// Assume that the following definitions have been declared for your usage:

// struct action {
//     string op; // operator
//     int (*func)(int, int); // function pointer to corresponding function
// };

// int myadd(int x, int y) { return x + y;}

// int mymin(int x, int y) { return x - y;}

// int mymul(int x, int y) { return x * y;}

// int mydiv(int x, int y) { return x / y;}

// Your code starts at line 20.
//Hết cái đề


#include <iostream>
#include <string>
using namespace std;

struct action {
    string op; // operator
    int (*func)(int, int); // function pointer to corresponding function
};

int myadd(int x, int y) { return x + y;}
int mymin(int x, int y) { return x - y;}
int mymul(int x, int y) { return x * y;}
int mydiv(int x, int y) { return x / y;}

int infix_cal(const string &input)
{
  const int num_actions = 4;
  action actions[num_actions] = {
      {"+", myadd},
      {"-", mymin},
      {"*", mymul},
      {"/", mydiv},
  };
  int space_1 = input.find(" ");
  int space_2 = input.find(" ", space_1 + 1);
  string num1_convert = input.substr(0, space_1);
  string operand_convert = input.substr(space_1 + 1, 1);
  string num2_convert = input.substr(space_2 + 1);
  int num_1 = stoi(num1_convert);
  int num_2 = stoi(num2_convert);
  int result = 0;

  for (int i = 0; i < num_actions; i++)
  {
    if (operand_convert == actions[i].op)
    {
      result = actions[i].func(num_1, num_2);
      break;
    }
  }

  return result;
}


int main()
{
  string input;
  getline(cin, input);
  cout << infix_cal(input) << endl;
  return 0;
}
