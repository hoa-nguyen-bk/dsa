#include <iostream>
using namespace std;

// Nội dung buổi 2
// - class
// - các thuộc tính oop
// +Tính đóng gói encapsulation: gom tất cả và gói gọn lại trong class student
// +Constructor
class student
{
private:
  int ID = 10;

public: // các đối tượng bên ngoài có thể truy cập vào bên trong class
  // constructor
  student(int ID)
  {
    this->ID = ID;
    cout << "Hello" << endl;
  }
  // destructor
  ~student()
  {
    cout << "Good bye" << endl;
  }
  void callName()
  {
    cout << ID;
  }
};
int main()
{
  student A(5);
  A.callName(); // có hiện duy nhất name vì nó được quyền truy cập vào name
  // vậy nếu muốn id ko đổi được thì để id vào private
  return 0;
}