//
// Created by Lepesh on 06.09.2024.
//

#ifndef OPENGLPROJECT_TEXTURE_H
#define OPENGLPROJECT_TEXTURE_H

#include<iostream>
#include "../../Enums/TextureType.h"


struct Texture {
    // OpenGL texture id
    uint32_t Id;
    TextureType Type;
    //TODO: think about filePath in Texture
    std::string AbsoluteFilePath;
};


#endif //OPENGLPROJECT_TEXTURE_H
