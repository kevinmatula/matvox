#include "include/Position/Camera3D.hpp"
#include "include/Position/Point2D.hpp"
#include "include/Position/Point3D.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {

  const int SIDELEN_CUBE = 20;
  const int HALF_SIDELEN_CUBE = SIDELEN_CUBE / 2;
  const int STARTING_FRONT_DEPTH = 10;
  const int STARTING_BACK_DEPTH = STARTING_FRONT_DEPTH + SIDELEN_CUBE;

  const int SCENE_WIDTH = 150;
  const int SCENE_HEIGHT = 30;

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

  // E value (the plane we are projecting onto)
  Point3D displaySurface(0, 0, CAM_DISTANCE);

  // Logic for printing pixels

  // Clear the screen and set cursor to home
  cout << "\x1b[2J\x1b[H";

  // Set the cursor to some random point in the terminal
  cout << "\x1b[5;150H";

  // Plot a lil thingy
  cout << "*";

  // Move cursor to bottom of terminal for space purposes
  cout << "\x1b[30H";

  return 0;
}
