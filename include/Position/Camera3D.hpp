#ifndef CAMERA3D_HPP
#define CAMERA3D_HPP

#include "Angle3D.hpp"
#include "Point3D.hpp"

// This struct represents a camera in our scene.
struct Camera3D {
  Point3D point;
  Angle3D angle;

  Camera3D(Point3D point, Angle3D angle) : point(point), angle(angle) {};
};

#endif
