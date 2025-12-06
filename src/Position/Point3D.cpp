#include "../../include/Position/Point3D.hpp"
#include "../../include/Position/Camera3D.hpp"

Point3D::Point3D(int x, int y, int z) : x(x), y(y), z(z) {}

Point3D cameraTransformation(Point3D originalPoint, Camera3D camera) {
  // This represents the original point A subtracted by the 3D position
  // representing the camera.
  Point3D subtractionAlignment((originalPoint.x - camera.point.x),
                               (originalPoint.y - camera.point.y),
                               (originalPoint.z - camera.point.z));
}
