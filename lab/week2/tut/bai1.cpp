#include <iostream>
#include "../doubly_linked_list/bai4.cpp"
using namespace std;


int main()
{
  DLinkedList<int> list;
  int size = 10;
  int value[] = {2, 5, 6, 3, 67, 3322, 43, 1, 0, 9};

  for (int idx = 0; idx < size; idx++)
  {
    list.add(value[idx]);
  }
  list.toString();
  list.toNodeString();
  return 0;
}