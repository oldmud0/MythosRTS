#pragma once

#include <string>

#include <glm/glm.hpp>
#ifdef __APPLE__
#   include <GLUT/glut.h>
#else
#   include <GL/glut.h>
#endif

struct Texture {
	GLuint id;
	
	//Identify whether it is specular, diffuse, etc. so we can put in the right shader.
	std::string type;
};