#pragma once

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
#include <stdio.h>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

class Texture;
class ResObject;
class Shader;

class ResManager {
private:
    std::map<int, ResObject*> resList;
    int num_objects, nextId;
public:
    ResManager();
    int loadModel(std::string modelName);
    std::vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType texType, std::string typeName, std::string path);
    GLint getTextureFromFile(std::string path);

    int getFreeId();
    ResObject* getResource(int id);
    bool unloadResource(int id);
};
