#include <iostream>

using namespace std;

int ucln(int a, int b)
{
  if (b == 0 || a == 0)
    return a + b;
  if (a == b)
    return a;
  if (a % b == 0)
  {
    cout << "a =" << a <<"; b= " << b<<" % ="<<a %b <<endl;
    return b;
  }
    cout << "a =" << a <<"; b= " << b<<" % ="<<a %b <<endl;

  return ucln(b, a % b);
}

int main()
{
  int a, b;
  cin >> a >> b;
  cout << ucln(a, b)<<endl;
}