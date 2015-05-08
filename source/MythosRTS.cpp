#include "stdio.h"
#include <stdlib.h>

#include <GL/glew.h>
#include <GL/glut.h>

int main(int argc, char* argv[]){
	glutInit (& argc, argv);
	glutCreateWindow ("GLEW Test");
	GLenum err = glewInit ();
	return 0;
}