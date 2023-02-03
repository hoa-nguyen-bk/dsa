#include <iostream>
using namespace std;

// Nội dung buổi 2
// - class
// - các thuộc tính oop
// +Tính đóng gói encapsulation: gom tất cả và gói gọn lại trong class student
// +Constructor
// +Inheritance -> kế thừa
// DRY => dont repeat yourself
// + template

int sum(int a, int b){

};

float sum(float a, float b){

};

double sum(double a, double b){

};

// cùng kdl
template <class T>
T sum(T a, T b)
{
  return a + b;
}

// khác kdl
template <class T, class Y>
T sumk(T a, Y b)
{
  return a + b;
}

class SSL
{
};

int main()
{
  int a = sum(2, 3);
  float b = sum(2.1, 2.2);
  double c = sumk(2.3, 1);
  cout << a << b << c;
  return 0;
}