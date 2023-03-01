#include <iostream>
#include <string>

using namespace std;

int gcd(int a, int b)
{
  if (a == b)
    return a;
  if (a > b)
  {
    a = a - b;
  }
  else
  {
    b = b - a;
  }
  return gcd(a, b);
}
// cách 4 dùng ước chung lớn nhất
int findLCM(int a, int b)
{
  int c = a, d = b;
  int dga = 0, lcm = 0;
  if (a == 0 || b == 0)
    return a + b;

  dga = gcd(a, b);
  lcm = (c * d) / dga;
  return lcm;
}

int main()
{

  cout << findLCM(5, 7) << endl;
  // cout << findLCM(10, 102) << endl; // 510
  return 0;
}
