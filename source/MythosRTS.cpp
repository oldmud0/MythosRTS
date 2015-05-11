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

void renderScene(void) {
    // Clear Color and Depth Buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Reset transformations
    glLoadIdentity();
    // Set the camera
    gluLookAt(  0.0f, 0.0f, 10.0f,
            0.0f, 0.0f,  0.0f,
            0.0f, 1.0f,  0.0f);

    

    glutSwapBuffers();
}

void changeSize(int w, int h) {
    if(h == 0)
        h = 1;
    float ratio = 1.0 * w / h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(45,ratio,1,1000);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(320, 320);
    glutInitWindowPosition(-1, -1);
    glutCreateWindow("Mythos RTS");

    glutDisplayFunc(renderScene);

    glutReshapeFunc(changeSize);

    // here is the idle func registration
    glutIdleFunc(renderScene);

    glutMainLoop();

    return 1;
}