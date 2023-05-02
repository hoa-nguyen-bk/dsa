#include <iostream>

using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"
// https://www.programiz.com/dsa/heap-data-structure - tham khảo hay
template <class T>
class Heap
{
protected:
  T *elements;
  int capacity;
  int count;

public:
  Heap()
  {
    capacity = 10;
    count = 0;
    elements = new T[capacity];
  }
  ~Heap()
  {
    delete[] elements;
  }
  void push(T item);

  bool isEmpty();
  bool contains(T item);
  T peek();
  bool pop();
  int size();
  int leftchild(int pos) const
  {
    return 2 * pos + 1;
  } // Return leftchild position
  int rightchild(int pos) const
  {
    return 2 * pos + 2;
  } // Return rightchild position
  void printHeap()
  {
    cout << "Max Heap [ ";
    for (int i = 0; i < count; i++)
      cout << elements[i] << " ";
    cout << "]\n";
  }
  bool isLeaf(int pos) const // True if pos is a leaf
  {
    return (pos >= count / 2) && (pos < count);
  }

private:
  void ensureCapacity(int minCapacity);
  void reheapUp(int position);
  void reheapDown(int position);
};
template <typename E, typename T>
inline void swap(E A[], T i, T j)
{
  E temp = A[i];
  A[i] = A[j];
  A[j] = temp;
}

template <class T>
void Heap<T>::reheapDown(int position)
{
  while (!isLeaf(position))
  {
    // stop if position is leaf
    int j = leftchild(position);
    int rc = rightchild(position);
    if ((rc < count) && (elements[rc] < elements[j]))
    {
      j = rc; // set j to greater child's value
    }
    if (elements[position] < elements[j])
      return;
    swap(elements, position, j);
    position = j; // move down
  }
}
// Your code goes here
// Bài 2
int parent(int pos) // return parent position
{
  return (pos - 1) / 2;
}
// Swap two elements in a generic array

template <class T>
void Heap<T>::push(T item)
{
  if (count >= capacity)
  {
    cout << "Heap is full" << endl;
    return;
  }
  int current = count++; // current = count trước, count ++ sau

  elements[current] = item; // start at end of heap
  // Giờ sift up cho đến khi current parent > current
  reheapUp(current);
}
template <class T>
void Heap<T>::ensureCapacity(int minCapacity)
{
  if (minCapacity > capacity)
  {
    int newCapacity = (capacity * 3) / 2 + 1;
    if (newCapacity < minCapacity)
    {
      newCapacity = minCapacity;
    }
    capacity = newCapacity;
  }
}

template <class T>
void Heap<T>::reheapUp(int position)
{
  int parentPosition = parent(position);
  if (position != 0 && elements[position] > elements[parentPosition])
  {
    swap(elements, position, parentPosition);
    reheapUp(parentPosition);
  }
  return;
}
// Bài 1
template <class T>
int Heap<T>::size()
{
  return count;
}

template <class T>
bool Heap<T>::isEmpty()
{
  if (count == 0)
    return true;
  return false;
}

// Peek (Find max/min)
// Peek operation returns the maximum element from Max Heap or minimum element from Min Heap without deleting the node.
// For both Max heap and Min Heap
template <class T>
T Heap<T>::peek()
{
  if (isEmpty())
    return T();
  return elements[0];
}

template <class T>
bool Heap<T>::contains(T item)
{
  if (isEmpty())
    return false;
  for (int i = 0; i < size(); i++)
  {
    if (elements[i] == item)
    {
      return true;
    }
  }
  return false;
}

template <class T>
bool Heap<T>::pop()
{
  if (isEmpty())
    return false;
  swap(elements, 0, --count); // swap fist with last value
  if (count != 0)
    reheapDown(0); // reheap down new root value
  return true;
}

int main()
{
  Heap<int> maxHeap;
  for (int i = 0; i < 5; i++)
  {
    maxHeap.push(i);
  }
  cout << maxHeap.peek() << endl;//4
  maxHeap.printHeap();
  // Max Heap [ 4 3 1 0 2 ]
  cout << maxHeap.size() << endl;       // 10
  cout << maxHeap.isEmpty() << endl;    // 0
  cout << maxHeap.contains(4) << endl;  // 1
  cout << maxHeap.contains(11) << endl; // 0
  cout << maxHeap.pop() << endl;
  maxHeap.printHeap();
  // [3 1 0 2]
  cout << "ket thuc em ai" << endl;
  return 0;
}
