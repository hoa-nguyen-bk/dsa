// TODO: bài tập tổng quát
//  void insertPos(T data, int pos), deletePos, tracerPos
//  <=0 -> head
//  1 < mid <= n-1
//  >=n tail

#include <iostream>
using namespace std;

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
  Node<T> *head = nullptr;

public:
  SLL()
  {
    // nhờ đây khi tạo class thì sẽ tự khai báo một cái node head với giá trị null pointer
    head = nullptr;
  }

  // đầu tiên thêm một pần tử vào thì thường thêm ở tail, ở đây hàm insertTail nhận vô 2 tham số là T, T chính là template ở trên mà mình cho người dùng truyền zô, rồi tới size, thầy nói size là phải truyền zô chứ ko dùng hàm hay phép toán chia chia nha, tại đây là con trỏ *arrD chứ ko phải là chính arrD, nhớ kĩ là cái *arrD khác size với arrD chứ ko bị lừa
  void insertTail(T *arrD, int size)
  {
    for (int i = 0; i < size; i++)
    {
      // Chỗ ni nó báo là invalid conversion from 'int' to 'Node<int>*' , tại vì nó bắt mình phải cấp vùng nhớ cho nó chứ ko làm zầy đc
      // Node<T> *node(arrD[i]);
      // nên mình viết lại cú pháp như vầy
      Node<T> *node = new Node<T>(arrD[i]);
      if (head == nullptr)
      {
        head = node;
      }
      else
      {
        // và biến tạm này bắt đầu từ head trước
        Node<T> *tmp = head;
        // khi nào gặp null thì khi đó là phần tử cuối cùng cần tìm rồi đó
        while (tmp->next != nullptr)
        {
          // mà nếu chưa phải cái mình cần tìm thì tmp->next là cái cục mình cần tìm tiếp theo
          tmp = tmp->next;
          // cout << tmp->data;
        }
        // khúc này phải coi bài giảng cho thiệt dễ hiểu
        tmp->next = node;
      }
    }
  }
  void insertMid(T dataInsert, int position)
  {
    int index = 0;
    Node<T> *nodeAfter = head;
    // cout << "nodeAfter = " << nodeAfter->data << ": " << nodeAfter->next << endl;
    Node<T> *nodeAdded = new Node<T>(dataInsert);
    Node<T> *nodeBefore = new Node<T>(nodeAfter->data);
    while (index != position)
    {
      index++;
      // cout << "index = " << index << endl;
      nodeBefore = nodeAfter;
      // cout << "nodeBefore = " << nodeBefore->data << endl;
      nodeAfter = nodeAfter->next;
      // cout << "nodeAfter->data = " << nodeAfter->data << endl;
    }

    // giờ là vế nếu index = position, hiện tại cái tmp đang đứng ở cái node típ theo
    //đầu tiên cho thằng vị trí típ theo của added là after 
    nodeAdded->next = nodeAfter;
    //tiếp theo cho vị trí cũ là added
    nodeBefore->next = nodeAdded;
    // nodeBefore->next= nodeAdded;
  }
  void insertHead(int dataInsert){
    Node<T> *new_head = new Node<T>(dataInsert);
    new_head->next = head;
    // cout << "new_head = " << new_head->data << ": " << new_head->next << endl;
    head = new_head;
  }
  void delR(T delData){
    // cout << "head = " << head << endl;
    Node<T> *tmp = head;
    while(tmp->next->data != delData){
      tmp= tmp->next;
    }
    // hiện tại node cần xóa delNode = tmp->next;
    Node<T> *delNode = tmp->next;
    tmp->next = tmp->next->next;
    delete delNode;
  }
  void delH(){
    Node<T> *delNode = head;
    head = head->next;
    delete delNode;
  }
  void print()
  {

    Node<T> *tmp = head;
    // nếu mà viết tmp->next thế này thì nó còn lâu mới đụng zô được thằng cuối cùng. Nên là phải dùng tmp != null pointer thôi.
    while (tmp != nullptr)
    {

      cout << tmp->data << ": " << tmp->next;
      if (tmp->next != nullptr)
      {
        cout << " -> ";
      }
      else
      {
        cout << endl;
      }
      tmp = tmp->next;
    }
  }
  // kết thúc class phải có ;
};

int main()
{
  // cho sẵn cái mảng phục vụ cho thằng insertTail của SLL
  int size = 5;
  int arrD[size] = {1, 2, 3, 4, 5};
  SLL<int> mynode;
  mynode.insertTail(arrD, size);
  mynode.insertMid(99, 2);
  mynode.insertHead(100);
  mynode.print();
  mynode.delR(3);
  mynode.delH();
  mynode.print();

  return 0;
}