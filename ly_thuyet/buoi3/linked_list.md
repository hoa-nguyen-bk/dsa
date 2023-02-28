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
  Node<T> *head = nullptr;

public:
  SLL()
  {
    // nhờ đây khi tạo class thì sẽ tự khai báo một cái node head với giá trị null pointer
    head = nullptr;
  }
  // lúc thêm cho thêm 3 chỗ, đầu giữa cuối, insertHead,insertMid,insertTail

  // đầu tiên thêm một pần tử vào thì thường thêm ở tail, ở đây hàm insertTail nhận vô 2 tham số là T, T chính là template ở trên mà mình cho người dùng truyền zô, rồi tới size, thầy nói size là phải truyền zô chứ ko dùng hàm hay phép toán chia chia nha, tại đây là con trỏ *arrD chứ ko phải là chính arrD, nhớ kĩ là cái *arrD khác size với arrD chứ ko bị lừa
  void insertTail(T *arrD, int size)
  {
    // chỗ này mình nhận một mảng chứ mình lười nhập từng thằng nên mình phải đi duyệt mảng
    for (int i = 0; i < size; i++)
    {
      // chỗ này phải tạo ra cái node, chứ làm méo gì có node nào sẵn đâu
      // Chỗ ni nó báo là invalid conversion from 'int' to 'Node<int>*' , tại vì nó bắt mình phải cấp vùng nhớ cho nó chứ ko làm zầy đc
      // Node<T> *node(arrD[i]);
      // nên mình viết lại cú pháp như vầy
      Node<T> *node = new Node<T>(arrD[i]);
      // sau khi có cái node rồi phải add thêm phần tử zô cái head chứ
      // này là để check nếu như đây vẫn là mảng còn trinh nguyên chưa thêm 1 phần tử nào
      if (head == nullptr)
      {
        // thì cái head là chính node mà mình mới tạo luôn
        head = node;
      }
      else
      {
        // ở cái vế else nếu cái linked list đã được một đống rồi chứ ko còn trinh nguyên thì phải dùng cách thêm bình thường. Vậy thì bình thường sẽ phải tìm thằng cuối cùng trong cái linked list đó để mà thêm thôi. Muốn tìm thằng cuối cùng thì lại phải đi duyệt mảng linked list. Mà ngoài cái head và cái arrD[i] hiện tại mình phải có 1 cái cục index di chuyển qua lại trên cái linked list đó để duyệt nữa. Cái cục đó được dân tình gọi tên là tmp, tiếng việt là biến tạm
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
        // ủa zị làm sao để gán tmp zô mảng, phải log nó ra mới bít đc, típ tục tới hàm tracer, tức hàm print
      }
    }
  }
  void insertMid(T dataInsert, int position){
    int index = 0;
    Node<T> *nodeAfter = head;
    Node<T> *nodeAdded = new Node<T>(dataInsert);
    while(index != position){
      index++;
      nodeAfter = nodeAfter->next;
    }
    //giờ là vế nếu index = position, hiện tại cái tmp đang đứng ở cái node típ theo
    //
    Node<T> *nodeBefore = nodeAfter;
    nodeAdded->next = nodeAfter;
    nodeBefore->next= nodeAdded;
  }
  void print()
  {

    // Node<T> *tmp
    // chỗ ni phải cho tmp là một giá trị ban đầu head, chính là cái thằng head mình cho ở trên private đó, nếu ko có thì làm sao nó biết phải bắt đầu từ đâu
    Node<T> *tmp = head;
    // nếu mà viết tmp->next thế này thì nó còn lâu mới đụng zô được thằng cuối cùng. Nên là phải dùng tmp != null pointer thôi.
    while (tmp != nullptr)
    {

      cout << tmp->data << ": " << tmp->next;
      if (tmp->next != nullptr)
      {
        cout << " -> ";
      }
      // in xong phải đi tiếp chứ, ko đi tiếp nó đứng mãi tại chỗ à
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
  // sai, chỗ ni khôn phải SLL mà là mynode mới đúng
  // SLL.print();
  mynode.insertTail(arrD, size);
  mynode.insertMid(99,2);
  
  mynode.print();
  return 0;
}