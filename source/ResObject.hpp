#pragma once

#include "ResManager.hpp"

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