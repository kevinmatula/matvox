#ifndef CUBE3D_HPP
#define CUBE3D_HPP

#include "../Object/Cube.hpp"
#include "../Position/Point3D.hpp"
#include <vector>

// This is our class representation for a 3D cube
class Cube3D : public Cube {
public:
  std::vector<Point3D> points;

  // This is our constructor method, in the future, we will use the builder
  // pattern.
  Cube3D(Point3D p1, Point3D p2, Point3D p3, Point3D p4, Point3D p5, Point3D p6,
         Point3D p7, Point3D p8, int startingFrontDepth);
};

#endif
