#include <iostream>
#include <string.h>
using namespace std;

class DynamicArray
{
private:
  int size;
  int capacity;
  int *storage;

public:
  DynamicArray()
  {
    size = 0;
    capacity = 10;
    storage = new int[capacity];
  }
  DynamicArray(int capacity)
  {
    cout << "DynamicArray(int capacity) func " << endl;
    this->capacity = capacity;
    size = 0;
    storage = new int[capacity];
  }
  ~DynamicArray()
  {
    delete[] storage;
  }
  void setCapacity(int newCapacity);
  void ensureCapacity(int minCapacity);
  void pack();
  void trim();
  void rangeCheck(int index);
  void print();
  void set(int index, int value);
  int get(int index);
  void insertAt(int index, int value);
  void removeAt(int index);
};

void DynamicArray::insertAt(int index, int value)
{
  // bằng size vẫn được tại vị trí size là vị trí cuối cùng mới, nên ko dùng hàm rangecheck là do vậy
  if (index < 0 || index > size)
  {
    throw std::out_of_range("Dont worry: Index out of bound");
  }
  ensureCapacity(size + 1);
  int moveCount = size - index;
  if (moveCount != 0)
  {
    memmove(storage + index + 1, storage + index, sizeof(int) * moveCount);
  }
  storage[index] = value;
  size++;
}

void DynamicArray::removeAt(int index)
{
  rangeCheck(index);
  int moveCount = size - index - 1;
  if (moveCount > 0)
  {
    memmove(storage + index, storage + (index + 1), sizeof(int) * moveCount);
  }
  size--;
  pack();
}

void DynamicArray::rangeCheck(int index)
{
  if (index < 0 || index >= size)
  {
    throw std::out_of_range("Index out of bounds");
  }
  else
  {
    cout << "still good" << endl;
  }
}

void DynamicArray::set(int index, int value)
{
  this->rangeCheck(index);
  storage[index] = value;
}

int DynamicArray::get(int index)
{
  rangeCheck(index);
  return storage[index];
}

void DynamicArray::pack()
{
  if (size <= capacity / 2)
  {
    int newCapacity = (size * 3) / 2 + 1;
    setCapacity(newCapacity);
  }
}

void DynamicArray::trim()
{
  int newCapacity = size;
  this->setCapacity(newCapacity);
}

void DynamicArray::setCapacity(int newCapacity)
{
  cout << "setCapacity " << endl;

  int *newStorage = new int[newCapacity];
  memcpy(newStorage, storage, sizeof(int) * this->size);
  this->capacity = newCapacity;
  delete[] this->storage;
  this->storage = newStorage;
}

void DynamicArray::ensureCapacity(int minCapacity)
{
  cout << "ensure" << endl;
  if (minCapacity > capacity)
  {
    int newCapacity = (capacity * 3) / 2 + 1;
    if (newCapacity < minCapacity)
    {
      newCapacity = minCapacity;
    }
    setCapacity(newCapacity);
  }
}

void DynamicArray::print()
{
  cout << "===== " << endl;
  cout << "Let print array: " << endl;
  for (int i = 0; i < this->size; i++)
  {
    cout << storage[i] << " ";
  }
  // cout << "end " << endl;
  cout << "size = " << this->size << "; cap = " << this->capacity << endl;
}

int main()
{
  cout << "Dynamic arr" << endl;
  DynamicArray *myArr = new DynamicArray(15);
  myArr->print();
  for (int i = 0; i < 10; i++)
  {
    myArr->insertAt(i, 10 - i);
  }
  myArr->print();
  cout << "myArr->get(3) = " << myArr->get(3) << endl;

  myArr->rangeCheck(200); // throw error and stop func
  return 0;
}