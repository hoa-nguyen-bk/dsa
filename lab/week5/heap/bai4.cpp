#include <iostream>
#include "heap.h"
//tét in git bash
// cd lab/week5/heap
// g++ bai4.cpp -o bai4.exe && ./bai4
using namespace std;
template <class T>
int Heap<T>::getItem(T item)
{
  // TODO: return the index of item in heap
  if (count == 0)
    return -1;
  for (int i = 0; i < count; i++)
  {
    if (elements[i] == item)
      return i;
  }
  return -1;
}

template <class T>
void Heap<T>::remove(T item)
{
  // TODO: remove the element with value equal to item
  int position = getItem(item);
  if (position == -1)
    return;
  if (position == (count - 1))
  {
    count--; // Last element, no work to do
  }
  else
  {
    int lastElement = count - 1;
    T temp = elements[position];
    elements[position] = elements[lastElement];
    elements[lastElement] = temp;
    count--;
    if (position != 0 && elements[position] > elements[(position - 1) / 2])
    {
      reheapUp(position);
    }
    if (count != 0)
    {
      reheapDown(position);
    }
  }
}

template <class T>
void Heap<T>::clear()
{
  // TODO: delete all elements in heap
  //    then reallocate memory as initial state
  count = 0;
  delete elements;
  // elements = T();
}
int main()
{
  Heap<int> maxHeap;
  // test case 1:
  // int arr[] = {42, 35, 30, 15, 20, 21, 18, 3, 7, 14};
  // for (int i = 0; i < 10; i++)
  //   maxHeap.push(arr[i]);
  // maxHeap.remove(42);
  // maxHeap.remove(35);
  // maxHeap.remove(30);
  // maxHeap.printHeap();
  // Max Heap [ 21 20 18 15 14 7 3 ]
  // testcase 2
  // int arr[] = {78, 67, 32, 56, 8, 23, 19, 45};
  // for (int i = 0; i < 8; i++)
  // maxHeap.push(arr[i]);
  // maxHeap.remove(78);
  // maxHeap.printHeap();
  // Max Heap [ 67 56 32 45 8 23 19 ]
  // test case 3 return []
  int arr[] = {13, 19, 20, 7, 15, 12, 16, 10, 8, 9, 3, 6, 18, 2, 14, 1, 17, 4, 11, 5};
  for (int i = 0; i < 20; ++i)
    maxHeap.push(arr[i]);
  maxHeap.clear();
  maxHeap.printHeap();
  return 0;
}