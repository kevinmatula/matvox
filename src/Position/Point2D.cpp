#include "../../include/Position/Point2D.hpp"

// This is our constructor implementation. p
Point2D::Point2D(int x, int y) : x(x), y(y) {}

// This is our function for projecting a 3D point to a 2D point, using the
// formula derived from wikipedia page on perspective projection.
Point2D::Point2D(Point3D cameraTransformation, Point3D displaySurface) {
  x = ((displaySurface.z / cameraTransformation.z) * cameraTransformation.x) +
      displaySurface.x;
  y = ((displaySurface.z / cameraTransformation.z) * cameraTransformation.y) +
      displaySurface.y;
}
