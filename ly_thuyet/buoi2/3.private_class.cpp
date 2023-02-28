#include <iostream>
using namespace std;

// Nội dung buổi 2
// - class
// - các thuộc tính oop
// +Tính đóng gói encapsulation: gom tất cả và gói gọn lại trong class student
class student
{
 private:

  int ID = 10;
public:          // các đối tượng bên ngoài có thể truy cập vào bên trong class
  void callName()
  {
    cout << ID;
  }

  
};
int main()
{
  student A;
  A.callName(); // có hiện duy nhất name vì nó được quyền truy cập vào name
  //vậy nếu muốn id ko đổi được thì để id vào private
  A.ID = 20; //nên chỗ này báo lõi là đúng
  A.callName();
  return 0;
}