#include "ResManager.hpp"

ResManager::ResManager()
    :num_objects(0)
{}

/**
 * Takes a .obj file and returns a reference to the resource object as stored
 * in the resource list.
*/
RenderObject& ResManager::loadModel(std::string modelName) {
    std::ifstream file(modelName.c_str());
    if (!file) {
        std::cerr << "ERROR: cannot open " << modelName << '\n';
    }

    std::vector<vec4> vertices;
    std::vector<vec3> normals;
    std::vector<GLushort>  elements;

    for (std::string line; std::getline(file, line);) {
        if (line.substr(0,2) == "v ") {
            std::istringstream s(line.substr(2).c_str());
            vec4 v; s >> v.x; s >> v.y; s >> v.z; v.w = 1.0f;
            vertices.push_back(v);
        } else if (line.substr(0,2) == "f ") {
            std::istringstream s(line.substr(2));
            GLushort a,b,c;
            s >> a; s >> b; s >> c;
            a--; b--; c--;
            elements.push_back(a); elements.push_back(b); elements.push_back(c);
        } else if (line[0] == '#') {
            //It's a comment, forget about it 
            continue;
        } else {
            //Colors? Forget it
            continue;
        }
    }

    normals.resize(vertices.size(), vec3(0.0, 0.0, 0.0));
    for (int i = 0; i < elements.size(); i+=3) {
        GLushort ia = elements[i];
        GLushort ib = elements[i+1];
        GLushort ic = elements[i+2];
        vec3 normal = normalize(cross(
        vec3(vertices[ib]) - vec3(vertices[ia]),
        vec3(vertices[ic]) - vec3(vertices[ia])));
        normals[ia] = normals[ib] = normals[ic] = normal;
    }

    RenderObject* render_object = new RenderObject(
        ++this->num_objects, 
        &vertices, 
        &normals, 
        &elements
    );
    this->resList[render_object->getId()] = render_object;
}

bool ResManager::unloadResource(int id) {
    std::map<int, ResObject*>::iterator resource = this->resList.find(id);
    if (resource->second == NULL) {
        return false;
    }

    this->resList.erase(resource);
    return true;
}