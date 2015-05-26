#pragma once

#include "ResObject.hpp"
#include "Model.hpp"
#include "Texture.hpp"

#include <map>
#include <vector>
#include <string>
#include <glm/glm.hpp>
using namespace glm;
#include <iostream>
#include <fstream>
#include <sstream>
#include <iostream>

#include <cstdlib>
#include <ctime>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

class ResManager {
private:
    std::map<int, ResObject*> resList;
    int num_objects;
public:
    ResManager();
    int loadModel(std::string modelName);
    std::vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType texType, std::string typeName, std::string path);
    GLint getTextureFromFile(std::string path);

    int getFreeId();
    bool unloadResource(int id);
};
