#include <iostream>
using namespace std;

// Nội dung buổi 2
// - class
// - các thuộc tính oop
// +Tính đóng gói encapsulation: gom tất cả và gói gọn lại trong class student
class student
{
  // và còn 100 thuộc tính phụ nữa để bổ sung cho các thuộc tính này
  // có thể có thêm các hàm

  // sự khác nhau giữa public, private, protected
  string school; // mặc định sẽ là private
public:          // các đối tượng bên ngoài có thể truy cập vào bên trong class
  string name;

private: // các dữ liệu quan trọng nên để private
  int ID;

protected:
  void callName()
  {
    cout << 123;
  }
};
int main()
{
  student A;
  A.name; // có hiện duy nhất name vì nó được quyền truy cập vào name
  // A.ID;   // Sẽ bị báo lỗi liền, vì nó là thuộc tính private của student
  return 0;
}