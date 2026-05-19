*This project has been created as part of the 42 curriculum by jslim, rghandou.*

# miniRT

## Description

miniRT is a small ray tracer written in C with MiniLibX. It renders a scene from a `.rt` file using basic ray tracing: one camera, ambient light, one point light, hard shadows, and simple geometric objects.

The mandatory supported objects are:

- Sphere
- Plane
- Cylinder

The renderer supports object position and orientation where applicable, camera orientation, ambient lighting, diffuse lighting, hard shadows, and finite cylinder caps.

## Instructions

Build the project:

```sh
make
```

Run miniRT with a scene file:

```sh
./miniRT scenes/simple.rt
```

Another example scene:

```sh
./miniRT scenes/showcase.rt
```

Clean build files:

```sh
make clean
```

Remove the executable and build files:

```sh
make fclean
```

Rebuild:

```sh
make re
```

## Scene Format

Scene files use the `.rt` extension. Each line describes one scene element:

```rt
A 0.2 255,255,255
C 0,0,0 0,0,1 70
L 10,10,10 0.7 255,255,255
sp 0,0,20 10 255,0,0
pl 0,-5,0 0,1,0 0,120,255
cy 9,-2,19 0,1,0 4 8 40,220,90
```

Required unique elements:

- `A`: ambient lighting
- `C`: camera
- `L`: light

Object elements:

- `sp`: sphere
- `pl`: plane
- `cy`: cylinder

## Controls

- `ESC`: close the window
- Red cross: close the window
- `W` / up arrow: move camera forward
- `S` / down arrow: move camera backward
- `A` / left arrow: move camera left
- `D` / right arrow: move camera right
- `Q`: move camera down
- `E`: move camera up

Camera movement is a development/debug helper and is not required by the mandatory subject.

## Resources

- 42 miniRT subject
- MiniLibX documentation and manual pages
- Ray-sphere intersection formula
- Ray-plane intersection formula
- Finite cylinder intersection math
- `math.h` documentation

AI assistance was used as a learning and review aid for the execution side of the project: explaining ray tracing math, reviewing integration issues, helping debug build errors, and suggesting tests. The final code was developed by the project authors.
