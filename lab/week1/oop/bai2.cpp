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
    /*
     * STUDENT ANSWER
     * TODO: set zero center's x-y and radius
     */
    this->center.setX(0);
    this->center.setY(0);
    this->radius = 0;
  }

  Circle(Point center, double radius)
  {
    this->center.setX(center.getX());
    this->center.setY(center.getY());
    this->setRadius(radius);
  }

  Circle(const Circle &circle)
  {
    this->center.setX(circle.center.getX());
    this->center.setY(circle.center.getY());
  }

  void setCenter(Point point)
  {
    this->center.setX(point.getX());
    this->center.setY(point.getY());
  }

  void setRadius(double radius)
  {
    this->radius = radius;
  }

  Point getCenter() const
  {

    return Point(this->center.getX(),this->center.getY());
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