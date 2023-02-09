#include <iostream>
using namespace std;

//typedef giúp cho code dễ đọc dễ maintain, alias ptr có ý nghĩa hơn int * trong cái ex này
typedef int *ptr;

int main()
{
  ptr x;
  int y = 10;
  // gán địa chỉ y cho x
  x = &y;
  // giá trị y được truy cập thông qua con trỏ x
  cout << *x << endl;
  return 0;
}