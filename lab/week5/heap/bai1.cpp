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
    this->capacity = 10;
    this->count = 0;
    this->elements = new T[capacity];
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

  void printHeap()
  {
    cout << "Max Heap [ ";
    for (int i = 0; i < count; i++)
      cout << elements[i] << " ";
    cout << "]\n";
  }

private:
  void ensureCapacity(int minCapacity);
  void reheapUp(int position);
  void reheapUp2(int position);
  void reheapDown(int position);
};
// Your code goes here
// Bài 2
int parent(int pos) // return parent position
{
  return (pos - 1) / 2;
}
// Swap two elements in a generic array
template <typename E>
inline void swap(E A[], int i, int j)
{
  E temp = A[i];
  A[i] = A[j];
  A[j] = temp;
}

template <class T>
void Heap<T>::push(T item)
{
  if (count >= capacity)
  {
    cout << "Heap is full" << endl;
    return;
  }
  int current = count++; // current = count trước, count ++ sau

  cout << "count = " << count << endl;
  cout << "current = " << current << endl;

  elements[current] = item; // start at end of heap
  // Giờ sift up cho đến khi current parent > current
  reheapUp(current);

  // while ((current != 0) && (elements[current] > elements[parent(current)]))
  // {
  //   swap(elements, current, parent(current));
  //   current = parent(current);
  // }
}
template <class T>
void Heap<T>::ensureCapacity(int minCapacity)
{
  cout << "ensure" << endl;
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
    cout << "position[" << position << "] = " << elements[position] << endl;
    cout << "parent[" << parentPosition << "] = " << elements[parentPosition] << endl;
    swap(elements, position, parentPosition);
    reheapUp(parentPosition);
  }
  return;
}
// Bài 1
template <class T>
int Heap<T>::size()
{
}

template <class T>
bool Heap<T>::isEmpty()
{
}

template <class T>
T Heap<T>::peek()
{
}

template <class T>
bool Heap<T>::contains(T item)
{
}

template <class T>
bool Heap<T>::pop()
{
}
int main()
{
  Heap<int> maxHeap;
  for (int i = 0; i < 5; i++)
  {
    maxHeap.push(i);
  }
  maxHeap.printHeap();
  // Max Heap [ 4 3 1 0 2 ]
  cout << maxHeap.size();    // 10
  cout << maxHeap.isEmpty(); // 0
  cout << "Kết thúc êm ái" << endl;
  return 0;
}
