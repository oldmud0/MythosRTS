#include "ResObject.hpp"

ResObject::ResObject(int _id)
    :id(_id){}

int ResObject::getId(){
    return this->id;
}