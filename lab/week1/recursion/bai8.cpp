#include <iostream>
#include <string.h>

using namespace std;
int myArrayToInt(char *str, int n)
{
  /*
   * STUDENT ANSWER
   */
  if (n == 0)
  {
    return 0;
  }
  else
  {
    // lấy phần tử cuối đổi thành số
    int digit = str[n - 1] - '0';
    cout << "digit = " << digit << endl;
    return digit + (10 * myArrayToInt(str, n - 1));
  }
}
int main()
{
  char str[] = "2020";
  printf("%d", myArrayToInt(str, 4)); // 2020
  return 0;
}
