// TODO: bài tập tổng quát
//  void insertPos(T data, int pos), deletePos, tracerPos
//  <=0 -> head
//  1 < mid <= n-1
//  >=n tail

#include <iostream>
using namespace std;

// cấu trúc template, cuối template ko có dấu ;
template <class T>

// cấu trúc node
struct Node
{
  T data;
  // ở đây phải là 1 con trỏ, vì ở đây là tham chiếu lấy giá trị địa chỉ tiếp theo mà
  Node *next;
  // ở đây phải có thêm 1 constructor, được tự động gọi khi tạo object
  Node(T data)
  {
    // chỗ này sử dụng con trỏ this chứ ko sử dụng . nha
    this->data = data;
    this->next = nullptr;
  }
  // phải có dấu ; khi hết struct
};

// phải định nghĩa lại template trước khi định nghĩa class dưới, bất kì chỗ nào có node thì phải có template này nhé
template <class T>

// cấu trúc class và các hàm ố dề
class SLL
{
  // là thuộc tính private nên class con không lấy được, bên ngoài cũng không lấy được
private:
  // cú pháp <kiểu dữ liệu><mẫu template muốn đưa vào, với template được cho ở trên> <tên bạn mún đặt> đó là cú pháp sai ở trong này
  //  Node<T> node;
  //  cú pháp đúng là sau, con trỏ head dùng để track tới cái node đầu tiên của 1 linked list => đây là khởi tạo cho not đầu tiên, mà node đầu tiên xuất hiện có thể là node duy nhất nên phải để giá trị con trỏ next là nullptr
  //  suy ra head trong dòng này chính là tên của node đầu tiên, node khởi tạo, head là con trỏ trỏ tới
  Node<T> *head;

public:
  SLL()
  {
    // nhờ đây khi tạo class thì sẽ tự khai báo một cái node head với giá trị null pointer
    head = nullptr;
  }
  // kết thúc class phải có ;
};

int main()
{
  SLL<int> mynode;

  return 0;
}