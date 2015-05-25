#include "RenderObject.hpp"

void RenderObject::render() {
    GLuint diffuseN = 1, specularN = 1;
    for(GLuint i = 0; i < this->textures.size(); i++) {
        glActiveTexture(GL_TEXTURE0 + i); //Set active texture before bind

        //Get tex number
        std::stringstream ss;
        std::string num, name = this->textures[i].type;

        if     (name == "texture_diffuse")
            ss << diffuseN++;
        else if(name == "texture_specular")
            ss << specularN++;
        num = ss.str();

        glUniform1f(glGetUniformLocation(this->shader.program, ("material." + name + num).c_str()), i);
        glBindTexture(GL_TEXTURE_2D, this->textures[i].id);
    }

    //Draw stuff
    glActiveTexture(GL_TEXTURE0);

    glUseProgram(this->shader.program);
    glBindVertexArray(this->vao);
    glDrawElements(GL_TRIANGLES, this->elements.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

void RenderObject::setup() {
    glGenVertexArrays(1, &this->vao);

    glGenBuffers(1, &this->vbo);
    glGenBuffers(1, &this->ebo);

    glBindVertexArray(this->vao);

    //Fill the VBO with vertex positions
    glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
    glBufferData(GL_ARRAY_BUFFER,
                 this->vertices.size() * sizeof(Vertex),
                 &this->vertices[0], 
                 GL_STATIC_DRAW);

    //Fill the EBO with vertex element IDs
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 
                 this->elements.size() * sizeof(GLuint),
                 &this->elements[0], 
                 GL_STATIC_DRAW);

    //Vertex positions. Works perfectly with structs.
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 
                          (GLvoid *) 0);

    //Vertex normals
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 
                          (GLvoid *) offsetof(Vertex, normal));

    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), 
                          (GLvoid *) offsetof(Vertex, texCoords));

    glBindVertexArray(0);
}
