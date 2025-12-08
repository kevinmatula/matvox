#ifndef POINT2D_HPP
#define POINT2D_HPP

#include "Point3D.hpp"

// This is our class representation for a 2D point.
class Point2D {
public:
  int x, y;

  // This is our constructor method.
  Point2D(int x, int y);

  // This is another constructor method that creates a 2D point from two 3D
  // points (perspective projection)
  Point2D(Point3D cameraTransformation, Point3D displaySurface);

  // This method will project a 3D point into 2D.
  Point2D Projection2D(Point3D cameraTransformation, Point3D displaySurface);
};

#endif
