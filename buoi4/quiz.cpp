#include <iostream>
#include <queue>
#include <stack>
using namespace std;


template <class T>
class Node
{
  T data;
  Node *next;
};

//cái này là đang sở hữu luôn
template <class T>
class SLL
{
private:
  Node<T> *head;

public:
};

int main()
{
  //về nhà hiện thực lại 2 cái queue và stack
  //phân biệt tmp->next != null và tmp != null
  
  queue<int> q;
  //dequeue
  //trả về giá trị đầu hàm đợi
  q.front();
  //empty
  q.empty();
  


  stack<int> s;
  //đưa 1 pt vào đầu tac
  s.push();
  //đưa 1 hàm ra
  s.pop();
  //
  s.empty();
  s.top();
  


  return 0;
}