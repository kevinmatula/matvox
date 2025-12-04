#include "src/Point2D.hpp"
#include "src/Point3D.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {

  // Front side of test cube
  Point3D frontTopRightCorner(1, 1, 1);
  Point3D frontTopLeftCorner(-1, 1, 1);
  Point3D frontBottomLeftCorner(-1, -1, 1);
  Point3D frontBottomRightCorner(1, 1, 1);

  // Back side of test cube
  Point3D backTopRightCorner(1, 1, -1);
  Point3D backTopLeftCorner(-1, 1, -1);
  Point3D backBottomLeftCorner(-1, -1, -1);
  Point3D backBottomRightCorner(1, 1, -1);

  return 0;
}
