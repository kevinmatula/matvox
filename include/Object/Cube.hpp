#ifndef CUBE_HPP
#define CUBE_HPP

// This is our class representation for a cube interface.
class Cube {
public:
  const int SIDELEN_CUBE = 20;
  const int HALF_SIDELEN_CUBE = SIDELEN_CUBE / 2;
  const int STARTING_FRONT_DEPTH;
  const int STARTING_BACK_DEPTH = STARTING_FRONT_DEPTH + SIDELEN_CUBE;

  Cube(int starting_front_depth) : STARTING_FRONT_DEPTH(starting_front_depth) {}
};

#endif
