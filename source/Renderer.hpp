#pragma once

#include "ResManager.hpp"
#include "Model.hpp"

#include <vector>

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
private:
    std::vector<Model*> renderList;
public:
    static Renderer* globalRenderer;

	Renderer(int* argc, char** argv);
    void startLoop();
	void renderModels();
    void addModel(ResManager* resMgr, int id);
};
