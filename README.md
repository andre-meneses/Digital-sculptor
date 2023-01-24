# Digital Sculptor

## Introduction
This project was developed as part of an advanced programming class, the goal was to build a program that allows the user to draw three dimensional figures from basic forms such as spheres, boxes and elipses. 

## Implementation  

### Voxel
The figures are drawn from 3d pixels called voxels. Each drawing constitutes a matrix of voxels that are arranged according to the user instructions. A voxel can be positioned individually through an (x,y,z) coordinate, or a more complex form that draws several voxels can be choosen. Voxels can also be erased in order to create negative spaces.

### Source code organization
The program is built around the abstract class 'figuraGeometrica'. The class defines a virtual function 'draw' and the attributes 'r,g,b,a'. Each geometric form is a child class of 'figuraGeometrica' that implements its own version of the function 'draw'.

The method 'parse' from the class 'interpreter' is responsible for performing the appropriate function calls. To add more drawing instruction types(geometric forms), it suffices to create a class that inherits 'figuraGeometrica' and to update the 'parse' function accordingly.

## How to run it
1. Clone the repository. 
2. Make a .txt file with drawing instructions, such as 
3. Compile the code using g++ or the makefile
```sh
~$ make all 
~$ ./sculptor
```
4. Type in the relative path of the input file.
5. The resulting .off file will be written inside of 'output/'.

### Input
The user draws a figure by providing a .txt file with drawing instructions. Each file must start with the instruction 'dim x y z' where x,y,z are the sculpture dimensions. The following instructions are available:
1. putvoxel x0 y0 z0 r g b a
2. putbox x0 x1 y0 y1 z0 z1 r g b a
3. putsphere x0 y0 z0 radius rgba
4. putellipsoid x0 y0 z0 radiusx radiusy radiusz r g b a
5. cutvoxel x y z
6. cutbox x0 x1 y0 y1 z0 z1
7. cutsphere x0 y0 z0 radius
8. cutellipsoid x0 y0 z0 radius

An instructions file example:
```
dim 55 55 55
putbox 0 19 0 19 0 9 64 224 208 0.9
putsphere 9 9 22 8 64 224 208 0.9
putellipsoid 9 9 42 7 3 9 64 224 208 0.9
cutbox 9 17 9 17 22 30
cutellipsoid 11 15 9 7 9 4
cutsphere 10 8 42 5
```
Once the drawing is finished, an OFF file is created. One can visualize it by using a program such as MeshLab or geomview. 
