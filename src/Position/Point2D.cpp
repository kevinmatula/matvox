#include "../../include/Position/Point2D.hpp"

// This is our constructor implementation.
Point2D::Point2D(int x, int y) : x(x), y(y) {}

// This is our function for projecting a 3D point to a 2D point, using the
// formula derived from wikipedia page on perspective projection, here we cast
// everything to integer.
Point2D::Point2D(Point3D cameraTransformation, Point3D displaySurface) {
  double scale = static_cast<double>(displaySurface.z) / cameraTransformation.z;
  x = static_cast<int>(scale * cameraTransformation.x + displaySurface.x);
  y = static_cast<int>(scale * cameraTransformation.y + displaySurface.y);
}
