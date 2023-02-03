//cho đoạn code sau, liệt kê các ptu của mảng sau khi thực hiện các lệnh ở cmt (1), (2,3)

#include <iostream>
using namespace std;

int main()
{
  int list[7] = {3, 9, 2, 99, 35, 11, 7};

  int *p = list;
  cout << "p = " << *p << "\n";

  *p = *p+2;
  cout << "p = " << *p;
  return 0;
}
