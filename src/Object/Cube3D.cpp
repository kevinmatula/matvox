#include "../../include/Object/Cube3D.hpp"
#include "../../include/Object/Cube.hpp"
#include "../../include/Position/Point3D.hpp"

Cube3D::Cube3D(Point3D frontTRg, Point3D frontTLg, Point3D frontBRg,
               Point3D frontBLg, Point3D backTRg, Point3D backTLg,
               Point3D backBRg, Point3D backBLg, int startingFrontDepth)
    : Cube(startingFrontDepth) {
  points.push_back(frontTRg), points.push_back(frontTLg),
      points.push_back(frontBLg), points.push_back(frontBRg),
      points.push_back(backTRg), points.push_back(backTLg),
      points.push_back(backBRg), points.push_back(backBLg);
}
