#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class Character
{
protected:
  int hp;
  int x;
  int y;

public:
  // Constructor: set the values of x and y and hp to 0
  Character();

  // Constructor: set the values of hp, x and y to each parameter
  Character(int hp, int x, int y);

  // Set and get hp
  int getHp();
  void setHp(int hp);

  // Set and get x
  int getX();
  void setX(int x);

  // Set and get y
  int getY();
  void setY(int y);

  // Get Manhattan distance to other character
  int getManhattanDistTo(Character *other);
};
#define EPSILON 0.0001f

int mySqrt(int number)
{
  int result = 1;
  while ((result * result - number) / number >= EPSILON)
    result = (number / result - result) / 2 + result;
  return result;
}
Character::Character()
{
  this->x = 0;
  this->y = 0;
  this->hp = 0;
}

Character::Character(int hp, int x, int y)
{
  this->x = x;
  this->y = y;
  this->hp = hp;
}

int Character::getHp()
{
  return this->hp;
}

void Character::setHp(int hp)
{
  this->hp = hp;
}

int Character::getX()
{
  return this->x;
}

void Character::setX(int x)
{
  this->x = x;
}

int Character::getY()
{
  return this->y;
}

void Character::setY(int y)
{
  this->y = y;
}

int Character::getManhattanDistTo(Character *other)
{

  int x = this->getX() - other->getX();
  int abx = x > 0 ? x : -x;
  int y = this->getY() - other->getY();
  int aby = y > 0 ? y : -y;
  return abx + aby;
}

int main()
{
  Character *ch31 = new Character(100, 1, 2);
  Character *ch32 = new Character(100, -3, 4);
  cout << ch31->getManhattanDistTo(ch32); // 6
  delete ch31;
  delete ch32;
  return 0;
}
