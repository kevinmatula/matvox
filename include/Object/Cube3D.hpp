#ifndef CUBE3D_HPP
#define CUBE3D_HPP

#include "../Object/Cube.hpp"
#include "../Position/Point3D.hpp"
#include <vector>

// This is our class representation for a 3D cube
class Cube3D : public Cube {
public:
  std::vector<Point3D> points;

  // This is our constructor method
  Cube3D(std::vector<Point3D> givenPoints, int startingFrontDepth);
};

#endif
