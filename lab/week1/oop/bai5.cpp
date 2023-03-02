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
    cout << "inside cartoy: " << color << " - " << price << endl;
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
    cout << "inside puzze: " << size << " - " << price << endl;

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
    /*
     * STUDENT ANSWER
     * TODO: set zero numberOfItems and nullptr toyBox
     */
    this->numberOfItems = 0;
    for (int i = 0; i < 5; i++)
    {
      this->toyBox[i] = nullptr;
    }
  }

  int addItem(const CarToy &carToy)
  {
    /*
     * STUDENT ANSWER
     * TODO: function add a new Car toy to the box.
             If successfully added, the function returns the current number of toys in the box.
             If the box is full, return -1.
     */
    if (this->numberOfItems >= 4)
      return -1;
    cout << "carToy = " << carToy.color << " - " << carToy.price << endl;
    this->toyBox[numberOfItems] = new CarToy(carToy.price, carToy.color);
    cout << "toyBox[" << numberOfItems << "] = " << toyBox[numberOfItems] << endl;
    this->numberOfItems++;
    cout << "numberOfItems = " << numberOfItems << endl;
    this->printBox();
    return this->numberOfItems;
  }

  int addItem(const PuzzleToy &puzzleToy)
  {
    /*
     * STUDENT ANSWER
     * TODO: function add a new Puzzle toy to the box.
             If successfully added, the function returns the current number of toys in the box.
             If the box is full, return -1.
     */
    if (this->numberOfItems >= 4)
      return -1;
    cout << "puzzleToy = " << puzzleToy.size << " - " << puzzleToy.price << endl;

    this->toyBox[numberOfItems] = new PuzzleToy(puzzleToy.price, puzzleToy.size);
    cout << "toyBox[" << numberOfItems << "] = " << toyBox[numberOfItems] << endl;

    this->numberOfItems++;
    this->printBox();
    cout << "numberOfItems = " << numberOfItems << endl;

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
  box.addItem(puzzle);
  box.addItem(car);
  box.addItem(puzzle);
  box.addItem(car);
  box.addItem(puzzle);
  box.printBox();
  // This is a car toy
  // This is a puzzle toy
  return 0;
}
