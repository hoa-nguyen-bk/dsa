#include <iostream>
using namespace std;

template <class T>
struct Node
{
  T data;
  Node<T> *link;
  Node() : data(), link(nullptr){};
};

template <class List_ItemType>
class LinkedList
{
  int count;
  Node<List_ItemType> *head;

public:
  LinkedList()
  {
    this->count = 0;
    this->head = nullptr;
  }
  ~LinkedList(){};
  int insertNode(Node<List_ItemType> *pointerPredecessor, List_ItemType value);
  void print();
};
template <class List_ItemType>
void LinkedList<List_ItemType>::print()
{
  Node<List_ItemType> *tmp = new Node();
  tmp = this->head;
  while (tmp != nullptr)
  {
    cout << tmp->data << " -> ";
    tmp = tmp->link;
  }
  cout << endl;
}

template <class List_ItemType>
int LinkedList<List_ItemType>::insertNode(Node<List_ItemType> *pointer2Predecessor, List_ItemType value)
{
  Node<List_ItemType> *pointer2New = new Node<List_ItemType>;
  if (pointer2New == NULL)
    return 0;
  pointer2New->data = value;
  if (pointer2Predecessor == nullptr)
  {
    pointer2New->link = this->head;
    this->head = pointer2New;
  }
  else
  {
    pointer2New->link = pointer2Predecessor->link;
    pointer2Predecessor->link = pointer2New;
  }
  this->count++;
  return 1;
}

int main()
{
  LinkedList<int>* myArr;
  
  
  return 0;
}