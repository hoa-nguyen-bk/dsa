#include <iostream>

using namespace std;
int findGCD(int a, int b)
{
      if (b == 0 || a == 0)
    return a + b;
  if (a == b)
    return a;
  if (a % b == 0)
  {
    return b;
  }

  return findGCD(b, a % b);
}

int main()
{
  int a, b;
  cin >> a >> b;
  cout << ucln(a, b)<<endl;
}