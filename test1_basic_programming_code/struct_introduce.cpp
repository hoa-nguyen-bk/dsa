#include <iostream>
using namespace std;

int add(int a, int b)
{
  return a + b;
}

int subtract(int a, int b)
{
  return a - b;
}
struct action
{
  string op;
  int (*func)(int, int);
};

int main()
{
  action actions[2] = {
      {"+", add},
      {"-", subtract}};

  int a = 10,
      b = 5;
  for (int i = 0; i < 2; i++)
  {
    cout << actions[i].op << " = " << actions[i].func(a, b) << endl;
  }
  // cout << (*func)(5,10) << endl;
  return 0;
}
