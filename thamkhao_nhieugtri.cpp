#include <iostream>
using namespace std;
// tính trung bình
//  cho 2 giá trị h và w
// nhiều tham khảo thì cho nhiều giá trị
void avg(int a, int b, double &avg_h, double &avg_w)
{
  ++avg_h;
  ++avg_w;
}
int main()
{
  double avg_h = 1;
  double avg_w = 1;
  avg(1, 2, avg_h, avg_w);
  cout << avg_h << " - " << avg_w;
}