#include <iostream>
using namespace std;

// dummy head??
// memory management
// IDE: Dev C, clion (của thầy), vs code

//bài tập tổng quát
// void insertPos(T data, int pos)

template <class T>
struct Node
{
  T data;
  Node *next;
  // này gọi là constructor, tự động gọi khi tạo object
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
  SLL()
  {
    head = nullptr;
  }

public:
  // arrD là mảng data
  void insert(T *arrD, int size)
  {
    // vì *arrD là một địa chỉ, chỉ có 8 byte nên phải có địa chỉ để dễ chia
    for (int i = 0; i < size; i++)
    {
      // tạo node mới có data là arr = 0 , next là null
      Node<T> *node(arrD[i]);
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
  // có 3 vị trí để insert, insert vô đầu/giữa/cuối: insertH, insertM, insertT;

  //với import zô giữa
  //với import node zô đầu
  //cho head node đó = node đầu
   
  void del(T data);
  // in  ra giá trị các phần tử trong linked list
  // vậy nên cần duyệt
  // mỗi lần dueejt đều cần đến tmp
  void print()
  {
    Node<T> *tmp = head;
    while (tmp != nullptr)
    {
      // trỏ tới node tiếp theo
      tmp = tmp->next;
      // bây giờ tmp đang ở địa chỉ tiếp theo
    }
  }
};

int main()
{

  int arr[5] = {1, 2, 3, 4, 5};
  // SLL<int> sll;

  // int arr[] = {1, 2, 3};
  // arr là địa chỉ, của thằng đầu tiên trong mảng

  // sum(arr);

  // Node<int> A;
  // A.data = 5;
  // A.next = nullptr;
  // 3 dòng này thay thế bởi 1 cái nào đó
  return 0;
}