#include <iostream>
#include <string.h>

using namespace std;
int myArrayToInt(char *str, int n) 
{ 
    /*  
     * STUDENT ANSWER
     */ 
     if(n == 0) return 0;
     int digit = str[n-1] -'0';
     return digit + (10*myArrayToInt(str,n-1));
     
}
int main()
{
  char str[] = "2020";
  printf("%d", myArrayToInt(str, 4)); // 2020
  return 0;
}
