#include "MythosRTS.hpp"

class ResManager {
private:
    std::map<int, ResObject*> resList;

public:
    ResManager();
    RenderObject& loadModel(std::string modelName);
    bool unloadResource(ResObject* obj);
};
