#ifndef ANGLE3D_HPP
#define ANGLE3D_HPP

// This struct represents an angle in our scene. All fields of an angle are
// represented in degrees.
struct Angle3D {
  double x;
  double y;
  double z;

  Angle3D(double x, double y, double z) : x(x), y(y), z(z) {};
};

#endif
