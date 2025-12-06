#include "src/Camera3D.hpp"
#include "src/Point2D.hpp"
#include "src/Point3D.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {

  const int SIDELEN_CUBE = 20;
  const int HALF_SIDELEN_CUBE = SIDELEN_CUBE / 2;
  const int STARTING_FRONT_DEPTH = 10;
  const int STARTING_BACK_DEPTH = STARTING_FRONT_DEPTH + SIDELEN_CUBE;

  const int CAM_DISTANCE = 40;

  // Front side of test cube
  Point3D frontTopRightCorner(HALF_SIDELEN_CUBE, HALF_SIDELEN_CUBE,
                              STARTING_FRONT_DEPTH);
  Point3D frontTopLeftCorner(-HALF_SIDELEN_CUBE, HALF_SIDELEN_CUBE,
                             STARTING_FRONT_DEPTH);
  Point3D frontBottomLeftCorner(-HALF_SIDELEN_CUBE, -HALF_SIDELEN_CUBE,
                                STARTING_FRONT_DEPTH);
  Point3D frontBottomRightCorner(HALF_SIDELEN_CUBE, -HALF_SIDELEN_CUBE,
                                 STARTING_FRONT_DEPTH);

  // Back side of test cube
  Point3D backTopRightCorner(HALF_SIDELEN_CUBE, HALF_SIDELEN_CUBE,
                             STARTING_BACK_DEPTH);
  Point3D backTopLeftCorner(-HALF_SIDELEN_CUBE, HALF_SIDELEN_CUBE,
                            STARTING_BACK_DEPTH);
  Point3D backBottomLeftCorner(-HALF_SIDELEN_CUBE, -HALF_SIDELEN_CUBE,
                               STARTING_BACK_DEPTH);
  Point3D backBottomRightCorner(HALF_SIDELEN_CUBE, -HALF_SIDELEN_CUBE,
                                STARTING_BACK_DEPTH);

  // Camera Point (Pinhole)
  Point3D cameraPoint(0, 0, 0);
  Angle3D anglePoint(0, 0, 0);
  Camera3D camera(cameraPoint, anglePoint);

  cout << "\x1b[2J" << endl;

  return 0;
}
