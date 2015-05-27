#include "Renderer.hpp"

Renderer* Renderer::globalRenderer = 0;

GLfloat rotate;

void render(void) {
    // Clear Color and Depth Buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Reset transformations
    glLoadIdentity();
    // Set the camera
    gluLookAt(  0.0f, 0.0f,  5.0f,
                0.0f, 0.0f,  0.0f,
                0.0f, 1.0f,  0.0f);
    glRotatef(rotate, 0.f, 1.f, 0.f);
    rotate += 2.5f;

    Renderer::globalRenderer->renderModels();

    glutSwapBuffers();
    glutPostRedisplay();
}

void resize(int w, int h) {
    if(h == 0)
        h = 1;
    float ratio = 1.0 * w / h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(45,ratio,1,1000);
    glMatrixMode(GL_MODELVIEW);
}

Renderer::Renderer(int* argc, char** argv) {
    glutInit(argc, argv);

    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(320, 320);
    glutInitWindowPosition(-1, -1);
    glutCreateWindow("Mythos GL");

    glutDisplayFunc(render);
    glutReshapeFunc(resize);

    //glClearColor(1.f, 1.f, 1.f, 1.f);

    glewExperimental = GL_TRUE;
    GLenum err = glewInit();
    if(err != GLEW_OK) std::cout << "ERROR with GLEW! " << err << std::endl;
    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLSL   version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
}

void Renderer::startLoop() {
    rotate = 0.f;
    glutMainLoop();
}


void Renderer::renderModels() {
    for(int i = 0; i < this->renderList.size(); i++) {
        renderList[i]->render(renderList[i]->shader);
    }
}

void Renderer::addModel(ResManager* resMgr, int id) {
    //TODO add checks
    this->renderList.insert(this->renderList.begin(), (Model*)(resMgr->getResource(id)));
}