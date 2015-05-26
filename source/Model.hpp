#pragma once

#include "ResObject.hpp"
#include "Mesh.hpp"

#include <string>
#include <vector>

#include <GL/glew.h>
#include <glm/glm.hpp>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

using namespace glm;

class Model : public ResObject {
private:
    std::vector<Mesh> meshes;
public:
    Model(
        int         _id,
        ResManager* _rm,
        std::string _path
        ) : ResObject(_id, _rm, _path)
    {}

    static void modelProcessNode(Model* model, aiNode* node, const aiScene* scene);
    static Mesh modelProcessMesh(Model* model, aiMesh* mesh, const aiScene* scene);

    using ResObject::getId;
    using ResObject::getResManager;
    using ResObject::getPath;
};