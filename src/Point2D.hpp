#ifndef POINT2D_HPP
#define POINT2D_HPP

#include "Point3D.hpp"

// This is our class representation for a 2D point.
class Point2D {
public:
  int x, y;

  // This is our constructor method.
  Point2D(int x, int y) {
    x = x;
    y = y;
  }

  // This method will project a 3D point into 2D.
  Point2D Projection2D(Point3D point);
};

#endif
