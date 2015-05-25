#pragma once

#include <vector>
#include <sstream>

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "ResObject.hpp"
#include "Vertex.hpp"
#include "Texture.hpp"
#include "Shader.hpp"

using namespace glm;

class RenderObject : public ResObject {
private:
    std::vector<Vertex>  vertices;
    std::vector<vec3>    normals;
    std::vector<GLuint>  elements;
    std::vector<Texture> textures;
    Shader               shader;

    GLuint vao, vbo, ebo;
public:
    //The implementation is empty, so let's save us some work and 
    //just keep it in the header.
    RenderObject(
        int _id, 
        std::vector<Vertex>  _vertices,
        std::vector<vec3>    _normals,
        std::vector<GLuint>  _elements,
        std::vector<Texture> _textures,
        Shader               _shader
    )
    :   ResObject(_id),
        vertices(_vertices),
        normals(_normals),
        elements(_elements),
        textures(_textures),
        shader(_shader)
    {}

    void render();
    void setup();
    using ResObject::getId;
};