#include <iostream>
#include <string>

using namespace std;
int max(int a, int b)
{
  if (a >= b)
    return a;
  return b;
}
int gcd(int a, int b)
{
  while (a != b)
  {
    if (a > b)
    {
      a = a - b;
      cout << "a = " << a << "; b = " << b << endl;
    }
    else
    {
      b = b - a;
      cout << "a = " << a << "; b = " << b << endl;
    }
  }
  return a;
}
// cách 4 dùng ước chung lớn nhất
int findLCM(int a, int b)
{
  int c = a, d = b;
  int dga = 0, lcm = 0;
  if (a == 0 || b == 0)
    return (a * b) / (a + b);

  dga = gcd(a, b);
  lcm = (c * d) / dga;
  return lcm;
}
int gcd(int a, int b)
{
  // N?u a = 0 => ucln(a,b) = b
  // N?u b = 0 => ucln(a,b) = a
  if (a == 0 || b == 0)
  {
    return a + b;
  }
  while (a != b)
  {
    if (a > b)
    {
      a -= b; // a = a - b
    }
    else
    {
      b -= a;
    }
  }
  return a; // return a or b, b?i vì lúc này a và b b?ng nhau
}

// cách 1 cơ bản nhứt
int findLCMfor(int a, int b)
{

  int maxV = a * b;
  for (int i = max(a, b); i < maxV; i++)
  {
    if (i % a == 0 && i % b == 0)
    {
      return i;
    }
  }
  return maxV;
}
int main()
{
  int a = 5, b = 7;
  int lcm = a * b / gcd(a, b);
  // printf("BCNN(%d, %d) = %d", a, b, lcm);
  cout << a << b << lcm << endl;
  cout << findLCM(5, 7) << endl;
  // cout << findLCM(10, 102) << endl; // 510
  return 0;
}
