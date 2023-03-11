#include <iostream>
#include "../doubly_linked_list.h"
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
  // TH1: remove at head
  cout << "TH1: remove at head" << endl;
  list.removeAt(0);
  list.toNodeString();
  // TH2: remove at middle
  cout << "TH2: remove at index = " << list.size() / 2 << endl;

  list.removeAt(list.size() / 2);
  list.toNodeString();
  // TH3: remove at tail
  cout << "TH3: remove at tail" << endl;
  list.removeAt(list.size() - 1);
  list.toNodeString();

  // TH1: remove at head
  cout << "TH1: remove at head" << endl;
  list.removeItem(list.get(0));
  list.toNodeString();

  // TH2: remove at middle
  int middle = list.get(list.size() / 2);
  cout << "TH2: remove at index = " << middle << endl;
  list.removeItem(middle);
  list.toNodeString();

  // TH3: remove at tail
  cout << "TH3: remove at tail" << endl;
  list.removeItem(list.get(list.size() - 1));
  list.toNodeString();

  list.clear();
  list.toNodeString();

  DLinkedList<int> listOnly;
  listOnly.toNodeString();

  list.clear();
  list.toNodeString();

  // // TH DB1: remove at for list only
  // cout << "TH DB1: remove at for list only" << endl;
  // listOnly.removeAt(0);
  // listOnly.toNodeString();
  // cout << "NEW QUEEN CAME UP" << endl;
  // listOnly.add(66);
  // listOnly.toNodeString();

  // // TH DB2: remove item for list only
  // cout << "TH DB2: remove item for list only (" <<list.get(0)<<") end" << endl;
  // listOnly.removeItem(66);
  // listOnly.toNodeString();

  return 0;
}