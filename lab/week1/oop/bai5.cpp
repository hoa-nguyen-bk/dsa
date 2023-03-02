#include <iostream>

using namespace std;

enum Color
{
  red,
  green,
  blue
};
enum Size
{
  small,
  medium,
  big
};

class Toy
{
protected:
  double price;

public:
  Toy(double price)
  {
    this->price = price;
  }

  virtual void printType() = 0;
  friend class ToyBox;
};

// class cartoy kế thừa class toy
class CarToy : public Toy
{
private:
  Color color;

public:
  CarToy(double price, Color color) : Toy(price)
  {
    this->color = color;
    this->price = price;
  }

  void printType()
  {
    cout << "This is a car toy\n";
  }

  friend class ToyBox;
};

class PuzzleToy : public Toy
{
private:
  Size size;

public:
  PuzzleToy(double price, Size size) : Toy(price)
  {
    this->price = price;
    this->size = size;
  }

  void printType()
  {
    cout << "This is a puzzle toy\n";
  }

  friend class ToyBox;
};

class ToyBox
{
private:
  // This code creates an array of 5 Toy pointers. Each pointer points to a Toy object in memory.
  Toy *toyBox[5];
  int numberOfItems;

public:
  ToyBox()
  {
    this->numberOfItems = 0;
    for (int i = 0; i < 5; i++)
    {
      this->toyBox[i] = nullptr;
    }
  }

  int addItem(const CarToy &carToy)
  {
    if (this->numberOfItems >= 4)
      return -1;
    this->toyBox[numberOfItems] = new CarToy(carToy.price, carToy.color);
    this->numberOfItems++;
    return this->numberOfItems;
  }

  int addItem(const PuzzleToy &puzzleToy)
  {
    if (this->numberOfItems >= 4)
      return -1;
    this->toyBox[numberOfItems] = new PuzzleToy(puzzleToy.price, puzzleToy.size);
    this->numberOfItems++;
    return this->numberOfItems;
  }

  void printBox()
  {
    for (int i = 0; i < numberOfItems; i++)
      toyBox[i]->printType();
  }
};

int main()
{
  cout << "red = " << red << endl;
  CarToy car(20000, red);
  PuzzleToy puzzle(30000, small);

  ToyBox box;
  box.addItem(car);
  box.addItem(puzzle);
  box.printBox();
  // This is a car toy
  // This is a puzzle toy
  return 0;
}
