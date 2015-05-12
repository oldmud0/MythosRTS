#include "MythosRTS.hpp"

class ResManager {
private:
    std::vector<RenderObject*> resList;

public:
    ResManager();
    RenderObject& loadResource(std::string modelName);
    bool unloadResource(RenderObject* obj);
};
