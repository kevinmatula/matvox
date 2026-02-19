#include "include/Object/Cube2D.hpp"
#include "include/Object/Cube3D.hpp"
#include "include/Position/Camera3D.hpp"
#include "include/Position/Point2D.hpp"
#include "include/Position/Point3D.hpp"
#include <iostream>
#include <memory>
#include <signal.h>
#include <unistd.h>
#include <vector>

using namespace std;

// cool-ass cleanup function that stops CPU mid instruction to run this command.
void cleanup(int) {
  cout << "\x1b[?1049l\x1b[?25h" << flush;
  cout << "Matvox Was Closed." << endl;
  _exit(0);
}

// This function takes the entire buffer and turns it into a string
// This functions reduces flicker by rendering entire string at once and then
// outputting that!
string renderScreen(vector<vector<char>> buf, int SCENE_WIDTH,
                    int SCENE_HEIGHT) {
  string screen = "";
  for (int y = 0; y < SCENE_HEIGHT; y++) {
    for (int x = 0; x < SCENE_WIDTH; x++) {
      screen += buf[y][x];
    }
    if (y < SCENE_HEIGHT - 1) {
      screen += "\n";
    }
  }
  return screen;
}

int main() {

  signal(SIGINT, cleanup);
  signal(SIGTERM, cleanup);

  const int SIDELEN_CUBE = 30;
  const int HALF_SIDELEN_CUBE = SIDELEN_CUBE / 2;
  const int STARTING_FRONT_DEPTH = 40;
  const int STARTING_BACK_DEPTH = STARTING_FRONT_DEPTH + SIDELEN_CUBE;

  const int SCENE_WIDTH = 110;
  const int SCENE_HEIGHT = 40;

  const int CAM_DISTANCE = 10;

  vector<Point3D> cubePoints;

  // Initial Idea of for-Loop to initialize front and back face of cube
  // structure
  for (int x = -HALF_SIDELEN_CUBE; x <= HALF_SIDELEN_CUBE; x++) {
    for (int y = -HALF_SIDELEN_CUBE; y <= HALF_SIDELEN_CUBE; y++) {
      cubePoints.push_back(Point3D(x, y, STARTING_FRONT_DEPTH));
      cubePoints.push_back(Point3D(x, y, STARTING_BACK_DEPTH));
    }
  }

  // Initial Idea of for-Loop to initialize left and right face of cube
  // structure
  for (int y = -HALF_SIDELEN_CUBE; y <= HALF_SIDELEN_CUBE; y++) {
    for (int z = STARTING_FRONT_DEPTH; z <= STARTING_BACK_DEPTH; z++) {
      cubePoints.push_back(Point3D(-HALF_SIDELEN_CUBE, y, z));
      cubePoints.push_back(Point3D(HALF_SIDELEN_CUBE, y, z));
    }
  }

  // Initial Idea of for-Loop to initialize top and bottom face of cube
  // structure
  for (int x = -HALF_SIDELEN_CUBE; x <= HALF_SIDELEN_CUBE; x++) {
    for (int z = STARTING_FRONT_DEPTH; z <= STARTING_BACK_DEPTH; z++) {
      cubePoints.push_back(Point3D(x, -HALF_SIDELEN_CUBE, z));
      cubePoints.push_back(Point3D(x, HALF_SIDELEN_CUBE, z));
    }
  }

  // Cube Initialization
  unique_ptr<Cube3D> cubeXYZ =
      make_unique<Cube3D>(cubePoints, STARTING_FRONT_DEPTH);

  int count = 0;

  // Clear the screen and set cursor to home
  cout << "\x1b[?1049h\x1b[?25l" << flush;

  while (1) {

    vector<vector<char>> buffer(SCENE_HEIGHT, vector<char>(SCENE_WIDTH, ' '));

    // Camera Point (Pinhole)
    Point3D cameraPoint(30, 20, 0);
    Angle3D anglePoint(0, 0, 0);
    Camera3D camera(cameraPoint, anglePoint);

    // E value (the plane we are projecting onto)
    Point3D displaySurface(0, 0, CAM_DISTANCE);

    // 2D cube initialization
    unique_ptr<Cube2D> cubeXY =
        make_unique<Cube2D>(*cubeXYZ, displaySurface, camera);

    for (int i = 0; i < cubeXY->points.size(); i++) {
      // Convert these points to terminal-friendly points.
      int screenX = cubeXY->points[i].x + SCENE_WIDTH / 2;
      int screenY = SCENE_HEIGHT / 2 - cubeXY->points[i].y;

      // Printing logic
      if (screenX < SCENE_WIDTH && screenX > 0 && screenY < SCENE_HEIGHT &&
          screenY > 0) {
        buffer[screenY][screenX] = '@';
      }
    }

    cout << "\x1b[H";
    cout << renderScreen(buffer, SCENE_WIDTH, SCENE_HEIGHT);

    cout << flush;

    usleep(10000);

    count++;
  }

  return 0;
}
