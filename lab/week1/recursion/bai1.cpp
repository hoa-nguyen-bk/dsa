#include <iostream>
using namespace std;

// Implement function
// void printArray(int n){}
// to print 0, 1, 2, ..., n (n is positive integer and has no space at the end).

void printArray(int n) {
    if (n == 0) {
        cout << n;
    } else {
        printArray(n-1);
        cout << ", " << n;
    }
}
//vd print array(2)
//loop1
//printArray(1), 2
//loop2
//printArray(0), 1, 2
//loop3
//0, 1, 2
int main()
{
  printArray(5);
  return 0;
}