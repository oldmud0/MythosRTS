#pragma once

#include "ResObject.hpp"
#include <string>

#include <glm/glm.hpp>
#ifdef __APPLE__
#   include <GLUT/glut.h>
#else
#   include <GL/glut.h>
#endif

class ResManager;

class Texture : public ResObject {
public:
	GLuint matId;
	
	//Identify whether it is specular, diffuse, etc. so we can put in the right shader.
	std::string type;

    Texture(
        int         _id,
        ResManager* _rm,
        std::string _path,
        GLuint      _matId,
        std::string _type
    )
    : ResObject(_id, _rm, _path),
        matId(_matId),
        type(_type)
    {}
};