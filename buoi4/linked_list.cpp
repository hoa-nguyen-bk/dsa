#include <iostream>
using namespace std;

// SinglyLinkedList
template <class T>
class SLL
{
  class Node; // forward declaration
private:
  Node *head;

public:
  void createLL(){};

public:
  class Node
  {
  private:
    T data;
    Node *next;

  public:
    SLL()
    {
      head = nullptr;
    }

  public:
    Node()
    {
      next = nullptr;
      Node *next;
      friend class SLL<T>;
    }
    Node(T data)
    {
      this->data = data;
      this->next = nullptr;
    }
  };
};

int main()
{
  SLL<int> list = new Node();

  return 0;
}