#include "include/Position/Camera3D.hpp"
#include "include/Position/Point2D.hpp"
#include "include/Position/Point3D.hpp"
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main() {

  const int SIDELEN_CUBE = 20;
  const int HALF_SIDELEN_CUBE = SIDELEN_CUBE / 2;
  const int STARTING_FRONT_DEPTH = 10;
  const int STARTING_BACK_DEPTH = STARTING_FRONT_DEPTH + SIDELEN_CUBE;

  const int SCENE_WIDTH = 100;
  const int SCENE_HEIGHT = 30;

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

  // Camera Point (Pinhole)
  Point3D cameraPoint(0, 0, 0);
  Angle3D anglePoint(0, 0, 0);
  Camera3D camera(cameraPoint, anglePoint);

  // E value (the plane we are projecting onto)
  Point3D displaySurface(0, 0, CAM_DISTANCE);

  // 3D TESTING:
  Point2D frontTopRightCorner2D(
      frontTopRightCorner3D.cameraTransformation(camera), displaySurface);
  Point2D frontTopLeftCorner2D(
      frontTopLeftCorner3D.cameraTransformation(camera), displaySurface);
  Point2D frontBottomRightCorner2D(
      frontBottomRightCorner3D.cameraTransformation(camera), displaySurface);
  Point2D frontBottomLeftCorner2D(
      frontBottomLeftCorner3D.cameraTransformation(camera), displaySurface);

  Point2D backTopRightCorner2D(
      backTopRightCorner3D.cameraTransformation(camera), displaySurface);
  Point2D backTopLeftCorner2D(backTopLeftCorner3D.cameraTransformation(camera),
                              displaySurface);
  Point2D backBottomRightCorner2D(
      backBottomRightCorner3D.cameraTransformation(camera), displaySurface);
  Point2D backBottomLeftCorner2D(
      backBottomLeftCorner3D.cameraTransformation(camera), displaySurface);

  vector<Point2D> cubePoints = {
      frontBottomLeftCorner2D,  frontTopLeftCorner2D,   frontTopRightCorner2D,
      frontBottomRightCorner2D, backBottomLeftCorner2D, backBottomRightCorner2D,
      backTopLeftCorner2D,      backTopRightCorner2D};
  vector<Point2D> cubePointsTest;

  // Clear the screen and set cursor to home
  cout << "\x1b[2J\x1b[H";

  for (int i = 0; i < cubePoints.size(); i++) {
    // We can try to convert these points to terminal-friendly points.
    int screenX = cubePoints[i].x + SCENE_WIDTH / 2;
    int screenY = SCENE_HEIGHT / 2 - cubePoints[i].y;

    // Printing logic
    cout << "\x1b[" << screenY << ";" << screenX << "H";
    // Plot a lil thingy
    cout << "*";
    cubePointsTest.push_back(Point2D(screenX, screenY));
  }

  // Move cursor to bottom of terminal for space purposes
  cout << "\x1b[30H";

  for (int i = 0; i < cubePointsTest.size(); i++) {
    cout << "X: " << cubePointsTest[i].x << endl;
    cout << "Y: " << cubePointsTest[i].y << endl;
  }

  return 0;
}
