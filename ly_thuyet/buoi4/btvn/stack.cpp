#include <iostream>
using namespace std;

// stack với 4 chức năng
// pop
// push
// empty
// pop

template <class T>
// struct thì struct vẫn dựa trên một cái node
struct Node
{
  int data;
  Node<T> *next;
  Node(T data)
  {
    this->data = data;
    this->next = nullptr;
  }
};

template <class T>
class Stack
{
private:
  // nhớ cho chỗ này head = null pointer
  Node<T> *head = nullptr;

public:
  Stack(T data)
  {
    head->data = data;
  }
  // thêm 1 ptu mới vào mảng, giá trị user quyết định dĩ nhiên òi, nên là T data
  void push(T data);
  void pop();
  void tracer();
  // nhớ hết class phải có ;
};

template <class T>
void Stack<T>::push(T data)
{
  Node<T> *tmp = head;
  // nếu temp chưa được cấp pháp bộ nhớ
  cout << "tmp=" << tmp << ";tmp->next =" << tmp->next;
  Node<T> *new_node = new Node<T>(data);
  if (head->next == nullptr)
  {
    //thêm zô sau tại đây stakc mà
    new_node->next = head;
  } else (head!=nullptr){
    
  }
}

template <class T>
void Stack<T>::tracer()
{
  Node<T> *tmp = head;
  while (tmp->next != nullptr)
  {
    cout << tmp->data << ": " << tmp->next << " -> ";
    tmp = tmp->next;
  }
}
// ở đây gặp bug ko log ra đc

int main()
{
  Stack<int> *A = new Stack<int>(5);
  A->push(5);
  A->push(2);
  A->tracer();
  return 0;
}