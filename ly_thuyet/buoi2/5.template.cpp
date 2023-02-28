#include <iostream>
using namespace std;

// Nội dung buổi 2
// - class
// - các thuộc tính oop
// +Tính đóng gói encapsulation: gom tất cả và gói gọn lại trong class student
// +Constructor
// +Inheritance -> kế thừa
// DRY => dont repeat yourself
// + template

template <class T>
struct Node
{
  T data;
  Node *next;
};

template <class T>
class SSL
{
private:
  Node<T> *head;

public:
  void createList(){};
  void insert(){};
  void del(){};
};

int main()
{
  SSL<int> Linkedlist;
  return 0;
}