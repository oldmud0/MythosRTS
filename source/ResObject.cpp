#include "ResObject.hpp"
#include "ResManager.hpp"

ResObject::ResObject(int _id, ResManager* _resMgr, std::string _path)
    :id(_id),
     resManager(_resMgr),
     path(_path)
{}

int ResObject::getId(){
    return this->id;
}

std::string ResObject::getPath() {
    return this->path;
}

ResManager* ResObject::getResManager() {
    return resManager;
}