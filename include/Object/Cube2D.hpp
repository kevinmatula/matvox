#ifndef CUBE2D_HPP
#define CUBE2D_HPP

#include "../Object/Cube.hpp"
#include "../Position/Point2D.hpp"
#include "Cube3D.hpp"

// This is our class representation for a 2D cube.
class Cube2D : public Cube {
public:
  std::vector<Point2D> points;

  // This is our constructor method.
  // TODO: in the future, we will use the builder pattern.
  Cube2D(Point2D p1, Point2D p2, Point2D p3, Point2D p4, Point2D p5, Point2D p6,
         Point2D p7, Point2D p8, int startingFrontDepth);

  // This is an overloaded constructor that instantiates a 2D cube by conducting
  // the transformation process. This will project all 3D cube3D points to 2D
  // points and construct a cube2D.
  Cube2D(Cube3D cube3D, Point3D displaySurface, Camera3D camera);
};

#endif
