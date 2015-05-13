#include "MythosRTS.hpp"

class RenderObject : public ResObject {
private:
    vector<glm::vec4> vertices;
    vector<glm::vec3> normals ;
    vector<GLushort>  elements;

public:
    RenderObject(vector<glm::vec4> vertices;
    vector<glm::vec3> normals ;
    vector<GLushort>  elements;
    );
    void render();
}