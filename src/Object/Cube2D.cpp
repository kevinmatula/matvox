#include "../../include/Object/Cube2D.hpp"
#include "../../include/Object/Cube.hpp"
#include "../../include/Position/Camera3D.hpp"
#include "../../include/Position/Point2D.hpp"

// Constructs a cube using given points
Cube2D::Cube2D(Point2D frontTRg, Point2D frontTLg, Point2D frontBRg,
               Point2D frontBLg, Point2D backTRg, Point2D backTLg,
               Point2D backBRg, Point2D backBLg, int startingFrontDepth)
    : Cube(startingFrontDepth) {
  points.push_back(frontTRg), points.push_back(frontTLg),
      points.push_back(frontBLg), points.push_back(frontBRg),
      points.push_back(backTRg), points.push_back(backTLg),
      points.push_back(backBRg), points.push_back(backBLg);
}

// Constructs a cube using a given 3D cube and does computation
Cube2D::Cube2D(Cube3D cube3D, Point3D displaySurface, Camera3D camera)
    : Cube(cube3D.STARTING_FRONT_DEPTH) {
  for (int i = 0; i < cube3D.points.size(); i++) {
    Point2D point(cube3D.points[i].cameraTransformation(camera),
                  displaySurface);
    points.push_back(point);
  }
}
