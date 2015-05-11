MythosRTS
===

# Parteners: 
 - @tanishalfelven
 - @oldmud0

# Description
An RTS written in C++ utitlizing OpenGL.

# Goals / TODO
Here is a current set of goals for the MythoRTS project.

## Setup
 - Implement OpenGL library
 - Get cmake working

## Engine
 - OpenGL 3D landform viewer
 - Entity Viewer
 - Animations
 - AI
 - General game mechanics

# Install Directions
1. Obtain cmake from [cmake.org](http://www.cmake.org/download/). _Make sure to install latest version from website!_
2. Install System Libraries
	- Linux (Ubuntu)
		1. `sudo apt-get install libglm-dev freeglut3 freeglut3-dev libglu1-mesa-dev libxmu-dev libxi-dev`
	- Windows / Mac
		1. ???
3. Clone the project with `git clone https://github.com/tanishalfelven/MythosRTS.git`
4. Create a build folder with `mkdir build && cd build`
5. Put into your terminal `cmake ..` and it will generate the makefiles for you.
6. Now `make` the project. (For linux just use `make`)
7. Run `MythosRTS`!