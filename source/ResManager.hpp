#include "MythosRTS.hpp"

#ifndef MAP
#   define MAP
#   include <map>
#endif

#ifndef VECTOR
#   define VECTOR
#   include <vector>
#endif

#ifndef RESOBJECT
#   define RESOBJECT
#   include "ResObject.hpp"
#endif

#ifndef RENDEROBJECT
#   define RENDEROBJECT
#   include "RenderObject.hpp"
#endif

#ifndef STRING
#   define STRING
#   include <string>
#endif

#ifndef GLM
#   define GLM
#   include <glm/glm.hpp>
using namespace glm;
#endif

#ifndef IOSTREAM
#   define IOSTREAM
#   include <iostream>
#endif

#ifndef FILESTREAM
#   define FILESTREAM
#   include <fstream>
#endif

#ifndef SSTREAM
#   define SSTREAM
#   include <sstream>
#endif

class ResManager {
private:
    std::map<int, ResObject*> resList;
    int num_objects;
public:
    ResManager();
    RenderObject& loadModel(std::string modelName);
    bool unloadResource(int id);
};
