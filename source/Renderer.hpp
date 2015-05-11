#ifndef STDIO
#	define STDIO
#	include <stdio.h>
#endif

#ifndef STDLIB
#	define STDLIB
#	include <stdlib.h>
#endif

#ifndef GLEW
#	define GLEW
#	include <GL/glew.h>
#endif

#ifndef GLM
#	define GLM
#	include <glm/glm.hpp>
using namespace glm;
#endif

#ifndef GLUT
#	define GLUT
#	ifdef __APPLE__
#	   include <GLUT/glut.h>
#	else
#	   include <GL/glut.h>
#	endif
#endif

class Renderer {
public:
	Renderer(int* argc, char** argv);
	void rendereModel();
private:
};