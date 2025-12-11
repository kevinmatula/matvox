#include "include/Object/Cube2D.hpp"
#include "include/Object/Cube3D.hpp"
#include "include/Position/Camera3D.hpp"
#include "include/Position/Point2D.hpp"
#include "include/Position/Point3D.hpp"
#include <iostream>
#include <memory>
#include <unistd.h>
#include <vector>

using namespace std;

int main() {

  const int SIDELEN_CUBE = 20;
  const int HALF_SIDELEN_CUBE = SIDELEN_CUBE / 2;
  const int STARTING_FRONT_DEPTH = 40;
  const int STARTING_BACK_DEPTH = STARTING_FRONT_DEPTH + SIDELEN_CUBE;

  const int SCENE_WIDTH = 115;
  const int SCENE_HEIGHT = 35;

  const int CAM_DISTANCE = 10;

  // Front side of test cube
  Point3D frontTopRightCorner3D(HALF_SIDELEN_CUBE, HALF_SIDELEN_CUBE,
                                STARTING_FRONT_DEPTH);
  Point3D frontTopLeftCorner3D(-HALF_SIDELEN_CUBE, HALF_SIDELEN_CUBE,
                               STARTING_FRONT_DEPTH);
  Point3D frontBottomLeftCorner3D(-HALF_SIDELEN_CUBE, -HALF_SIDELEN_CUBE,
                                  STARTING_FRONT_DEPTH);
  Point3D frontBottomRightCorner3D(HALF_SIDELEN_CUBE, -HALF_SIDELEN_CUBE,
                                   STARTING_FRONT_DEPTH);

  // Back side of test cube
  Point3D backTopRightCorner3D(HALF_SIDELEN_CUBE, HALF_SIDELEN_CUBE,
                               STARTING_BACK_DEPTH);
  Point3D backTopLeftCorner3D(-HALF_SIDELEN_CUBE, HALF_SIDELEN_CUBE,
                              STARTING_BACK_DEPTH);
  Point3D backBottomLeftCorner3D(-HALF_SIDELEN_CUBE, -HALF_SIDELEN_CUBE,
                                 STARTING_BACK_DEPTH);
  Point3D backBottomRightCorner3D(HALF_SIDELEN_CUBE, -HALF_SIDELEN_CUBE,
                                  STARTING_BACK_DEPTH);

  // Cube Initialization
  unique_ptr<Cube3D> cubeXYZ = make_unique<Cube3D>(
      frontTopRightCorner3D, frontTopLeftCorner3D, frontBottomRightCorner3D,
      frontBottomLeftCorner3D, backTopRightCorner3D, backTopLeftCorner3D,
      backBottomRightCorner3D, backBottomLeftCorner3D, STARTING_FRONT_DEPTH);

  vector<Point2D> cubePointsTest;

  int count = 0;

  // Clear the screen and set cursor to home
  cout << "\x1b[?1049h\x1b[?25l" << flush;
  while (1) {

    vector<vector<char>> buffer(SCENE_HEIGHT, vector<char>(SCENE_WIDTH, ' '));

    // Camera Point (Pinhole)
    Point3D cameraPoint(0, 0, 0);
    Angle3D anglePoint(count, 0, 0);
    Camera3D camera(cameraPoint, anglePoint);

    // E value (the plane we are projecting onto)
    Point3D displaySurface(0, 0, CAM_DISTANCE);

    // 2D cube initialization
    unique_ptr<Cube2D> cubeXY =
        make_unique<Cube2D>(*cubeXYZ, displaySurface, camera);

    for (int i = 0; i < cubeXY->points.size(); i++) {
      // We can try to convert these points to terminal-friendly points.
      int screenX = cubeXY->points[i].x + SCENE_WIDTH / 2;
      int screenY = SCENE_HEIGHT / 2 - cubeXY->points[i].y;

      // Printing logic
      if (screenX < SCENE_WIDTH && screenX > 0 && screenY < SCENE_HEIGHT &&
          screenY > 0) {
        buffer[screenY][screenX] = '.';
        cubePointsTest.push_back(Point2D(screenX, screenY));
      }
    }

    cout << "\x1b[2J\x1b[H";
    for (int y = 0; y < SCENE_HEIGHT; y++) {
      for (int x = 0; x < SCENE_WIDTH; x++) {
        cout << buffer[y][x];
      }
      cout << "\n";
    }
    cout << flush;
    usleep(10000);
    count++;
  }

  // Move cursor to bottom of terminal for space purposes
  cout << "\x1b[" << SCENE_HEIGHT + 1 << "H";
  cout << "\x1b[?25h" << flush;

  // for (int i = 0; i < cubePointsTest.size(); i++) {
  //   cout << "X: " << cubePointsTest[i].x << endl;
  //   cout << "Y: " << cubePointsTest[i].y << endl;
  // }

  return 0;
}
