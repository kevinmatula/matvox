#include "../../include/Object/Cube3D.hpp"
#include "../../include/Object/Cube.hpp"
#include "../../include/Position/Point3D.hpp"

Cube3D::Cube3D(std::vector<Point3D> givenPoints, int startingFrontDepth)
    : Cube(startingFrontDepth), points(givenPoints) {}
