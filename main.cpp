#include "src/Point2D.hpp"
#include "src/Point3D.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {

  const int SIDELEN_CUBE = 20;
  const int HALF_SIDELEN_CUBE = SIDELEN_CUBE / 2;

  // Im gonna be honest i dont know how to scale this value.
  const int CAM_DISTANCE = 40;

  // Front side of test cube
  Point3D frontTopRightCorner(HALF_SIDELEN_CUBE, HALF_SIDELEN_CUBE,
                              HALF_SIDELEN_CUBE);
  Point3D frontTopLeftCorner(-HALF_SIDELEN_CUBE, HALF_SIDELEN_CUBE,
                             HALF_SIDELEN_CUBE);
  Point3D frontBottomLeftCorner(-HALF_SIDELEN_CUBE, -HALF_SIDELEN_CUBE,
                                HALF_SIDELEN_CUBE);
  Point3D frontBottomRightCorner(HALF_SIDELEN_CUBE, -HALF_SIDELEN_CUBE,
                                 HALF_SIDELEN_CUBE);

  // Back side of test cube
  Point3D backTopRightCorner(HALF_SIDELEN_CUBE, HALF_SIDELEN_CUBE,
                             -HALF_SIDELEN_CUBE);
  Point3D backTopLeftCorner(-HALF_SIDELEN_CUBE, HALF_SIDELEN_CUBE,
                            -HALF_SIDELEN_CUBE);
  Point3D backBottomLeftCorner(-HALF_SIDELEN_CUBE, -HALF_SIDELEN_CUBE,
                               -HALF_SIDELEN_CUBE);
  Point3D backBottomRightCorner(HALF_SIDELEN_CUBE, -HALF_SIDELEN_CUBE,
                                -HALF_SIDELEN_CUBE);

  // Camera Point (Pinhole)
  Point3D camera(0, 0, 0);

  return 0;
}
