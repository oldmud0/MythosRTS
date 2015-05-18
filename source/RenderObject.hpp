#pragma once

#include "ResObject.hpp"

#include <vector>
#include <GL/glew.h>
#include <glm/glm.hpp>
using namespace glm;


class RenderObject : public ResObject {
private:
    std::vector<vec4>* vertices;
    std::vector<vec3>* normals;
    std::vector<GLushort>*  elements;
public:
    RenderObject(
        int _id, 
        std::vector<vec4>* _vertices,
        std::vector<vec3>* _normals,
        std::vector<GLushort>* _elements
    );
    void render();
    using ResObject::getId;
};