#ifndef POINT3D_HPP
#define POINT3D_HPP

struct Camera3D;

class Point3D {
public:
  int x, y, z;

  // This is our constructor.
  Point3D(int x, int y, int z);

  // TODO: add a method to find a vector d that represents the position of a
  // point with respect to the coordinate system defined by the camera.
  // NOTE: so far, we have completed a - c portion, now we just need to multiply
  // by rotation matrix.
  Point3D cameraTransformation(Point3D originalPoint, Camera3D camera);
};

#endif
