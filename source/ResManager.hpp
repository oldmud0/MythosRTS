#pragma once

#include "ResObject.hpp"
#include "RenderObject.hpp"

#include <map>
#include <vector>
#include <string>
#include <glm/glm.hpp>
using namespace glm;
#include <iostream>
#include <fstream>
#include <sstream>

#include <iostream>

class ResManager {
private:
    std::map<int, ResObject*> resList;
    int num_objects;
public:
    ResManager();
    void loadModel(std::string modelName);
    bool unloadResource(int id);
};
