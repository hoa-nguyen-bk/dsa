#include <iostream>
using namespace std;
// Given a positive number, print following a pattern without using any loop.

// Input: n = 16
// Output: 16, 11, 6, 1, -4, 1, 6, 11, 16 (has no space at the end)

// Input: n = 10
// Output: 10, 5, 0, 5, 10 (has no space at the end)

// pr(10)
// loop1
// 10, pr(5), 10
// loop2
// 10, 5, pr(0), 5, 10
// loop3
// 10, 5, 0, 5, 10

// We basically first reduce 5 one by one until we reach a negative or 0. After we reach 0 or negative, we one add 5 until we reach n.

void printPattern(int n)
{
  /*
   * STUDENT ANSWER
   */
  if (n <= 0)
  {
    cout << n;
  } else {

  // in đầu
  cout << n << " ";
  // in giữa
  printPattern(n - 5);
  // in cuối
  cout << " " << n;
  }
}

//n = 10;
//10, pr(5), 10
//10, 5, pr(0), 5, 10

int main()
{
  printPattern(10);
  return 0;
}