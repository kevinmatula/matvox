# ⬡ matvox
matvox is an efficient, terminal-based voxel engine. All graphics are rendered with ASCII characters using the CPU .

## ⛏ Features
- matvox allows users to roam freely.
- matvox comes out of the box with various performance optimizations, such as face culling.

## 🧮 Notes on Mathematical Principles Used and Development Process
#### Day 1 (12/4/25):
- In order to get this entire process to work, we need a class that represents 2D points and a class that represents 3D points. 
- I know that linear algebra must be used in order to project a 3D point onto a 2D screen, so we will have to utilize various projection matrices.
- It is important to note that our camera will influence the "depth perception" of our shapes, thus changing the ASCII characters representing each pixel of our scene.
- Currently, my goal is to hardcode values for a simple 3D cube, and get it rendered on to the terminal, after I will begin adding concepts from CS3520 in order to optimize and better this program, and following that I will add movement mechanics and eventually face-culling.
- YouTube videos have been my savior, as well as well-formed questions on Google.
- Resources: [Stack Overflow Thread](https://stackoverflow.com/questions/38909696/2d-coordinate-to-3d-world-coordinate), [OpenGL Thread](https://gamedev.stackexchange.com/questions/178643/the-view-matrix-finally-explained), [This YT Video](https://youtu.be/0E0UBphVRhY?si=kSGusPsY1c5QSSQM)
