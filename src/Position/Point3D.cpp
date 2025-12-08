#include "../../include/Position/Point3D.hpp"
#include "../../include/Position/Camera3D.hpp"
#include <math.h>
#include <vector>

Point3D::Point3D(int x, int y, int z) : x(x), y(y), z(z) {}

Point3D Point3D::cameraTransformation(Camera3D camera) {
  // This represents the original point A subtracted by the 3D position
  // representing the camera.
  Point3D subtractionAlignment((x - camera.point.x), (y - camera.point.y),
                               (z - camera.point.z));

  // This represents the original point A rotated according to the angle of the
  // camera.
  std::vector<std::vector<double>> angleMatrix = {
      {std::cos(camera.angle.y) * std::cos(camera.angle.z),
       std::cos(camera.angle.y) * std::sin(camera.angle.z),
       -1 * std::sin(camera.angle.y)},
      {(std::sin(camera.angle.x) * std::sin(camera.angle.y) *
        std::cos(camera.angle.z)) -
           (std::cos(camera.angle.x) * std::sin(camera.angle.z)),
       (std::sin(camera.angle.x) * std::sin(camera.angle.y) *
        std::sin(camera.angle.z)) +
           (std::cos(camera.angle.x) * std::cos(camera.angle.z)),
       std::sin(camera.angle.x) * std::cos(camera.angle.y)},
      {(std::cos(camera.angle.x) * std::sin(camera.angle.y) *
        std::cos(camera.angle.z)) +
           (std::sin(camera.angle.x) * std::sin(camera.angle.z)),
       (std::cos(camera.angle.x) * std::sin(camera.angle.y) *
        std::sin(camera.angle.z)) -
           (std::sin(camera.angle.x) * std::cos(camera.angle.z)),
       std::cos(camera.angle.x) * std::cos(camera.angle.y)}};

  // This represents the matrix times the vector, to get a full vector
  // representing the transformation.
  Point3D finalCameraVector(angleMatrix[0][0] * subtractionAlignment.x +
                                angleMatrix[0][1] * subtractionAlignment.y +
                                angleMatrix[0][2] * subtractionAlignment.z,
                            angleMatrix[1][0] * subtractionAlignment.x +
                                angleMatrix[1][1] * subtractionAlignment.y +
                                angleMatrix[1][2] * subtractionAlignment.z,
                            angleMatrix[2][0] * subtractionAlignment.x +
                                angleMatrix[2][1] * subtractionAlignment.y +
                                angleMatrix[2][2] * subtractionAlignment.z);

  return finalCameraVector;
}
