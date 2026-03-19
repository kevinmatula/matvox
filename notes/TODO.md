## Current Status

The base functionality of the engine works.

- We can render one ASCII cube (currently in one character only).
- Move around the space with WASD.

---

## Areas for Improvement

There are, however, many quality of life things we can add.

### Roadmap

- Finish polishing the engine
- Allow the engine to be "customer facing," meaning that we build out functions to be usable by others.

### Features to Add

Here are a few features that should be added in order to polish the engine:

#### Immediate (Ordered)

- Render the cubes by making each face have a different color (grayscale is fine), note that we will no longer support shading in this engine.
- FIX: Bug where some random lines of cube aren't drawn when touching cube.
- **MAYBE** FIX: Make cube more cubish and less rectangular.
- Fix the design schema so that a user can spawn multiple cubes using a simple function instead of manually inserting the location.
- Implement face culling, so pixels are only rendered when they are calculated to be shown on the screen.

#### Reach/Later
- Allow users to look around with either their mouse or using the arrow keys, this will change their viewing angle.
- Explore procedurally generated "maps."
- Implement functionality for a single file to render an entire map.
- Standard Controller Compatibility.
- Port to a samsung smart fridge (genuinely).
