#include <iostream>
using namespace std;

// Nội dung buổi 2
// - class
// - các thuộc tính oop
// +Tính đóng gói encapsulation: gom tất cả và gói gọn lại trong class student
class student
{
 
public:          // các đối tượng bên ngoài có thể truy cập vào bên trong class
  int ID = 10;
  void callName()
  {
    cout << ID;
  }

  
};
int main()
{
  student A;
  A.callName(); // có hiện duy nhất name vì nó được quyền truy cập vào name
  A.ID = 20;
  A.callName();
  //vậy nếu muốn id ko đổi được thì để id vào private
  return 0;
}