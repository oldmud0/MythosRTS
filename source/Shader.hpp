#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

struct Shader {
    GLuint program,
           vertexShader,
           fragmentShader;
};