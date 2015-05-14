#include "RenderObject.hpp"

RenderObject::RenderObject( int _id, 
                            std::vector<vec4>* _vertices,
                            std::vector<vec3>* _normals,
                            std::vector<GLushort>*  _elements)
   :ResObject(_id),
    vertices(_vertices),
    normals(_normals),
    elements(_elements)
{}

void RenderObject::render() {
    return;
}