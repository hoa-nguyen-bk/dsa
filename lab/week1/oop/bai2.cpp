// In the coordinate plane, we have class Point to store a point with it's x-y coordinate.
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Point
{
private:
  double x, y;

public:
  Point()
  {
    this->x = 0;
    this->y = 0;
  }

  Point(double x, double y)
  {
    this->x = x;
    this->y = y;
  }

  void setX(double x)
  {
    this->x = x;
  }

  void setY(double y)
  {
    this->y = y;
  }

  double getX() const
  {
    return this->x;
  }

  double getY() const
  {
    return this->y;
  }

  double distanceToPoint(const Point &pointA)
  {
    return sqrt(pow(this->x - pointA.x, 2) + pow(this->y - pointA.y, 2));
  }
};

class Circle
{
private:
  Point center;
  double radius;

public:
  Circle()
  {
    this->center.setX(0);
    this->center.setY(0);
    this->radius = 0;
  }

  Circle(Point center, double radius)
  {
    this->center = center;
    this->radius = radius;
  }

  Circle(const Circle &circle)
  {
    this->center = circle.center;
    this->radius= circle.radius;
  }

  void setCenter(Point point)
  {
   this->center = point;
  }

  void setRadius(double radius)
  {
    this->radius = radius;
  }

  Point getCenter() const
  {

    return this->center;
  }

  double getRadius() const
  {
    /*
     * STUDENT ANSWER
     */
    return this->radius;
  }

  void printCircle()
  {
    printf("Center: {%.2f, %.2f} and Radius %.2f\n", this->center.getX(), this->center.getY(), this->radius);
  }
};

int main()
{
  Circle A;
  A.printCircle(); //Center: {0.00, 0.00} and Radius 0.00
  return 0;
}