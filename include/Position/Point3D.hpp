#ifndef POINT3D_HPP
#define POINT3D_HPP

struct Camera3D;

class Point3D {
public:
  double x, y, z;

  // This is our constructor.
  Point3D(double x, double y, double z);

  // TODO: add a method to find a vector d that represents the position of a
  // point with respect to the coordinate system defined by the camera.
  // NOTE: so far, we have completed a - c portion, now we just need to multiply
  // by rotation matrix.
  // Consider pre-computing for optimization.
  Point3D cameraTransformation(Camera3D camera) const;
};

#endif
