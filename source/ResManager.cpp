#include "ResManager.hpp"

/**
 * Takes a .obj file and returns a reference to the RenderObject as stored
 * in the resource list.
*/
RenderObject& ResManager::loadResource(std::string modelName) {
    //TODO insert .obj loading code here
}

bool ResManager::unloadResource(RenderObject* obj) {
    if (obj == NULL) {
        return false;
    }

    //this->resList
}