#include <iostream>
using namespace std;

template <class T>
class Node
{
  T data;
  Node *next;
};

//cái này là đang sở hữu luôn
template <class T>
class SLL : public Node<T>
{
private:
  Node<T> *head;

public:
};

int main()
{

  return 0;
}