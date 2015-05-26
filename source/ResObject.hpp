#pragma once

#include <string>
#include <vector>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

class Texture;
class ResManager;

class ResObject {
private:
    ResManager* resManager;
protected:
    int id;
    std::string path;
public:
    ResObject(int _id, ResManager* _resMgr, std::string _path);
    ResObject();

    int getId();
    std::string getPath();
    ResManager* getResManager();
};