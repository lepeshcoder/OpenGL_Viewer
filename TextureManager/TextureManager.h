//
// Created by Lepesh on 11.09.2024.
//

#ifndef OPENGLPROJECT_TEXTUREMANAGER_H
#define OPENGLPROJECT_TEXTUREMANAGER_H

#include <iostream>
#include <unordered_map>
#include "../Entities/Texture/Texture.h"
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include "stb_image.h"


using std::unordered_map, std::string;

class TextureManager {
private:

    unordered_map<string,Texture> TexturesByPath;

    uint32_t TextureFromFile(const string& textureFilePath);

public:

    void LoadTexture(const string& textureFilePath, TextureType type);

    const Texture& GetTextureByPath(const string& textureFilePath);

    bool IsTextureExist(const string& textureFilePath);

};


#endif //OPENGLPROJECT_TEXTUREMANAGER_H
