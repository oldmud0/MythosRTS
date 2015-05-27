#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <GL/glew.h>
#include <glm/glm.hpp>

//Took straight off LearnOpenGL due to lack of time. Sorry if this offends anyone.
class Shader {
private:
    void checkCompileErrors(GLuint shader, std::string type);
public:
    GLuint program,
           vertexShader,
           fragmentShader;

    Shader(const GLchar* vertexPath, const GLchar* fragmentPath, const GLchar* geometryPath = NULL);
    Shader();
    
    void use();
};