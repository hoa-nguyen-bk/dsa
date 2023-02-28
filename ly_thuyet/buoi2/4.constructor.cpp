#include <iostream>
using namespace std;

// Nội dung buổi 2
// - class
// - các thuộc tính oop
// +Tính đóng gói encapsulation: gom tất cả và gói gọn lại trong class student
// +Constructor
// +Inheritance -> kế thừa
// DRY => dont repeat yourself
class people
{
private:
  int ID = 0;

public:
  void callName()
  {
    cout << ID << endl;
  };
};
// thuộc tính protected đem xún class con được, nhưng private thì ko

class student : public people
{
  void print()
  {
    cout << "stu";
  }
};
int main()
{
  people A;
  A.callName();
  student B;
  B.callName();
  return 0;
}