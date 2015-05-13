#include "RenderObject.hpp"

RenderObject::RenderObject(vector<glm::vec4> vertices,
                           vector<glm::vec3> normals,
                           vector<GLushort>  elements)
{
    this->vertices = vertices;
    this->normals = normals;
    this->elements = elements;
}

RenderObject::render() {
    
}