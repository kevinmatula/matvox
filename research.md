## 🧮 Notes on Mathematical Principles Used and Development Process

#### Thoughts (12/4/25):
- I know that linear algebra must be used in order to project a 3D point onto a 2D screen, so we will have to utilize various projection matrices.
- It is important to note that our camera will influence the "depth perception" of our shapes, thus changing the ASCII characters representing each pixel of our scene.
- Currently, my goal is to hardcode values for a simple 3D cube and get it rendered on to the terminal, and following that I will add movement mechanics and eventually face-culling.
- YouTube videos have been my savior, as well as well-formed questions on Google.
- Resources: [Stack Overflow Thread](https://stackoverflow.com/questions/38909696/2d-coordinate-to-3d-world-coordinate), [OpenGL Thread](https://gamedev.stackexchange.com/questions/178643/the-view-matrix-finally-explained), [This YT Video](https://youtu.be/0E0UBphVRhY?si=kSGusPsY1c5QSSQM)

#### Thoughts (12/6/25):
- Here is a rough road map for the rest of the project: Project points for the corner of the cube -> organize code and entry point -> parse file data to create scenes of voxel cubes -> enable movement via affine transformation.
- Resources: [ANSI Wiki](https://en.wikipedia.org/wiki/ANSI_escape_code), [Ansi Repo](https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797), [Perspective Projection Wiki](https://en.wikipedia.org/wiki/3D_projection#Mathematical_formula)
