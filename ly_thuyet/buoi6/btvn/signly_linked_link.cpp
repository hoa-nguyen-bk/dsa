#include <iostream>

using namespace std;

template <class ItemType>
struct Node
{
  ItemType data;
  Node<ItemType> *link;
};


class List
{
private:
  Node *head;
  int count;
  public:
  Node(){
    this
  }
};

int main()
{
  Node<int> *p = new Node<int>();
  p->data = 5;
  cout << p->data << endl;
  Node<int> *q = p;
  cout << q->data << endl;
  Node<int> *r = new Node<int>();
  r->data=10;
  q->link=r;
  cout << p->link->data << endl;

  return 0;
}
