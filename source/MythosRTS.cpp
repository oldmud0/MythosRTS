#include "stdio.h"
#include <stdlib.h>

#include <GL/glew.h>
#include <GL/glut.h>

static int make_resources(void){
    return 1;
}

static void update_fade_factor(void){
}

static void render(void){
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}


int main(int argc, char* argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(400, 300);
	glutCreateWindow("Hello World");
	glutDisplayFunc(&render);
	glutIdleFunc(&update_fade_factor);
}