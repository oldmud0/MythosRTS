#include "ResManager.hpp"

ResManager::ResManager()
    :num_objects(0)
{}

/**
 * Takes a .3DO (.obj) file
*/
void ResManager::loadModel(std::string modelName) {
    std::cerr << "Model loading is unimplemented! We are going to switch to a furreal loader!" << std::endl;
    exit(1);
}

bool ResManager::unloadResource(int id) {
    std::map<int, ResObject*>::iterator resource = this->resList.find(id);
    if (resource->second == NULL) {
        return false;
    }

    this->resList.erase(resource);
    return true;
}