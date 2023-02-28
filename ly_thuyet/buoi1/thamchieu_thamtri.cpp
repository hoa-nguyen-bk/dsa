#include <iostream>
using namespace std;

// truyền tham khảo  --> & <--
void inc1(int &a)
{
  ++a;
}
void inc2(int a)
{
  ++a;
}
int main()
{
  int x = 5;
  // truyền tham khảo
  inc1(x);
  cout << x << "\n";
  // truyền tham trị
  inc2(x);
  cout << x;
}