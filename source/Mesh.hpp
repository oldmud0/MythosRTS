#pragma once

#include <vector>
#include <sstream>

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "Vertex.hpp"
#include "Texture.hpp"
#include "Shader.hpp"

using namespace glm;

class Mesh {
private:
    std::vector<Vertex>  vertices;
    std::vector<GLuint>  elements;
    std::vector<Texture> textures;

    GLuint vao, vbo, ebo;
public:
    //The implementation is empty, so let's save us some work and 
    //just keep it in the header.
    Mesh(
        std::vector<Vertex>  _vertices,
        std::vector<GLuint>  _elements,
        std::vector<Texture> _textures
    )
    :   vertices(_vertices),
        elements(_elements),
        textures(_textures)
    {}

    void render(Shader shader);
    void setup();
};