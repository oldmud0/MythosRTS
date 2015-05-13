#include "ResManager.hpp"

/**
 * Takes a .obj file and returns a reference to the resource object as stored
 * in the resource list.
*/
RenderObject& ResManager::loadModel(std::string modelName) {
    std::ifstream in(modelName, ios::in);
    if (!in) {
        std::cerr << "ERROR: cannot open " << modelName << '\n';
    }

    vector<glm::vec4> vertices;
    vector<glm::vec3> normals ;
    vector<GLushort>  elements;

    std::string line;

    while (std::getline(in, line)) {
        if      (line.substr(0,2) == "v ") {
            std::istringstream s(line.substr(2));
            glm::vec4 v; s >> v->x; s >> v->y; s >> v->z; v->w = 1.0f;
            vertices->push_back(v);
        }
        else if (line.substr(0,2) == "f ") {
            std::istringstream s(line.substr(2));
            GLushort a,b,c;
            s >> a; s >> b; s >> c;
            a--; b--; c--;
            elements->push_back(a); elements->push_back(b); elements->push_back(c);
        }
        else if (line[0] == '#') {
            //It's a comment, forget about it 
        }
        else {
            //Colors? Forget it
        }
    }

    normals.resize(vertices.size(), glm::vec3(0.0, 0.0, 0.0));
    for (int i = 0; i < elements.size(); i+=3) {
        GLushort ia = elements[i];
        GLushort ib = elements[i+1];
        GLushort ic = elements[i+2];
        glm::vec3 normal = glm::normalize(glm::cross(
        glm::vec3(vertices[ib]) - glm::vec3(vertices[ia]),
        glm::vec3(vertices[ic]) - glm::vec3(vertices[ia])));
        normals[ia] = normals[ib] = normals[ic] = normal;
    }

    RenderObject* obj(vertices, normals, elements);
    this->resList[&obj] = *obj;
}

bool ResManager::unloadResource(ResObject* obj) {
    if (obj == NULL) {
        return false;
    }

    this->resList.erase(&obj);
}