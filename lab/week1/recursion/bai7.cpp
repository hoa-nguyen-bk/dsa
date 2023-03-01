#include <iostream>
#include <string>

using namespace std;

void printHailstone(int number)
{
  /*
   * STUDENT ANSWER
   */

  if (number <= 1)
  {

    cout << number << endl;
  }
  else if (number % 2 == 0)
  {
    cout << number << ' ';
    int even = number / 2;
    printHailstone(even);
  }
  else
  {
    cout << number << ' ';
    int odd = number * 3 + 1;
    printHailstone(odd);
  }
}

int main()
{
  printHailstone(11);
  return 0;
}
