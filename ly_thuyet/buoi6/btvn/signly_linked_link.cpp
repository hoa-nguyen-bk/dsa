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
};

int main()
{
  Node *p = new Node();
  p->data = 5;
  cout << p->data << endl;
  Node *q = p;
  cout << q->data << endl;
  Node *r = new Node();
  r->data=10;
  q->link=r;
  cout << p->link->data << endl;

  return 0;
}
