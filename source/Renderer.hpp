#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <glm/glm.hpp>
using namespace glm;
#ifdef __APPLE__
#   include <GLUT/glut.h>
#else
#   include <GL/glut.h>
#endif

class Renderer {
public:
	Renderer(int* argc, char** argv);
	void rendereModel();
private:
};