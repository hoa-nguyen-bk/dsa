#include <iostream>
using namespace std;

// dummy head??
// memory management
// IDE: Dev C, clion (của thầy), vs code

//TODO: bài tập tổng quát
// void insertPos(T data, int pos)
// <=0 -> head
// 1 < mid <= n-1
// >=n tail


template <class T>
struct Node
{
  T data;
  Node *next;
  // này gọi là constructor, tự động gọi khi tạo object
  // nếu ko có constructor thì khi tạo dữ liệu cho A. A.
  Node(T data)
  {
    this->data = data;
    this->next = nullptr;
    // nhớ phải gán = giá trị nullptr nếu ko nó sẽ ra giá trị bậy bạ
  }
};
// SinglyLinkedList
template <class T>
class SLL
{
private:
  Node<T> *head = nullptr;

public:
  SLL()
  {
    head = nullptr;
  }
  // arrD là mảng data
  // có 3 vị trí để insert, insert vô đầu/giữa/cuối: insertH, insertM, insertT;

  //với import zô giữa
  // có p0->p1->p2. giờ mún thêm p3 vô giữa p1 và p2 thành p0->p1->p3->p2
  // giờ mún thêm an toàn xài cách p3 -> p2 trước, p1 -> p3
  // tmp = p1->next
  // tmp 
  //với import node zô đầu
  //cho head node đó = node đầu
   
  void insert(T *arrD, int size)
  {
    // vì *arrD là một địa chỉ, chỉ có 8 byte nên phải có địa chỉ để dễ chia
    for (int i = 0; i < size; i++)
    {
      // tạo node mới có data là arr = 0 , next là null
      Node<T>* node = new Node<T>(arrD[i]);
      if (head == nullptr)
      {
        head = node;
      }
      else
      {
        // giờ là trường hợp danh sách lk có hơn 1 ptu
        // mún thêm phần tử mới thì phải thêm vào pt cuối
        // giờ phải duyệt phần tử
        // tạo biến tạm tmp
        Node<T> *tmp = head;
        while (tmp != nullptr)
        {
          // trỏ tới node tiếp theo
          tmp = tmp->next;
          // bây giờ tmp đang ở địa chỉ tiếp theo
        }
        // giờ đã lấy được ptu cuối
        tmp->next == node;
      }
    }
  }
  
  //khi xóa thì chỉ cấn đổi pointer cho cái trước đó. Mà chú ý đến memory leak, khi 1 chương trình chạy, thì phải xin cấp phát vùng nhớ, thì có một số vùng nhớ ko cần xài đến, nhưng hệ đìu hành cũng ko làm đc gì nó
  // b1: xóa ra khỏi linked list
  // delN = p1->next;
  // p1->next=p2;
  // delete delN;
  // b2: delete(giải phóng memory)
  // xóa các node đầu, giữa, cuối
  // về làm cho kỹ 2 phần này
  // thứ nhất insert node tại pos bất kì
  // thứ hai del node tại pos bất kì
  // tracer tại vị trí bất kì
  void del(T data);
  // in  ra giá trị các phần tử trong linked list
  // vậy nên cần duyệt
  // mỗi lần dueejt đều cần đến tmp
  void print()
  {
    Node<T> *tmp = head;
    while (tmp != nullptr)
    {
      // in ra 
      cout << tmp->data << " -> ";
      // trỏ tới node tiếp theo
      tmp = tmp->next;
      // bây giờ tmp đang ở địa chỉ tiếp theo
    }
  }
};

int main()
{

  int arr[5] = {1, 2, 3, 4, 5};
  SLL<int> sll;
  sll.insert(arr, 5);
  sll.print();

  // int arr[] = {1, 2, 3};
  // arr là địa chỉ, của thằng đầu tiên trong mảng

  // sum(arr);

  // Node<int> A;
  // A.data = 5;
  // A.next = nullptr;
  // 3 dòng này thay thế bởi 1 dòng dưới do Node trên ko có constructor, nhưng node dưới thì có
  // Node<int> A(5);
  return 0;
}