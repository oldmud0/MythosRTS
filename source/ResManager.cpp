#include "ResManager.hpp"

ResManager::ResManager()
    :num_objects(0)
{}

/**
 * Takes any supported Assimp model format. Make sure it has shaders along with it.
*/
int ResManager::loadModel(std::string modelName) {
    Assimp::Importer importer;
    Model* model = new Model(getFreeId(), this, modelName.substr(0, modelName.find_last_of('/')));

    const aiScene* scene = importer.ReadFile(modelName, 
                     aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_OptimizeMeshes);

    if (!scene || scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
    {
        std::cout << "Error loading model! " << importer.GetErrorString() << std::endl; //endl has horrible performance, but whatever.
        return;
    }

    Model::modelProcessNode(model, scene->mRootNode, scene);

    //Add to map
    this->resList[model->getId()] = dynamic_cast<ResObject *>(model);
    num_objects++;
}

std::vector<Texture> ResManager::loadMaterialTextures(aiMaterial* mat, aiTextureType texType, std::string typeName, std::string path) {
    std::vector<Texture> textures;
    for (GLuint i = 0; i < mat->GetTextureCount(texType); i++)
    {
        aiString str;
        mat->GetTexture(texType, i, &str);
        Texture texture(getFreeId(), this, path, getTextureFromFile(std::string(str.C_Str()) + '/' + path), typeName);

        textures.push_back(texture);
    }
    return textures;
}

GLint ResManager::getTextureFromFile(std::string path) {
    //TODO
}

//Gets a nonoccupied ID for a new ResObject.
//Okay, this is a terrible implementation for a free ID. But it's for a good cause.
int ResManager::getFreeId() {
    srand(time(NULL));
    return rand();
}

bool ResManager::unloadResource(int id) {
    std::map<int, ResObject*>::iterator resource = this->resList.find(id);
    if (resource->second == NULL) {
        return false;
    }

    this->resList.erase(resource->first);
    this->num_objects--;
    return true;
}