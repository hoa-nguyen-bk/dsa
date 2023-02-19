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
    /*
     * STUDENT ANSWER
     * TODO: set zero x-y coordinate
     */
    this.x = 0;
    this.y = 0;
  }

  Point(double x, double y)
  {
    /*
     * STUDENT ANSWER
     */
    this.x = x;
    this.y = y;
  }

  void setX(double x)
  {
    /*
     * STUDENT ANSWER
     */
    this.x = x;
  }

  void setY(double y)
  {
    /*
     * STUDENT ANSWER
     */
    this.y = y;
  }

  double getX() const
  {
    /*
     * STUDENT ANSWER
     */
    return this.x;
  }

  double getY() const
  {
    /*
     * STUDENT ANSWER
     */
    return this.y;
  }

  double distanceToPoint(const Point &pointA)
  {
    /*
     * STUDENT ANSWER
     * TODO: calculate the distance from this point to point A in the coordinate plane
     */
    return 12.2;
  }
};

int main()
{
  Point A(2, 3);
  cout << A.getX() << " " << A.getY(); // 2 3
  Point A(2, 3);
  Point B(1, 1);
  cout << pow(A.distanceToPoint(B), 2);
  return 0;
}