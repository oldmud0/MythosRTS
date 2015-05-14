#include "MythosRTS.hpp"

#ifndef VECTOR
#   define VECTOR
#   include <vector>
#endif

#ifndef GLM
#   define GLM
#   include <glm/glm.hpp>
using namespace glm;
#endif

#ifndef RESOBJECT
#   define RESOBJECT
#   include "ResObject.hpp"
#endif

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