//ex2
// Định nghĩa và hiện thực countChar đếm số lần xh của 1 ktu trong 1 chuỗi
//in: chuỗi và ký tự cần đếm
//out: số lần xuất hiện của ký tự
#include <iostream>
using namespace std;

void func(int n)  
{  
   int i = 0;    
   if (n > 1)  
     func(n - 1);  
   for (i = 0; i < n; i++)  
     cout << " * ";  
}  

int main (){
  func(5);
} 